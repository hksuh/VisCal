#include "visCal_File_IO.h"

trainData& txtIn(){
    //const char *name = "TrainingList.txt";
    const char *name = "/Users/namsan/Project/VisCal/VisCal/TrainingList.txt";
	return txtIn(name, 20, 32, 32, 1);
}
trainData& txtIn(const char* name, unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny,unsigned int outputSize){
	trainData * re = new trainData(numOfInput,input_lenx,input_leny,outputSize);
	trainData &testImg = *re;
	testImg.checkInit();
	cout << "Read file <" << name << ">" << endl;

	testImg.numOfData = numOfInput;

	ifstream inFile(&name[0u]);
	int i = 0;

	bool inputState = true;

	int var;
	try{
		while (i < numOfInput){

			var = readChL2(inFile, testImg.input[i]);
			if (var != 0){ throw var; };

			inFile >> var; if (var != -4){ throw -4; };

			var = readL1(inFile, testImg.expectedResult[i]);
			if (var != 0){ throw var; };

			inFile >> var; if (var != -5){ throw var; };

			i++;
		}
		//inFile >> var; if (var != -6){ throw var; };
	}
	catch (int e){
		cout << "An exception occurred. Exception No. " << e << '\n';
	}
	inFile.close();

	return *re;
}

int readChL2(ifstream& _file, channelLayer2& _target){
	int i = 0, j = 0, k = 0;
	double var;
	_file >> var;
    if (var != -2){ return -2; };
	_file >> var;
	while (var >= 0){
		while (var >= 0){
			while (var >= 0){
				_target[i][j][k] = var;
				k++;
				_file >> var;
			}
			if (((int)(var-.5)) != -10){ return -10; };
			j++; k = 0;
			_file >> var;
		}
		if (((int)(var - .5)) != -20){ return -20; };
		i++; j = 0;
		_file >> var;
	}
	if (((int)(var - .5)) != -30){ return -30; };
	_file >> var; if (((int)(var - .5)) != -3){ return -3; };
	return 0;
}

int readL1(ifstream& _file, layer1& _target){
	int i=0;
	double var;
    _file >> var; if (((int)(var - .5)) != -2){ return -2; };
	_file >> var;
	while (var >= 0){
		_target[i] = var;
		i++;
		_file >> var;
	}
	if (((int)(var - .5)) != -10){ return -10; };
	_file >> var; if (((int)(var - .5)) != -3){ return -3; };
	return 0;
};
