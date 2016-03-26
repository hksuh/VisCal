#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#pragma once
using namespace std;

// vector �ڷ��� ����� �̿��Ͽ� ������ ��İ� �׿� �ʿ��� ���걸��
//// 1. template�� �̿��Ͽ� recursion���� class�� �����Ͽ� ������ ������Ŀ� ���� �Ϲ�ȭ �Ҽ��� ������
//// �� ���������� ������ ������ ����� ������ ���еǰ� ������ ��� ������ �ƴ� 1,2,3������ �ַ� ���ǹǷ� �����Ϲ�ȭ�� ���� �ʴ´�.  
//// 2. �Լ��� �̿��Ҷ� input,target ������� ��������� ���̰� �°� �־����� �����Ѵ�. (���ȿ���� ���� �˻繮�̳� ����ó���� ���� �Ű澲�� �ʴ´�.)

typedef double T;
// �Ŀ� double�� �ƴ� �ٸ� �ڷ����� ����� ��� typedef T�� �ڷ����� �ٲپ��ָ� �ȴ�.
// T �ڷ����� ��뿬��� (�ڵ屸���� �ּ� �߰�)
/* operator + */
/* operator * */
/* toStr (cout ��¹�) */

// �����Լ���
/* add : ������ ��Ŀ��ҵ��� ���Ѵ�.*/
/* copy : �������縦 �����Ѵ�. cppy constructor�� operator=�̶� ��� ����ؾߵ��� ���� �𸣰���*/
/* rand : ���Ұ����� �������� �����Ѵ�.*/
/* toStr : ������������ string���� ��ȯ�Ѵ�. file I/O�� show �Լ��� ���ȴ�.*/
/* show : toStr�� �̿��Ͽ� ��ü�� ������������ ����Ѵ�*/


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
    void random();
    void mutate(T);

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
    
    void random();
    void print();

};

class mat2 : public mat<T*> {
public:
	mat2();
    mat2(const unsigned int, const unsigned int);
    virtual ~mat2();
	void init(const unsigned int, const unsigned int);

    void random();
    void print();
};

class mat3 {
public:
    T*** elem;
    unsigned int size_n, size_m, size_l;
    unsigned int size;
    
    mat3(const unsigned int, const unsigned int, const unsigned int);
    ~mat3();
    
    void add(const mat3&, const mat3&);
    void random();
    void print();
};

/*
class mat4{};

class mat5{};
*/