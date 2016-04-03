#include "layers.h"
#pragma once

//indiv는 layers.h의 정의된 객체들을 이용하여 하나의 계산단위를 생성하고 생성자 단계에서 행렬차원들이 어긋나지 않도록 초기화해준다.
//또한 계산단위인 레이어 연결성 커널집합들의 랜덤초기화, 변이함수를 제공한다.

class indiv{
public:
	double score;
	void calTotalScore(totalLayer& _layers, const trainData& _trainData);
	void calScore(totalLayer& _layers, const trainData& _trainData, int dataNum);

	/*

	DIMENSION SETTINGS
	size_frontL=depthF
	size_rearL=depthR+1

	*/
	//depth of frontal and rear part
	unsigned int depthF,depthR;
	//size_frontL[depth][*]={number of channels, x length, y length}
	unsigned int** size_frontL;
	//size_rearL[depth]
	unsigned int* size_rearL;

	//kernels[depth,channel]
	krnl** krnls;
	//connectivities[depth]
	conn* conns;
	//thresholds[depth]
	thsd* thsds;

	indiv();
	indiv(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL);
	void init(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL);
	~indiv();

	void preset();
	void presetRead();

	void setConst(T);
	indiv& operator=(const indiv& _ref);
	void copy(const indiv& _ref);
	void rand();
	void mutate(T _foot);
	void mutate(T _foot,int typenumber);
	string toStr();
	void show();
};