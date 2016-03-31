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
	krnl b(num, num, num);

	b.setConst(1);
	q = true;
	for (int j = 0; j < num; j++){
		for (int k = 0; k < num; k++){
			for (int l = 0; l < num; l++){
				if (b[j][k][l] != 1){ q = false; }
			}
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
				for (int l = 0; l < num; l++){
					if (b[j][k][l] != 0){ count++; }
				}
			}
		}
	}
	cout << "example table of mutation" << endl;
	b.print();
	cout << "prob of mut (should be 0.1):" << count / (100000.*num*num*num) << endl;

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

int copy_testDrive(){
	conn a(3, 3);
	a.setConst(0.5);
	conn b(2,2);
	b = a;
	a[2][2] = 1.0;
	a.print();
	b.print();
	thsd c(3);
	c.setConst(0.5);
	thsd d(2);
	d = c;
	c[2] = 1.0;
	c.print();
	d.print();
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

int getNext_testDrive() {
	conn a = conn(4, 3);
	a.setConst(1);
	a[0][1] = -1;
	a[0][2] = 0.5;
	a[1][0] = -1;
	a[1][1] = -1;
	layer1 b = layer1(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;
	layer1 c = layer1(4);
	a.getNext(b, c);
	cout << "a" << endl;
	a.print();
	cout << "b" << endl;
	b.print();
	cout << "c = a X b" << endl;
	c.print();

	thsd d = thsd(4);
	d.setConst(1);
	cout << "thsd d" << endl;
	d.print();
	cout << "get next >>>" << endl;
	d.getNext(c);
	c.print();


	return 0;
}

int prefix_kernel_testDrive() {
	krnl * kn1 = new krnl[4];
	for (int i = 0; i < 4; i++){
		kn1[i] = krnl(1,2,2);
		kn1[i].maxPool = 2;
		kn1[i].thr = .1;
	}
	int v = 0;
	kn1[v][0][0][0] = -.5; kn1[v][0][0][1] = -.5;
	kn1[v][0][1][0] = .5; kn1[v][0][1][1] = .5;

	v = 1;
	kn1[v][0][0][0] = -.5; kn1[v][0][0][1] = .5;
	kn1[v][0][1][0] = -.5; kn1[v][0][1][1] = .5;

	v = 2;
	kn1[v][0][0][0] = .9; kn1[v][0][0][1] = 0;
	kn1[v][0][1][0] = 0; kn1[v][0][1][1] = -0.9;

	v = 3;
	kn1[v][0][0][0] = 0; kn1[v][0][0][1] = .9;
	kn1[v][0][1][0] = -.9; kn1[v][0][1][1] = 0;

	krnl * kn2 = new krnl[2];
	kn2[0] = krnl(4, 4, 4);
	kn2[1] = krnl(4, 4, 4);

	kn2[0].setConst(0);
	kn2[1].setConst(0);
	kn2[0].maxPool = 0;
	kn2[1].maxPool = 0;
	kn2[0].thr = 16.5;
	kn2[1].thr = 12;

	v = 0;
	kn2[0][v][0][2] = 2.;
	kn2[0][v][0][3] = 2.;

	v = 1;
	kn2[0][v][0][0] = 1.; kn2[0][v][0][1] = -1.; kn2[0][v][0][2] = .5; kn2[0][v][0][3] = .5;
	kn2[0][v][1][0] = 1.; kn2[0][v][1][1] = -1.; kn2[0][v][1][2] = 0; kn2[0][v][1][3] = 0;
	kn2[0][v][2][0] = 1.; kn2[0][v][2][1] = .5; kn2[0][v][2][2] = 0; kn2[0][v][2][3] = -1.;
	kn2[0][v][3][0] = 1.; kn2[0][v][3][1] = .5; kn2[0][v][3][2] = -.5; kn2[0][v][3][3] = -1.5;

	v = 2;
	//kn2[0][v][0][0] = 1.; kn2[0][v][0][1] = -1.; kn2[0][v][0][2] = .5; kn2[0][v][0][3] = .5;
	//kn2[0][v][1][0] = 1.; kn2[0][v][1][1] = -1.; kn2[0][v][1][2] = 0; kn2[0][v][1][3] = 0;
	kn2[0][v][2][0] = 0.; kn2[0][v][2][1] = -1.; kn2[0][v][2][2] = 0; kn2[0][v][2][3] = 1.;
	kn2[0][v][3][0] = 0.; kn2[0][v][3][1] = -1.; kn2[0][v][3][2] = -.5; kn2[0][v][3][3] = 1.;
	
	v = 3;
	kn2[0][v][0][0] = 1.; kn2[0][v][0][1] = -1.; kn2[0][v][0][2] = -1.; kn2[0][v][0][3] = -1.;
	kn2[0][v][1][0] = 1.; kn2[0][v][1][1] = -1.; kn2[0][v][1][2] = 0.5; kn2[0][v][1][3] = 0;
	kn2[0][v][2][0] = .5; kn2[0][v][2][1] = -1.; kn2[0][v][2][2] = 1.; kn2[0][v][2][3] = .5;
	kn2[0][v][3][0] = 0; kn2[0][v][3][1] = -1.; kn2[0][v][3][2] = 1.; kn2[0][v][3][3] = 1.;

	v = 1;
	kn2[1][v][0][0] = 1.; kn2[1][v][0][1] = -1.; kn2[1][v][0][2] = -1.; kn2[1][v][0][3] = -1.;
	kn2[1][v][1][0] = 1.; kn2[1][v][1][1] = -1.; kn2[1][v][1][2] = 0.5; kn2[1][v][1][3] = 0;
	kn2[1][v][2][0] = .5; kn2[1][v][2][1] = -1.; kn2[1][v][2][2] = 1.; kn2[1][v][2][3] = .5;
	kn2[1][v][3][0] = 0; kn2[1][v][3][1] = -1.; kn2[1][v][3][2] = 1.; kn2[1][v][3][3] = 1.;


	v = 3;
	kn2[1][v][0][0] = 1.; kn2[1][v][0][1] = -1.; kn2[1][v][0][2] = -1.; kn2[1][v][0][3] = -1.;
	kn2[1][v][1][0] = 1.; kn2[1][v][1][1] = -1.; kn2[1][v][1][2] = 0.5; kn2[1][v][1][3] = 0;
	kn2[1][v][2][0] = .5; kn2[1][v][2][1] = -1.; kn2[1][v][2][2] = 1.; kn2[1][v][2][3] = .5;
	kn2[1][v][3][0] = 0; kn2[1][v][3][1] = -1.; kn2[1][v][3][2] = 1.; kn2[1][v][3][3] = 1.;

	trainData a = txtIn("TrainingList.txt", 2, 32, 32, 1);
	a.input[0][0].print();
	channelLayer2 a2 = new layer2[4];
	channelLayer2 a3 = new layer2[2];
	for (int i = 0; i < 4; i++){
		a2[i] = layer2(15,15);
		kn1[i].getNext(a.input[0],a2[i]);
	}
	a3[0] = layer2(12, 12);
	a3[1] = layer2(12, 12);
	kn2[0].getNext(a2, a3[0]);
	kn2[1].getNext(a2, a3[1]);

	a3[0].print();
	a3[1].print();

	cout <<a3[1][8][7] << endl;
	return 0;
    
}


int indiv_testDrive() {
    //unsigned int size_front[2][2] = { {2, 2}, {1, 1} };
    
    unsigned int **size_front = new unsigned int*[2];
    size_front[0] = new unsigned int[3];
    size_front[1] = new unsigned int[3];
    size_front[0][0] = 2;
    size_front[0][1] = 2;
    size_front[0][2] = 2;
    size_front[1][0] = 2;
    size_front[1][1] = 2;
    size_front[1][2] = 2;
    
    unsigned int *size_rear = new unsigned int[3];
    size_rear[0] = 3;
    size_rear[1] = 2;
    size_rear[2] = 1;
    indiv a = indiv((unsigned int)2, (unsigned int)3, size_front, size_rear);
    cout << a.size_frontL[0][0] << endl;
    a.krnls[0][0].init(1, 2, 3);
    a.krnls[0][0].setConst(1);
    a.krnls[0][0].print();
    //a.conns[0].print();
    
    return 0;
}