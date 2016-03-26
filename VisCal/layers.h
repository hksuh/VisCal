#include "matrix.h"
#pragma once

// matrix 자료형을 이용한 계산 layer상의 각부분 구현 
//// 1. 계산흐름은 크게 두부분으로 구분된다.
//////(1) kernel image convolution (unsupervised task-independent learning). 자유도를 줄이고 인지영역을 확장하는데에 초점이 있음.
//////(2) fully connected neural layer (supervised task-dependent learning). Trainging example을 이용 mutation을 통해 알고리즘 학습.
//// 2. (1)에서는 2차원 이미지의 다채널 정보가 레이어 한 층을 구성하므로 한 레이어가 3차원 행렬에 해당한다. (1)의 마지막 에서는 하나의 채널이 1*1 matrix가 되므로
//// 이를 (2)에서 넘겨받을때에는 1차원 matrix를 사용하며 따라서 connectivity는 2차원, threshold는 1차원 행렬의 형태가 된다.

// 계산진행이 저장되는 layer이다. 차원에 따라 이름뒤의 숫자가 구분되며 channelLayer는 여러채널 레이어 묶음을 나타낸다. 따라서 (1)영역은 channelLayer2, (2)영역은 layer1이 사용된다. 필요한 레이어를 모두 묶어 totalLayer라 한다.
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


/*connectivity : keyfunction : layer1 input을 받아 행렬곱하여 layer1계산결과를 target에 쓰는 것.*/
class conn:public mat2{
public:
	conn();
	conn(const unsigned int, const unsigned int);
	mat2::init;
	mat2::operator[];
	void getNext(const layer1& _input, layer1 _target);
};

/*kernel : keyfunction : layer2나 channelLayer2를 input으로 받아 계산결과를 layer2 target에 쓰는 것. */
class krnl:public mat2{
public:
	krnl();
	krnl(const unsigned int, const unsigned int);
	mat2::init;
	mat2::operator[];
	void getNext(const layer2& _input, layer2 _target);
	void getNext(const channelLayer2& _input, layer2 _target);
};

/*threshold : keyfunction : layer1 target의 데이터를 sigmoid 연산하여 수정하는것. */
class thsd:public mat1{
public:
	thsd();
	thsd(const unsigned int);
	mat1::init;
	mat1::operator[];
	void getNext(layer1& _target);
};

/*trainData : train할 input들과 알고있는 결과를 저장해둔다.*/
struct trainData{
public:
	int numOfData;
	vector<channelLayer2> input;
	vector<layer1> expectedResult;

	trainData(unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize);
};