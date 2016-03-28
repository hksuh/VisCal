#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#pragma once
using namespace std;

// vector 자료형 상속을 이용하여 다차원 행렬과 그에 필요한 연산구현
//// 1. template을 이용하여 recursion으로 class를 정의하여 임의의 차원행렬에 대해 일반화 할수도 있지만
//// 이 문제에서는 각각의 차원의 행렬이 쓰임이 구분되고 임의의 모든 차원이 아닌 1,2,3차원만 주로 사용되므로 차원일반화를 하지 않는다.  
//// 2. 함수를 이용할때 input,target 변수들과 현재행렬의 길이가 맞게 주어진다 가정한다. (계산효율을 위해 검사문이나 예외처리를 따로 신경쓰지 않는다.)

typedef double T;
// 후에 double이 아닌 다른 자료형을 사용할 경우 typedef T의 자료형을 바꾸어주면 된다.
// T 자료형의 사용연산들 (코드구현시 주석 추가)
/* operator + */
/* operator * */
/* toStr (cout 출력문) */

// 공통함수들
/* add : 각각의 행렬원소들을 더한다.*/
/* copy : 깊은복사를 수행한다. cppy constructor랑 operator=이랑 어떻게 사용해야될지 아직 모르겠음*/
/* rand : 원소값들을 랜덤으로 생성한다.*/
/* toStr : 원소정보들을 string으로 변환한다. file I/O와 show 함수에 사용된다.*/
/* show : toStr을 이용하여 객체의 변수정보들을 출력한다*/


/* Abstract Class for matrix 
 * 
 *
 */

template <typename U> 
class mat{
  public:
	mat(const unsigned int);
	virtual ~mat();
    U * elem;
	const int dim;
    unsigned int* size;
    
    /* common method */
  //  void set(int*, T);
    //    void mutate(T);
    void random();


	U& operator[](int index){
		return elem[index];
	}

};

class mat1 : public mat<T>{
public:
	mat1();
	mat1(const unsigned int);
	virtual ~mat1();
	void init(const unsigned int);
	using mat<T>::operator[];
    
	void mutate(T,const unsigned int);
    void random();
    void copy(const mat1&);
//	mat<T>::setConst;
    void print();

	mat1& operator=(const mat1& ref);
};

class mat2 : public mat<T*> {
public:
	mat2();
    mat2(const unsigned int, const unsigned int);
    virtual ~mat2();
	void init(const unsigned int, const unsigned int);
	using mat<T*>::operator[];

	void product(const mat1& _input, mat1& _target);
//	void mutate(T, const unsigned int, const unsigned int);
	void random();
    void print();
};