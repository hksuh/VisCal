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
mat<U>::mat(const unsigned int _dim) :dim(_dim){
	size = new unsigned int[dim];
	for (int i = 0; i < dim; i++){
		size[i] = 0;
	}
	elem = nullptr;
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

/*
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
*/
/*
template <typename U>
void mat<U>::setConst(T a){
int* i = new int[dim];
int j = 0;
for (j = 0; j < dim; j++){ i[j] = 0; }
while (j >= 0)
{
//set(i, a);
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
*/

mat1::mat1() :mat<T>(1){
	size[0] = 0;               // malloc(n*sizeof(T))
}

mat1::mat1(const unsigned int n) : mat<T>(1){
	init(n);
}

void mat1::init(const unsigned int n){
	size[0] = n;
	elem = new T[n];
}

mat1::~mat1(){
	delete[] elem;
}

void mat1::print() {
	unsigned int i;
	printf("[");
	for (i = 0; i < size[0] - 1; i++) {
		printf("%f, \n", elem[i]);
	}
	printf("%f]\n", elem[size[0] - 1]);
}

void mat1::random() {
	for (int i = 0; i < size[0]; i++)
	{
		//elem[i] = rand()%100000000/100000000.0;
		elem[i] = 2.*(double)rand() / (double)RAND_MAX - 1.;
	}
}

void mat1::setConst(T constant){
	for (int i = 0; i < size[0]; i++){
		elem[i] = constant;
	}
}

mat1& mat1::operator=(const mat1& ref){
	if (elem != nullptr){
		delete[] elem;
	}
	init(ref.size[0]);
	copy(ref);

	return *this;
}

void mat1::copy(const mat1& ref){
	for (int i = 0; i < ref.size[0]; i++){
		elem[i] = ref.elem[i];
	}
}

void mat1::mutate(T _foot){
	for (int i = 0; i < size[0]; i++){
		if (!(rand() % 10)){
			elem[i] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
		}
	}
}

void mat1::mutate(T _foot, const unsigned int& _i){
	elem[_i] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
}

mat2::mat2() :mat<T*>(2){
	size[0] = 0;
	size[1] = 0;

	elem = nullptr;                 // malloc(n*sizeof(T))
}

mat2::mat2(const unsigned int n0, const unsigned int n1) :mat<T*>(2){
	init(n0, n1);
}

void mat2::init(const unsigned int n0, const unsigned int n1){

	unsigned int i;
	size[0] = n0;
	size[1] = n1;

	elem = new T*[size[0]];                 // malloc(n*sizeof(T))
	for (i = 0; i < size[0]; i++) {
		elem[i] = new T[size[1]];
	}
}

mat2::~mat2() {
	unsigned int i;
	for (i = 0; i < size[0]; i++) {
		delete[] elem[i];
	}
	delete[] elem;
}

void mat2::product(const mat1& _input, mat1& _target){
	for (int i = 0; i < size[0]; i++){
		_target[i] = 0;
		for (unsigned int j = 0; j < size[1]; j++){
			_target.elem[i] += elem[i][j] * (_input.elem[j]);
		}
	}
}

void mat2::print() {
	int i, j;
	printf("[");
	for (i = 0; i < size[0] - 1; i++) {
		for (j = 0; j <size[1]; j++)
			printf("%f, ", elem[i][j]);
		printf("\n");
	}
	for (j = 0; j <size[1] - 1; j++)
		printf("%f, ", elem[i][j]);

	printf("%f]\n", elem[size[0] - 1][size[1] - 1]);
}

void mat2::random() {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			//elem[i][j] = rand()%100000000/100000000.0;
			elem[i][j] = 2.*(double)rand() / (double)RAND_MAX - 1.;
		}
	}
}

void mat2::setConst(T constant){
	for (int i = 0; i < size[0]; i++){
		for (int j = 0; j < size[1]; j++){
			elem[i][j] = constant;
		}
	}
}

void mat2::mutate(T _foot){
	for (int i = 0; i < size[0]; i++){
		for (int j = 0; j < size[1]; j++){
			if (!(rand() % 10)){
				elem[i][j] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
			}
		}
	}
}

void mat2::mutate(T _foot, const unsigned int& _i, const unsigned int& _j){
	elem[_i][_j] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
}

mat2& mat2::operator=(const mat2& ref){
	if (elem != nullptr){
		for (int i = 0; i < size[0]; i++) {
			delete[] elem[i];
		}
		delete[] elem;
	}
	init(ref.size[0], ref.size[1]);
	copy(ref);

	return *this;
}

void mat2::copy(const mat2& ref){
	for (int i = 0; i < ref.size[0]; i++){
		for (int j = 0; j < ref.size[1]; j++){
			elem[i][j] = ref.elem[i][j];
		}
	}
}


mat3::mat3() :mat<T**>(3){
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;

	elem = nullptr;                 // malloc(n*sizeof(T))
}

mat3::mat3(const unsigned int n0, const unsigned int n1, const unsigned int n2) :mat<T**>(3){
	init(n0, n1, n2);
}

void mat3::init(const unsigned int n0, const unsigned int n1, const unsigned int n2){

	unsigned int i;
	size[0] = n0;
	size[1] = n1;
	size[2] = n2;

	elem = new T**[size[0]];                 // malloc(n*sizeof(T))
	for (i = 0; i < size[0]; i++) {
		elem[i] = new T*[size[1]];
		for (int j = 0; j < size[1]; j++){
			elem[i][j] = new T[size[2]];
		}
	}
}

mat3::~mat3() {
	unsigned int i, j;
	for (i = 0; i < size[0]; i++) {
		for (j = 0; j < size[1]; j++){
			delete[] elem[i][j];
		}
		delete[] elem[i];
	}
	delete[] elem;
}

void mat3::print() {
	int h, i, j;
	for (h = 0; h < size[0]; h++)
	{
		printf("[");
		for (i = 0; i < size[1] - 1; i++) {
			for (j = 0; j <size[2]; j++)
				printf("%f, ", elem[h][i][j]);
			printf("\n");
		}
		for (j = 0; j <size[2] - 1; j++)
			printf("%f, ", elem[h][i][j]);
		printf("%f]\n", elem[h][size[1] - 1][size[2] - 1]);
	}
}

void mat3::random() {
	for (int i = 0; i < size[0]; i++) {
		for (int j = 0; j < size[1]; j++) {
			for (int k = 0; k < size[2]; k++){
				//elem[i][j] = rand()%100000000/100000000.0;
				elem[i][j][k] = 2.*(double)rand() / (double)RAND_MAX - 1.;
			}
		}
	}
}

void mat3::setConst(T constant){
	for (int i = 0; i < size[0]; i++){
		for (int j = 0; j < size[1]; j++){
			for (int k = 0; k < size[2]; k++){
				elem[i][j][k] = constant;
			}
		}
	}
}

void mat3::mutate(T _foot){
	for (int i = 0; i < size[0]; i++){
		for (int j = 0; j < size[1]; j++){
			for (int k = 0; k < size[2]; k++){
				if (!(rand() % 10)){
					elem[i][j][k] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
				}
			}
		}
	}
}

void mat3::mutate(T _foot, const unsigned int& _i, const unsigned int& _j, const unsigned int& _k){
	elem[_i][_j][_k] += _foot*((double)rand() / (double)RAND_MAX - 0.5);
}

mat3& mat3::operator=(const mat3& ref){
	if (elem != nullptr){
		for (int i = 0; i < size[0]; i++) {
			for (int j = 0; j < size[1]; j++){
				delete[] elem[i][j];
			}
			delete[] elem[i];
		}
		delete[] elem;
	}
	init(ref.size[0], ref.size[1], ref.size[2]);
	copy(ref);

	return *this;
}

void mat3::copy(const mat3& ref){
	for (int i = 0; i < ref.size[0]; i++){
		for (int j = 0; j < ref.size[1]; j++){
			for (int k = 0; k < ref.size[2]; k++){
				elem[i][j][k] = ref.elem[i][j][k];
			}
		}
	}
}


/*
mat3::mat2():mat<T**>(3){
size[0] = 0;
size[1] = 0;

elem = NULL;                 // malloc(n*sizeof(T))
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
*/