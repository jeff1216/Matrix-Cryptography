void CreateFile(){
	cout << "Please enter the name of the file you want to save the message in: ";
	cin >> name;
	name = name + ".txt";
	cypherFile.open(name);
	cypherFile.close();
	cout << "Done! :)" << endl;
}


void WriteToFile(vector<vector<int>> key, vector<vector<int>> encrypted){

	cypherFile.open(name);
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cypherFile << key[i][j] << " ";
		}
	}
	cypherFile << endl << message2.size() << endl;
	for (int i = 0; i < (message2.size() / 3); i++){
		for (int j = 0; j < 3; j++){
			cypherFile << encrypted[i][j] << " ";
		}
	}
	cypherFile.close();
}


vector <int> GetMessage(){
	cout << "Please enter your message: ";
	string message;
	int a;
	cin.ignore();
	getline(cin, message);
	for (int i = 0; i < message.size(); ++i) {
		a = message[i];
		message2.push_back(a);
	}
	return message2;
}


vector<vector<int>> MatrixKey(){
	srand(time(NULL));
	int n = 1 + rand() % 100;
	key[0][0] = 8 * n * n + 8 * n;
	key[0][1] = 2 * n + 1;
	key[0][2] = 4 * n;
	key[1][0] = 4 * n*n + 4 * n;
	key[1][1] = n + 1;
	key[1][2] = 2 * n + 1;
	key[2][0] = 4 * n*n + 4 * n + 1;
	key[2][1] = n;
	key[2][2] = 2 * n - 1;


	return key;
}


vector<vector<int>> InverseMatrix(){
	MatrixKey();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j<3; j++)
		{
			inverse[j][i] = key[(i + 1) % 3][(j + 1) % 3] *
				key[(i + 2) % 3][(j + 2) % 3] -
				key[(i + 1) % 3][(j + 2) % 3] *
				key[(i + 2) % 3][(j + 1) % 3];

		}
	}
	return inverse;
}


vector<vector<int>> GroupMessage(){
	int extra;
	int k = 0;
	switch (message2.size() % 3){
	case 0:
		extra = 0;
		break;
	case 1:
		extra = 2;
		break;
	case 2:
		extra = 1;
		break;
	}
	for (; extra > 0; --extra) {
		message2.push_back(0);
	}
	for (int i = 0; i < message2.size() / 3; i++){
		for (int j = 0; j < 3; j++, k++){
			grouped[i][j] = message2[k];
		}
	}
	return grouped;
}