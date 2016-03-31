#include "matrix.h"
#pragma once

// matrix �ڷ����� �̿��� ��� layer���� ���κ� ���� 
//// 1. ����帧�� ũ�� �κκ����� ���еȴ�.
//////(1) kernel image convolution (unsupervised task-independent learning). �������� ���̰� ���������� Ȯ���ϴµ��� ������ ����.
//////(2) fully connected neural layer (supervised task-dependent learning). Trainging example�� �̿� mutation�� ���� �˰��� �н�.
//// 2. (1)������ 2���� �̹����� ��ä�� ������ ���̾� �� ���� �����ϹǷ� �� ���̾ 3���� ��Ŀ� �ش��Ѵ�. (1)�� ������ ������ �ϳ��� ä���� 1*1 matrix�� �ǹǷ�
//// �̸� (2)���� �Ѱܹ��������� 1���� matrix�� ����ϸ� ���� connectivity�� 2����, threshold�� 1���� ����� ���°� �ȴ�.

// ��������� ����Ǵ� layer�̴�. ������ ���� �̸����� ���ڰ� ���еǸ� channelLayer�� ����ä�� ���̾� ������ ��Ÿ����. ���� (1)������ channelLayer2, (2)������ layer1�� ���ȴ�. �ʿ��� ���̾ ��� ���� totalLayer�� �Ѵ�.
//class layer1:public mat1{};
//class layer2:public mat2{};
//class channelLayer2 :public vector<layer2>{};
typedef mat1 layer1;
typedef mat2 layer2;
typedef layer2* channelLayer2;

struct totalLayer{
	channelLayer2* frontL;
	layer1* rearL;

	totalLayer();
	~totalLayer();
};

void flatten(const channelLayer2&, layer1&);

/*connectivity : keyfunction : layer1 input�� �޾� ��İ��Ͽ� layer1������� target�� ���� ��.*/
class conn:public mat2{
public:
	conn();
	conn(const unsigned int, const unsigned int);
	using mat2::init;
	using mat2::operator[];
	void getNext(const layer1& _input, layer1& _target);

	using mat2::mutate;
	using mat2::setConst;
};

/*kernel : keyfunction : layer2�� channelLayer2�� input���� �޾� ������� layer2 target�� ���� ��. */
class krnl:public mat3{
public:
	krnl();
	krnl(const unsigned int, const unsigned int, const unsigned int);
	
	int maxPool;
	double thr;

	using mat3::init;
	using mat3::operator[];
	//void getNext(const layer2& _input, layer2& _target);
	void getNext(const channelLayer2& _input, layer2& _target);

	using mat3::mutate;
	using mat3::setConst;
};

/*threshold : keyfunction : layer1 target�� �����͸� sigmoid �����Ͽ� �����ϴ°�. */
class thsd:public mat1{
public:
	thsd();
	thsd(const unsigned int);
	using mat1::init;
	using mat1::operator[];
	double sigmoid(double value, double threshold);
	void getNext(layer1& _target);

	using mat1::mutate;
	using mat1::setConst;
};

/*trainData : train�� input��� �˰��ִ� ����� �����صд�.*/
struct trainData{
public:
	int numOfData;
	channelLayer2* input;
	layer1* expectedResult;

	trainData(unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize);
	~trainData();

	void checkInit();
};