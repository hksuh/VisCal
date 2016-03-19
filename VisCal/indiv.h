#include "layers.h"

//indiv�� layers.h�� ���ǵ� ��ü���� �̿��Ͽ� �ϳ��� �������� �����ϰ� ������ �ܰ迡�� ����������� ��߳��� �ʵ��� �ʱ�ȭ���ش�.
//���� �������� ���̾� ���Ἲ Ŀ�����յ��� �����ʱ�ȭ, �����Լ��� �����Ѵ�.

class indiv{
public:
	double score;
	void calTotalScore(const totalLayer& _layers,const trainData& _trainData){}

	//depth of frontal and rear part
	unsigned int depthF,depthR;
	//size_frontL[depth]={number of channels, x length, y length}
	vector<unsigned int[3]> size_frontL;
	//size_rearL[depth]
	vector<unsigned int> size_rearL;

	//kernels[depth,channel]
	vector<vector<krnl>> krnls;
	//connectivities[depth]
	vector<conn> conns;
	//thresholds[depth]
	vector<thsd> thsds;

	indiv(unsigned int _depthF, unsigned int _depthR, vector<unsigned int[3]>& _size_frontL, vector<unsigned int>& _size_rearL){
		/*Given size dimension matching. All elements are set zero*/
	};

	void copy();
	void rand();
	void mutate();
	string toStr();
	void show();
};