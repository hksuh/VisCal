#include "testDrive.h"

int trainDataTest(){
	trainData a=trainData(300, 32, 32, 1);
	a.checkInit();
	return 0;
}

int fileIOTest(){
	trainData a=txtIn("TrainingList.txt", 600, 32, 32, 1);
	cout << "edfdfefedfefdfefd" << endl;
	a.checkInit();
	cout << "edfdfefedfefdfefd" << endl;
	a.input[2][0].print();
	a.expectedResult[5].print();
	return 0;
}

int matrix_testDrive(){
    cout << "testing mat1 & mat2 class" << endl;
    mat1 a = mat1(3);
    cout << "printing mat1, matrix should be filled with 0" << endl;
    a.print();
    cout << "randomizing mat1" << endl;
    a.random();
    a.print();
    cout << "printing mat2, matrix should be filled with 0" << endl;
    mat2 b = mat2(3, 11);
    b.print();
    cout << "randomizing mat1" << endl;
    b.random();
    b.print();
	return 0;
}

int mutation_testDrive(){
	
	const int num = 5;
	bool q = true;
	double count = 0;

	cout << "==========test conn setConst , mutate==========" << endl;
	
	conn a(num,num);

	a.setConst(1);
	for (int j = 0; j < num; j++){
		for (int k = 0; k < num; k++){
			if (a[j][k] != 1){ q = false; }
		}
	}
	if (q){ cout << "setConst operates well" << endl; }
	else{ cout << "setConst is fucked up" << endl; }

	for (int i = 0; i < 100000; i++){
		a.setConst(0);
		a.mutate(1.0);
		for (int j = 0; j < num; j++){
			for (int k = 0; k < num; k++){
				if (a[j][k] != 0){ count++; }
			}
		}
	}
	cout << "example table of mutation" << endl;
	a.print();
	cout << "prob of mut (should be 0.1):"<<count / (100000.*num*num) << endl;

	cout << "==========test krnl setConst , mutate==========" << endl;

	krnl b(num, num);

	b.setConst(1);
	q = true;
	for (int j = 0; j < num; j++){
		for (int k = 0; k < num; k++){
			if (b[j][k] != 1){ q = false; }
		}
	}
	if (q){ cout << "setConst operates well" << endl; }
	else{ cout << "setConst is fucked up" << endl; }

	count = 0;
	for (int i = 0; i < 100000; i++){
		b.setConst(0);
		b.mutate(1.0);
		for (int j = 0; j < num; j++){
			for (int k = 0; k < num; k++){
				if (b[j][k] != 0){ count++; }
			}
		}
	}
	cout << "example table of mutation" << endl;
	b.print();
	cout << "prob of mut (should be 0.1):" << count / (100000.*num*num) << endl;

	cout << "==========test conn setConst , mutate==========" << endl;

	thsd c(num);

	c.setConst(1);
	
	q = true;
	for (int j = 0; j < num; j++){
		if (c[j]!=1){ q = false; }
	}
	if (q){ cout << "setConst operates well" << endl; }
	else{ cout << "setConst is fucked up" << endl; }

	count = 0;
	for (int i = 0; i < 100000; i++){
		c.setConst(0);
		c.mutate(1.0);
		for (int j = 0; j < num; j++){
			if (c[j] != 0){ count++; }
		}
	}
	cout << "example table of mutation" << endl;
	c.print();
	cout << "prob of mut (should be 0.1):" << count / (100000.*num) << endl;
	return 0;
}

class te{
public:
	int** b;
	te(int** _b){
		b = _b;
	}
};

int ptr_testDrive(){
	int** a = new int*[3];
	a[0] = new int[3];
	a[1] = new int[3];
	a[2] = new int[3];
	a[0][0] = 1;
	te * obj = new te(a);
	cout << (*obj).b[0][0] << endl;
	(*obj).b[0][0] = 3;
	cout << a[0][0] << endl;
	return 0;
}

int syntax_testDrive(){
	int** a = new int*[3];
	a[0] = new int[3];
	a[1] = new int[3];
	a[2] = new int[3];
	a[0][0] = 1;
	te * obj = new te(a);
	cout << (*obj).b[0][0] << endl;
	(*obj).b[0][0] = 3;
	cout << a[0][0] << endl;
	return 0;
}

int arraydel(){
	conn** a = new conn*[3];
	cout << "1" << endl;
	a[0] = new conn[2];
	cout << "2" << endl;
	a[1] = new conn[2];
	cout << "3" << endl;
	a[2] = new conn[2];
	cout << "4" << endl;
	delete[] a[0];
	cout << "5" << endl;
	delete[] a[1];
	cout << "6" << endl;
	delete[] a[2];
	cout << "7" << endl;
	delete[] a;

	return 0;
}