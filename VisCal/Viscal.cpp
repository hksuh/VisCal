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
	mat1 v=mat1(2,0.);
	cout << v[1] << endl;

	int a;
	cin >> a;
	return a;
}

int main(){
	int a;
	cout << "HEloow Wolrd;";
	cin >> a;
	cout << "you t" << endl;
	//return multiThread();
	return testDrive();
}