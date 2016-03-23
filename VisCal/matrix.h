#include <vector>
#include <cstdlib>
#include <ctime>

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
class mat{
  public:
    virtual ~mat() = 0;
    T* elem;
    unsigned int size;
    
    /* common method */
    void add(const mat&, const mat&);
    void random();
    
    /* abstract method */
    virtual void print() = 0;
};

class mat1 {
  public:
    T* elem;
    unsigned int size;
    
    mat1(const unsigned int);
    ~mat1();
    
    void add(const mat1&, const mat1&);
    void random();
    void print();
};

class mat2 {
  public:
    T** elem;
    unsigned int size_m, size_n;
    unsigned int size;
    
    mat2(const unsigned int, const unsigned int);
    ~mat2();
    
    void add(const mat2&, const mat2&);
    void random();
    void print();
};

class mat3 {
public:
    T*** elem;
    unsigned int size_l, size_m, size_n;
    unsigned int size;
    
    mat3(const unsigned int, const unsigned int, const unsigned int);
    ~mat3();
    
    void add(const mat3&, const mat3&);
    void random();
    void print();
};
/*
	mat1():vector<T>(){}
	mat1(size_t _n,T _init):vector<T>(_n,_init){}

	void add(const mat1& _a, const mat1& _b){}
*/
	/* flatten : 2차원이상의 행렬의 원소들을 일렬로 펼쳐서 1차원행렬(column vector)로 만든다.*/
    /*
	void flatten();
	
	void copy();
	string toStr();
	void show();
    */

//void mat1::show(){/*이런식으로 cpp파일에 함수 내용물 구현*/};
/*
class mat2 : public vector<mat1>{
public:
    mat2();
   */
    /*
	mat2() :vector<mat1>(){}
	mat2(size_t _n, mat1 _init) :vector<mat1>(_n, _init){}
*/
	/*thsd를 이용하여 각각의 원소값에 sigmoid함수를 취하여 0~1사이 실수로 만든다.*/
//	void sigmoid(const mat2& _thsd);

	/*input 열벡터에 현재행렬을 곱한 결과를 target 열벡터에 저장한다.*/
//	void product(const mat1& _input, mat1& _target);
	/*
	void add();
	void copy();
	string toStr();
	void show();
};

class mat3{};

class mat4{};

class mat5{};
*/
