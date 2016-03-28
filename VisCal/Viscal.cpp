#include <iostream>
#include "population.h"
#include "visCal_File_IO.h"
#include "matrix.h"
#include "layers.h"
#include <thread>
#include "testDrive.h"

using namespace std;

//population popul;

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


int main(){
    srand((unsigned int)time(nullptr));
    
    mat1 a = mat1(3);
    a.print();
    a.random();
    a.print();
    a.random();
    a.print();
    mat2 b = mat2(3, 4);
    b.print();
    b.random();
    b.print();
	return 0;
}
