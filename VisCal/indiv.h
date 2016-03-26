#include "layers.h"
#pragma once

//indiv는 layers.h의 정의된 객체들을 이용하여 하나의 계산단위를 생성하고 생성자 단계에서 행렬차원들이 어긋나지 않도록 초기화해준다.
//또한 계산단위인 레이어 연결성 커널집합들의 랜덤초기화, 변이함수를 제공한다.

class indiv{
public:
	double score;
	void calTotalScore(const totalLayer& _layers,const trainData& _trainData){}

	//depth of frontal and rear part
	unsigned int depthF,depthR;
	//size_frontL[depth]={number of channels, x length, y length}
	unsigned int** size_frontL;
	//size_rearL[depth]
	unsigned int* size_rearL;

	//kernels[depth,channel]
	krnl** krnls;
	//connectivities[depth]
	conn* conns;
	//thresholds[depth]
	thsd* thsds;

	indiv(unsigned int _depthF, unsigned int _depthR, vector<unsigned int[3]>& _size_frontL, vector<unsigned int>& _size_rearL){
		/*Given size dimension matching. All elements are set zero*/
	};

	void copy();
	void rand();
	void mutate();
	string toStr();
	void show();
};