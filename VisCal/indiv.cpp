#include "indiv.h"
indiv::indiv(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL){
	/*Given size dimension matching. All elements are set zero*/
	depthF = _depthF;
	krnls = new krnl*[depthF];
	size_frontL = _size_frontL;
	for (int i = 0; i < depthF; i++){
		krnls[i] = new krnl[size_frontL[i][0]];
		//for loop should be made after we set kernel
	}
	depthR = _depthR; //depthR is # of layers
	size_rearL = _size_rearL;
	conns = new conn[depthR-1]; 
	for (int i = 0; i < depthR-1; i++){
		conns[i].init(size_rearL[i+1],size_rearL[i]);
	}
	thsds = new thsd[depthR - 1];
	for (int i = 0; i < depthR - 1; i++){
		thsds[i].init(size_rearL[i+1]);
	}
};

indiv::~indiv(){
	delete[] conns;
	delete[] thsds;

	for (int i = 0; i < depthF; i++){
		delete[] size_frontL[i];
		delete[] krnls[i];
	}
	delete[] size_frontL;
	delete[] size_rearL;
}

void indiv::calTotalScore(const totalLayer& _layers, const trainData& _trainData){
};