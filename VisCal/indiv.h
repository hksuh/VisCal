#include "layers.h"
#pragma once

//indiv�� layers.h�� ���ǵ� ��ü���� �̿��Ͽ� �ϳ��� �������� �����ϰ� ������ �ܰ迡�� ����������� ��߳��� �ʵ��� �ʱ�ȭ���ش�.
//���� �������� ���̾� ���Ἲ Ŀ�����յ��� �����ʱ�ȭ, �����Լ��� �����Ѵ�.

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