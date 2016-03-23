#include <vector>
#include <cstdlib>
#include <ctime>

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
	/* flatten : 2�����̻��� ����� ���ҵ��� �Ϸķ� ���ļ� 1�������(column vector)�� �����.*/
    /*
	void flatten();
	
	void copy();
	string toStr();
	void show();
    */

//void mat1::show(){/*�̷������� cpp���Ͽ� �Լ� ���빰 ����*/};
/*
class mat2 : public vector<mat1>{
public:
    mat2();
   */
    /*
	mat2() :vector<mat1>(){}
	mat2(size_t _n, mat1 _init) :vector<mat1>(_n, _init){}
*/
	/*thsd�� �̿��Ͽ� ������ ���Ұ��� sigmoid�Լ��� ���Ͽ� 0~1���� �Ǽ��� �����.*/
//	void sigmoid(const mat2& _thsd);

	/*input �����Ϳ� ��������� ���� ����� target �����Ϳ� �����Ѵ�.*/
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
