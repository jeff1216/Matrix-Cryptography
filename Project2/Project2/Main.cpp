#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

#include "FunctionNames.h"
#include "ReuseableFunctions.h"
#include "EncryptFunctions.h"
#include "DecryptFunctions.h"

int main(){
	system("color 2");
	while (1){
		cout << "Encode or Decode or Quit (Type the command): ";
		cin >> entry;
		transform(entry.begin(), entry.end(), entry.begin(), toupper);
		if (entry == "QUIT"){
			cout << "Bye!" << endl;
			break;
		}
		else if (entry == "ENCODE"){
			//encode
			entry2 = 1;
			MatrixKey();
			InverseMatrix();
			GetMessage();
			GroupMessage();
			MatrixMulti(key, grouped);
			CreateFile();
			WriteToFile(inverse, product);
			system("pause");
		}
		else if (entry == "DECODE"){
			//decode
			entry2 = 0;
			ReadMessage();
			MatrixMulti(Minverse, Mmessage);
			DisplayMessage();
			system("pause");
		}
		else {
			cout << "Please enter a valid entry." << endl;
			system("pause");
		}
		system("CLS");
	}

	system("pause");
}