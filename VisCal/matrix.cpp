//
//  matrix.cpp
//  VisCal
//
//  Created by 남태욱 on 2016. 3. 20..
//  Copyright © 2016년 남태욱. All rights reserved.
//

#include "matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename U>
mat<U>::mat(const unsigned int _dim) {
	dim = _dim;
	size=new unsigned int[dim];
}


template <typename U>
mat<U>::random(){
	unsigned int i[dim];
	int j = 0;
	for (j = 0; j < dim; j++){ i[j] = 0; }
	while (j>=0)
	{
		set(i, ((double)rand() / (double)RAND_MAX));
		j = dim - 1;
		i[j]++;
		while (i[j] == size[j]){
			i[j] = 0;
			j--;
			if (j < 0){ break; }
			i[j]++;
		}
	}
}


mat1::mat1(const unsigned int n):mat(1) {
    size[0] = n;
    elem = new T[n];                 // malloc(n*sizeof(T))
}

mat1::~mat1() {
	cout << "소멸자1 호출" << endl;
    delete[] elem;
}

void mat1::add(const mat1& a, const mat1& b){
	unsigned int i;
    
    for(i = 0; i < size; i++) {
        elem[i] = a.elem[i] + b.elem[i];
    }
}

void mat1::random() {
    unsigned int i;
    
    for(i = 0; i < size; i++)
    {
        elem[i] = rand()%100000000/100000000.0;
    }
}

void mat1::print() {
    int i;
    printf("[");
    for(i = 0; i < size - 1; i++) {
        printf("%f, ", elem[i]);
    }
    printf("%f]\n", elem[size - 1]);
}

mat2::mat2(const unsigned int n, const unsigned int m) {
    unsigned int i;
    
    size = m*n;
    size_m = m;
    size_n = n;
    
    elem = new T*[size_n];                 // malloc(n*sizeof(T))
    for(i=0; i < n; i++) {
        elem[i] = new T[size_m];
    }
}

mat2::~mat2() {
	cout << "enlgihd" << endl;
    unsigned int i;
    
    for(i=0; i < size_n; i++) {
        delete[] elem[i];
    }
    delete[] elem;
}

void mat2::add(const mat2& a, const mat2& b){
    int i, j;
    
    for(i = 0; i < size_n; i++) {
        for(j = 0; j < size_n; j++) {
            elem[i][j] = a.elem[i][j] + b.elem[i][j];
        }
    }
}

void mat2::random() {
    unsigned int i, j;
    
    for(i = 0; i < size_n; i++) {
        for(j = 0; j < size_m; j++) {
            elem[i][j] = rand()%100000000/100000000.0;
        }
    }
}

void mat2::print() {
    int i, j;
    printf("[");
    for(i = 0; i < size_n - 1; i++) {
        for(j = 0; j <size_m; j++)
            printf("%f, ", elem[i][j]);
        printf("\n");
    }
    for(j = 0; j <size_m - 1; j++)
        printf("%f, ", elem[i][j]);
    
    printf("%f]", elem[size_m - 1][size_n - 1]);
}

mat3::mat3(const unsigned int n, const unsigned int m, const unsigned int l) {
    unsigned int i, j;
    
    size = l*m*n;
    size_l = l;
    size_m = m;
    size_n = n;
    
    elem = new T**[size_n];
    for(i = 0; i < size_n; i++) {
        elem[i] = new T*[size_m];
        for(j = 0; j < size_m; j++){
            elem[i][j] = new T[size_l];
        }
    }
}

mat3::~mat3() {
	cout << "소멸자3 호출" << endl;
    unsigned int i, j;
    
    for(i = 0; i < size_n; i++) {
        for(j = 0; j < size_m; j++){
            delete[] elem[i][j];
        }
        delete elem[i];
    }
	delete[] elem;
	cout << "소멸자4 호출" << endl;
}

void mat3::add(const mat3& a, const mat3& b){
    int i, j, k;
    
    for(i = 0; i < size_l; i++) {
        for(j = 0; j < size_m; j++) {
            for(k = 0; j < size_n; k++)
            {
                elem[i][j][k] = a.elem[i][j][k] + b.elem[i][j][k];
            }
        }
    }
        
}

void mat3::random() {
    int i, j, k;
    
    for(i = 0; i < size_l; i++) {
        for(j = 0; j < size_m; j++) {
            for(k = 0; k < size_n; k++)
            elem[i][j][k] = rand()%100000000/100000000.0;
        }
    }
}

void mat3::print() {
    int h, i, j;
    
    for(h = 0; h < size_l; h++)
    {
        printf("[");
        for(i = 0; i < size_m - 1; i++) {
            for(j = 0; j <size_n; j++)
                printf("%f, ", elem[h][i][j]);
            printf("\n");
        }
        for(j = 0; j <size_n - 1; j++)
            printf("%f, ", elem[h][i][j]);
    
        printf("%f]\n", elem[h][size_m - 1][size_n - 1]);
    }
}