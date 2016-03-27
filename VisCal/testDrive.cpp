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
	mat1 a= mat1(4);

	mat2 b(4, 5);

	//    mat3 c(4,5,7);
	(a[0]) = 0.5;
	    a.print();
//	    b.setConst(0.5);
//		b.print();
	cout << "mat2";
	cout << "mat2[0][0]" << b.elem[0][0] << endl;
	cout << "mat2[0][0]" << b[0][0] << endl;

	b.print();
	//    c.random();
	//    cout <<"mat3";
	//    c.print();
	double alter;
	cin >> alter;
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