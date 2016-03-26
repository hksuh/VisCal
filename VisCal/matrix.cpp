//
//  matrix.cpp
//  VisCal
//
//  Created by ³²ÅÂ¿í on 2016. 3. 20..
//

#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename U>
mat<U>::mat(const unsigned int _dim):dim(_dim){
	size = new unsigned int[dim];
}

template <typename U>
mat<U>::~mat() {
	delete[] size;
}
/*
template <typename U>

mat<U>::set(int* index, T value) {
    if(dim == 0) {
        elem[index[0]] = value;
    }
    if(dim == 1) {
        elem[index[0]]
    }
}
 */

template <typename U>
void mat<U>::random(){
	int* i=new int[dim];
	int j = 0;
	for (j = 0; j < dim; j++){ i[j] = 0; }
	while (j >= 0)
	{
		//set(i, ((double)rand() / (double)RAND_MAX));
		j = dim - 1;
		i[j]++;
		while (i[j] == size[j]){
			i[j] = 0;
			j--;
			if (j < 0){ break; }
			i[j]++;
		}
	}
	delete[] i;
}

mat1::mat1():mat<T>(1){
	size[0] = 0;
	elem = NULL;                 // malloc(n*sizeof(T))
}

mat1::mat1(const unsigned int n) :mat<T>(1){
	size[0] = n;
	elem = new T[n];                 // malloc(n*sizeof(T))
}

mat1::~mat1(){
	mat<T>::~mat();
	delete[] elem;
}

void mat1::random(){
	mat<T>::random();
}

void mat1::print() {
	unsigned int i;
	printf("[");
	for (i = 0; i < size[0] - 1; i++) {
		printf("%f, ", elem[i]);
	}
	printf("%f]\n", elem[ size[0]-1]);
}

mat2::mat2():mat<T*>(2){
	unsigned int i;
	size[0] = 0;
	size[1] = 0;

	elem = NULL;                 // malloc(n*sizeof(T))
}

mat2::mat2(const unsigned int n0, const unsigned int n1):mat<T*>(2){
    unsigned int i;
    size[0] = n0;
    size[1] = n1;
    
    elem = new T*[size[0]];                 // malloc(n*sizeof(T))
    for(i=0; i < size[0]; i++) {
        elem[i] = new T[size[1]];
    }
}

mat2::~mat2() {
    cout << "enlgihd" << endl;
    unsigned int i;
    
    for(i=0; i < size[0]; i++) {
        delete[] elem[i];
    }
    delete[] elem;
}

void mat2::random() {
    mat<T*>::random();
}

void mat2::print() {
    int i, j;
    printf("[");
    for(i = 0; i < size[0] - 1; i++) {
        for(j = 0; j <size[1]; j++)
            printf("%f, ", elem[i][j]);
        printf("\n");
    }
    for(j = 0; j <size[1] - 1; j++)
        printf("%f, ", elem[i][j]);
    
    printf("%f]", elem[size[0] - 1][size[1] - 1]);
}

mat3::mat3(const unsigned int n, const unsigned int m, const unsigned int l) {
	unsigned int i, j;

	size = l*m*n;
	size_l = l;
	size_m = m;
	size_n = n;

	elem = new T**[size_n];
	for (i = 0; i < size_n; i++) {
		elem[i] = new T*[size_m];
		for (j = 0; j < size_m; j++){
			elem[i][j] = new T[size_l];
		}
	}
}

mat3::~mat3() {
	unsigned int i, j;

	for (i = 0; i < size_n; i++) {
		for (j = 0; j < size_m; j++){
			delete[] elem[i][j];
		}
		delete elem[i];
	}
	delete[] elem;
}

void mat3::add(const mat3& a, const mat3& b){
	int i, j, k;

	for (i = 0; i < size_l; i++) {
		for (j = 0; j < size_m; j++) {
			for (k = 0; j < size_n; k++)
			{
				elem[i][j][k] = a.elem[i][j][k] + b.elem[i][j][k];
			}
		}
	}

}

void mat3::random() {
	int i, j, k;

	for (i = 0; i < size_l; i++) {
		for (j = 0; j < size_m; j++) {
			for (k = 0; k < size_n; k++)
				elem[i][j][k] = rand() % 100000000 / 100000000.0;
		}
	}
}

void mat3::print() {
	int h, i, j;

	for (h = 0; h < size_l; h++)
	{
		printf("[");
		for (i = 0; i < size_m - 1; i++) {
			for (j = 0; j <size_n; j++)
				printf("%f, ", elem[h][i][j]);
			printf("\n");
		}
		for (j = 0; j <size_n - 1; j++)
			printf("%f, ", elem[h][i][j]);

		printf("%f]\n", elem[h][size_m - 1][size_n - 1]);
	}
}