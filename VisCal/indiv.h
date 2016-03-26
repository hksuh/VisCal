#include "layers.h"
#pragma once

//indiv�� layers.h�� ���ǵ� ��ü���� �̿��Ͽ� �ϳ��� �������� �����ϰ� ������ �ܰ迡�� ����������� ��߳��� �ʵ��� �ʱ�ȭ���ش�.
//���� �������� ���̾� ���Ἲ Ŀ�����յ��� �����ʱ�ȭ, �����Լ��� �����Ѵ�.

class indiv{
public:
	double score;
	void calTotalScore(const totalLayer& _layers,const trainData& _trainData){}

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
	
	indiv(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL);

	void copy();
	void rand();
	void mutate();
	string toStr();
	void show();
};