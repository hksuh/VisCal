#include <iostream>
#include "population.h"
#include "visCal_File_IO.h"
#include <thread>

using namespace std;

population popul;

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

int fileIOTest(){
	txtIn("TrainingList.txt", 99, 32, 32, 1);
}

int testDrive(){

    mat1 a(4);

    mat2 b(4,5);

    mat3 c(4,5,7);
    a.random();
    cout <<"mat1";
    a.print();
    b.random();
    cout <<"mat2";
    b.print();
    c.random();
    cout <<"mat3";
    c.print();
    
    return 0;
}


int main(){
    srand((unsigned int)time(nullptr));
	//return multiThread();
	return testDrive();
}