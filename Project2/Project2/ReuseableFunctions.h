vector<vector<int>> MatrixMulti(vector<vector<int>> matrix1, vector<vector<int>> matrix2){
	int siz;
	if (entry2){
		siz = message2.size();
	//	vector<vector<int>> product((message2.size() + 4), vector<int>(3));
	}
	else{
		siz = Msize;
	//	vector<vector<int>> product((Msize + 4), vector<int>(3));
	}
	int sum = 0;
	for (int k = 0; k < (siz / 3); k++){
		for (int i = 0; i < 3; i++){
			for (int j = 0; j < 3; j++){
				sum += matrix1[i][j] * matrix2[k][j];
			}
			product[k][i] = sum;
			sum = 0;
		}

	}

	return product;
}