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


mat1::mat1(const unsigned int n) {
    size = n;
    elem = new T[n];                 // malloc(n*sizeof(T))
}

mat1::~mat1() {
    delete[] elem;
}

void mat1::add(const mat1& a, const mat1& b){
    int i;
    
    for(i = 0; i < size; i++) {
        elem[i] = a.elem[i] + b.elem[i];
    }
}

void mat1::random() {
    int i;
    
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

mat2::mat2(const unsigned int m, const unsigned int n) {
    int i;
    
    size = m*n;
    size_m = m;
    size_n = n;
    
    elem = new T*[size_m];                 // malloc(n*sizeof(T))
    for(i=0; i < n; i++) {
        elem[i] = new T[size_n];
    }
}

mat2::~mat2() {
    int i;
    
    for(i=0; i < size_n; i++) {
        delete[] elem[i];
    }
    delete[] elem;
}

void mat2::add(const mat2& a, const mat2& b){
    int i, j;
    
    for(i = 0; i < size_m; i++) {
        for(j = 0; j < size_n; j++) {
            elem[i][j] = a.elem[i][j] + b.elem[i][j];
        }
    }
}

void mat2::random() {
    int i, j;
    
    for(i = 0; i < size_m; i++) {
        for(j = 0; j < size_n; j++) {
            elem[i][j] = rand()%100000000/100000000.0;
        }
    }
}

void mat2::print() {
    int i, j;
    printf("[");
    for(i = 0; i < size_m - 1; i++) {
        for(j = 0; j <size_n; j++)
            printf("%f, ", elem[i][j]);
        printf("\n");
    }
    for(j = 0; j <size_n - 1; j++)
        printf("%f, ", elem[i][j]);
    
    printf("%f]", elem[size_m - 1][size_n - 1]);
}

mat3::mat3(const unsigned int l, const unsigned int m, const unsigned int n) {
    int i, j;
    
    size = l*m*n;
    size_l = l;
    size_m = m;
    size_n = n;
    
    elem = new T**[size_l];
    for(i = 0; i < size_l; i++) {
        elem[i] = new T*[size_m];
        for(j = 0; j < size_m; j++){
            elem[i][j] = new T[size_n];
        }
    }
}

mat3::~mat3() {
    int i, j;
    
    for(i = 0; i < size_l; i++) {
        for(j = 0; j < size_m; j++){
            delete[] elem[i][j];
        }
        delete elem[i];
    }
    delete[] elem;
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

mat4::mat4(const unsigned int k, const unsigned int l, const unsigned int m, const unsigned int n) {
    int h, i, j;
    
    size = k*l*m*n;
    size_k = k;
    size_l = l;
    size_m = m;
    size_n = n;
    
    elem = new T***[size_k];
    for(h = 0; h < size_k; h++) {
        elem[h] = new T**[size_l];
        for(i = 0; i < size_l; i++){
            elem[h][i] = new T*[size_m];
            for(j=0; j < size_m; j++) {
                elem[h][i][j] = new T[size_n];
            }
        }
    }
}

mat4::~mat4() {
    int h, i, j;
    
    for(h = 0; h < size_k; h++) {
        for(i = 0; i < size_l; i++){
            for(j=0; j < size_m; j++) {
                delete[] elem[h][i][j];
            }
            delete[] elem[h][i];
        }
        delete[] elem[h];
    }
    delete[] elem;
}

void mat4::add(const mat4& a, const mat4& b){
    int g, h, i, j;
    
    for(g = 0; g < size_k; g++) {
        for(h = 0; h < size_l; h++) {
            for(i = 0; i < size_m; i++)
            {
                for(j = 0; j < size_n; j++)
                {
                    elem[g][h][i][j] = a.elem[g][h][i][j] + b.elem[g][h][i][j];
                }
            }
        }
    }
    
}

void mat4::random() {
    int g, h, i, j;
    
    for(g = 0; g < size_k; g++) {
        for(h = 0; h < size_l; h++) {
            for(i = 0; i < size_m; i++)
            {
                for(j = 0; j < size_n; j++)
                {
                    elem[g][h][i][j] = rand()%100000000/100000000.0;
                }
            }
        }
    }
}

void mat4::print() {
    int g, h, i, j;
    
    for(g = 0; g < size_k; g++)
    {
        for(h = 0; h < size_l; h++)
        {
            printf("[");
            for(i = 0; i < size_m - 1; i++) {
                for(j = 0; j <size_n; j++)
                    printf("%f, ", elem[g][h][i][j]);
                    printf("\n");
            }
            for(j = 0; j <size_n - 1; j++)
                printf("%f, ", elem[g][h][i][j]);
        
            printf("%f]\n", elem[g][h][size_m - 1][size_n - 1]);
            printf("-----------------------------------\n");
        }
        printf("==================================\n");
    }
}