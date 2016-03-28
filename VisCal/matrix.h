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