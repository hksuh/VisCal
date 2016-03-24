#include <iostream>
#include "matrix.h"
#include <thread>

using namespace std;

int drive1(unsigned int threadNum){ return 0; }

int multiThread(){
	thread thread1(&drive1, 1);
	thread thread2(&drive1, 2);
	thread thread3(&drive1, 3);
	thread thread4(&drive1, 4);
	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();

	return 0;
}

int testDrive(){
 
    mat1 a(4);
    mat2 b(4,5);
    mat3 c(4,5,7);
    mat4 d(6, 3, 12, 3);
    a.random();
    cout <<"mat1";
    a.print();
    
    b.random();
    cout <<"mat2";
    b.print();
    
    c.random();
    cout <<"mat3";
    c.print();
    
    d.random();
    cout <<"mat4";
    d.print();
    
    return 0;
}


using namespace std;

int main(){
        srand((unsigned int)time(nullptr));
	int a;
	cout << "HEloow Wolrd;";
	cin >> a;
	cout << "you t" << endl;

	return testDrive();
}
