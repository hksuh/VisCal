#include "indiv.h"

indiv::indiv(){
	size_frontL = nullptr;
	size_rearL = nullptr;

	krnls = nullptr;
	conns = nullptr;
	thsds = nullptr;
}

indiv::indiv(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL){
	init(_depthF,_depthR,_size_frontL,_size_rearL);
};

void indiv::init(unsigned int _depthF, unsigned int _depthR, unsigned int** _size_frontL, unsigned int* _size_rearL){
	/*Given size dimension matching. All elements are set zero*/
	/*

	DIMENSION SETTINGS
	size_frontL=depthF
	size_rearL=depthR+1

	*/

	depthF = _depthF;
	krnls = new krnl*[depthF];
	size_frontL = _size_frontL;
    
	for (int i = 0; i < depthF; i++){
		krnls[i] = new krnl[size_frontL[i][0]];
     //   for(int j = 0; j < size_frontL[i][0]; i++) {
            // krnls[i][j].init();
	}
    
	depthR = _depthR;
	size_rearL = _size_rearL;
	conns = new conn[depthR]; 
	for (int i = 0; i < depthR; i++){
		conns[i].init(size_rearL[i+1],size_rearL[i]);
	}
	thsds = new thsd[depthR];
	for (int i = 0; i < depthR; i++){
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
	delete[] krnls;
	delete[] size_rearL;
}

void indiv::preset(){
	/* initialize size information*/
	depthF = 3;
	depthR = 3;

	/* set size information */
	size_frontL = new unsigned int*[depthF];
	size_rearL = new unsigned int[depthR + 1];

	for (int i = 0; i < depthF; i++) {
		size_frontL[i] = new unsigned int[3];
	}
	size_frontL[0][0] = 8;
	size_frontL[0][1] = 15;
	size_frontL[0][2] = 15;
	size_frontL[1][0] = 2;
	size_frontL[1][1] = 12;
	size_frontL[1][2] = 12;
	size_frontL[2][0] = 2;
	size_frontL[2][1] = 1;
	size_frontL[2][2] = 1;


	size_rearL[0] = size_frontL[depthF - 1][0];
	size_rearL[1] = 3;
	size_rearL[2] = 3;
	size_rearL[3] = 1;

	/* set conns, thsds */
	init(3, 3, size_frontL, size_rearL);

	/* init krnls */
	int i = 0;
	for (int j = 0; j < size_frontL[i][0]; j++){
		krnls[i][j].init(1, 2, 2);
		krnls[i][j].maxPool = 2;
		krnls[i][j].thr = 0.3;
	}

	i = 1;
	for (int j = 0; j < size_frontL[i][0]; j++){
		krnls[i][j].init(size_frontL[i-1][0], 4, 4);
	}
	krnls[i][0].thr = 5.1;
	krnls[i][0].thr = 5.7;

	i = 2;
	for (int j = 0; j < size_frontL[i][0]; j++){
		krnls[i][j].init(size_frontL[i - 1][0], 4, 4);
	}

	setConst(0);

	//readKrnl();
}

void indiv::presetRead(){
	//readkrnl()

	krnls[0][0].thr = 0.3;
	krnls[0][0].maxPool = 2;
	krnls[0][0][0][0][0] = 4.;
	krnls[0][0][0][0][1] = 4.;
	krnls[0][0][0][1][0] = -4.;
	krnls[0][0][0][1][1] = -4.;

	krnls[0][1].thr = 0.3;
	krnls[0][1].maxPool = 2;
	krnls[0][1][0][0][0] = -4.;
	krnls[0][1][0][0][1] = -4.;
	krnls[0][1][0][1][0] = 4.;
	krnls[0][1][0][1][1] = 4.;

	krnls[0][2].thr = 0.3;
	krnls[0][2].maxPool = 2;
	krnls[0][2][0][0][0] = -4.;
	krnls[0][2][0][0][1] = 4.;
	krnls[0][2][0][1][0] = -4.;
	krnls[0][2][0][1][1] = 4.;

	krnls[0][3].thr = 0.3;
	krnls[0][3].maxPool = 2;
	krnls[0][3][0][0][0] = 4.;
	krnls[0][3][0][0][1] = -4.;
	krnls[0][3][0][1][0] = 4.;
	krnls[0][3][0][1][1] = -4.;

	krnls[0][4].thr = 0.3;
	krnls[0][4].maxPool = 2;
	krnls[0][4][0][0][0] = 7.2;
	krnls[0][4][0][0][1] = 0.;
	krnls[0][4][0][1][0] = 0.;
	krnls[0][4][0][1][1] = -7.2;

	krnls[0][5].thr = 0.3;
	krnls[0][5].maxPool = 2;
	krnls[0][5][0][0][0] = -7.2;
	krnls[0][5][0][0][1] = 0.;
	krnls[0][5][0][1][0] = 0.;
	krnls[0][5][0][1][1] = 7.2;

	krnls[0][6].thr = 0.3;
	krnls[0][6].maxPool = 2;
	krnls[0][6][0][0][0] = 0.;
	krnls[0][6][0][0][1] = -7.2;
	krnls[0][6][0][1][0] = 7.2;
	krnls[0][6][0][1][1] = 0.;

	krnls[0][7].thr = 0.3;
	krnls[0][7].maxPool = 2;
	krnls[0][7][0][0][0] = 0.;
	krnls[0][7][0][0][1] = 7.2;
	krnls[0][7][0][1][0] = -7.2;
	krnls[0][7][0][1][1] = 0.;

	krnls[1][0].thr = 5.1;
	krnls[1][0].maxPool = 0;
	krnls[1][0][0][0][0] = 0.;
	krnls[1][0][0][0][1] = 0.;
	krnls[1][0][0][0][2] = 0.;
	krnls[1][0][0][0][3] = 0.;
	krnls[1][0][0][1][0] = 0.;
	krnls[1][0][0][1][1] = 0.;
	krnls[1][0][0][1][2] = 0.;
	krnls[1][0][0][1][3] = 0.;
	krnls[1][0][0][2][0] = -3.2;
	krnls[1][0][0][2][1] = 0.;
	krnls[1][0][0][2][2] = 0.;
	krnls[1][0][0][2][3] = 1.6;
	krnls[1][0][0][3][0] = -3.2;
	krnls[1][0][0][3][1] = -3.2;
	krnls[1][0][0][3][2] = 1.6;
	krnls[1][0][0][3][3] = 1.6;
	krnls[1][0][1][0][0] = -1.6;
	krnls[1][0][1][0][1] = 0.;
	krnls[1][0][1][0][2] = 1.6;
	krnls[1][0][1][0][3] = 1.6;
	krnls[1][0][1][1][0] = -1.6;
	krnls[1][0][1][1][1] = 0.;
	krnls[1][0][1][1][2] = 0.8;
	krnls[1][0][1][1][3] = 0.8;
	krnls[1][0][1][2][0] = -1.6;
	krnls[1][0][1][2][1] = -1.6;
	krnls[1][0][1][2][2] = 0.;
	krnls[1][0][1][2][3] = -1.6;
	krnls[1][0][1][3][0] = -1.6;
	krnls[1][0][1][3][1] = -1.6;
	krnls[1][0][1][3][2] = -1.6;
	krnls[1][0][1][3][3] = -1.6;
	krnls[1][0][2][0][0] = 2.4;
	krnls[1][0][2][0][1] = 0.;
	krnls[1][0][2][0][2] = 0.;
	krnls[1][0][2][0][3] = -3.2;
	krnls[1][0][2][1][0] = 2.4;
	krnls[1][0][2][1][1] = 0.;
	krnls[1][0][2][1][2] = -3.2;
	krnls[1][0][2][1][3] = -3.2;
	krnls[1][0][2][2][0] = 2.4;
	krnls[1][0][2][2][1] = 0.;
	krnls[1][0][2][2][2] = -3.2;
	krnls[1][0][2][2][3] = -0.8;
	krnls[1][0][2][3][0] = 2.4;
	krnls[1][0][2][3][1] = 0.;
	krnls[1][0][2][3][2] = 0.;
	krnls[1][0][2][3][3] = -0.8;
	krnls[1][0][3][0][0] = -1.6;
	krnls[1][0][3][0][1] = 0.;
	krnls[1][0][3][0][2] = 1.6;
	krnls[1][0][3][0][3] = 0.;
	krnls[1][0][3][1][0] = -1.6;
	krnls[1][0][3][1][1] = 0.;
	krnls[1][0][3][1][2] = 0.;
	krnls[1][0][3][1][3] = 0.;
	krnls[1][0][3][2][0] = -1.6;
	krnls[1][0][3][2][1] = 0.;
	krnls[1][0][3][2][2] = 0.;
	krnls[1][0][3][2][3] = 1.6;
	krnls[1][0][3][3][0] = -1.6;
	krnls[1][0][3][3][1] = 0.;
	krnls[1][0][3][3][2] = 1.6;
	krnls[1][0][3][3][3] = 1.6;
	krnls[1][0][4][0][0] = -3.2;
	krnls[1][0][4][0][1] = 0.;
	krnls[1][0][4][0][2] = 1.6;
	krnls[1][0][4][0][3] = 0.;
	krnls[1][0][4][1][0] = -3.2;
	krnls[1][0][4][1][1] = 0.;
	krnls[1][0][4][1][2] = 0.;
	krnls[1][0][4][1][3] = 0.;
	krnls[1][0][4][2][0] = -3.2;
	krnls[1][0][4][2][1] = 0.;
	krnls[1][0][4][2][2] = 0.;
	krnls[1][0][4][2][3] = 1.6;
	krnls[1][0][4][3][0] = -3.2;
	krnls[1][0][4][3][1] = 0.;
	krnls[1][0][4][3][2] = 0.8;
	krnls[1][0][4][3][3] = 1.6;
	krnls[1][0][5][0][0] = 2.4;
	krnls[1][0][5][0][1] = 0.;
	krnls[1][0][5][0][2] = 1.6;
	krnls[1][0][5][0][3] = 0.8;
	krnls[1][0][5][1][0] = 2.4;
	krnls[1][0][5][1][1] = 0.;
	krnls[1][0][5][1][2] = 0.;
	krnls[1][0][5][1][3] = 0.8;
	krnls[1][0][5][2][0] = 2.4;
	krnls[1][0][5][2][1] = 0.;
	krnls[1][0][5][2][2] = -1.6;
	krnls[1][0][5][2][3] = -1.6;
	krnls[1][0][5][3][0] = 2.4;
	krnls[1][0][5][3][1] = 0.;
	krnls[1][0][5][3][2] = -1.6;
	krnls[1][0][5][3][3] = -1.6;
	krnls[1][0][6][0][0] = -3.2;
	krnls[1][0][6][0][1] = 0.;
	krnls[1][0][6][0][2] = 1.6;
	krnls[1][0][6][0][3] = 1.6;
	krnls[1][0][6][1][0] = -3.2;
	krnls[1][0][6][1][1] = 0.;
	krnls[1][0][6][1][2] = 0.8;
	krnls[1][0][6][1][3] = 0.8;
	krnls[1][0][6][2][0] = -3.2;
	krnls[1][0][6][2][1] = 0.;
	krnls[1][0][6][2][2] = 0.;
	krnls[1][0][6][2][3] = 0.8;
	krnls[1][0][6][3][0] = -3.2;
	krnls[1][0][6][3][1] = 0.;
	krnls[1][0][6][3][2] = 0.8;
	krnls[1][0][6][3][3] = 1.6;
	krnls[1][0][7][0][0] = 2.4;
	krnls[1][0][7][0][1] = 0.;
	krnls[1][0][7][0][2] = -1.6;
	krnls[1][0][7][0][3] = -1.6;
	krnls[1][0][7][1][0] = 2.4;
	krnls[1][0][7][1][1] = 0.;
	krnls[1][0][7][1][2] = -0.8;
	krnls[1][0][7][1][3] = -0.8;
	krnls[1][0][7][2][0] = 2.4;
	krnls[1][0][7][2][1] = 0.;
	krnls[1][0][7][2][2] = -1.6;
	krnls[1][0][7][2][3] = 0.;
	krnls[1][0][7][3][0] = 2.4;
	krnls[1][0][7][3][1] = 0.;
	krnls[1][0][7][3][2] = 0.;
	krnls[1][0][7][3][3] = 0.;

	krnls[1][0].thr = 5.7;
	krnls[1][0].maxPool = 0;
	krnls[1][1][0][0][0] = -3.2;
	krnls[1][1][0][0][1] = -3.2;
	krnls[1][1][0][0][2] = -3.2;
	krnls[1][1][0][0][3] = -3.2;
	krnls[1][1][0][1][0] = 0.;
	krnls[1][1][0][1][1] = 0.;
	krnls[1][1][0][1][2] = 0.;
	krnls[1][1][0][1][3] = 0.;
	krnls[1][1][0][2][0] = 0.;
	krnls[1][1][0][2][1] = 0.;
	krnls[1][1][0][2][2] = 0.;
	krnls[1][1][0][2][3] = 0.;
	krnls[1][1][0][3][0] = 0.;
	krnls[1][1][0][3][1] = 0.;
	krnls[1][1][0][3][2] = 0.;
	krnls[1][1][0][3][3] = 0.;
	krnls[1][1][1][0][0] = -3.2;
	krnls[1][1][1][0][1] = -3.2;
	krnls[1][1][1][0][2] = 0.;
	krnls[1][1][1][0][3] = 0.;
	krnls[1][1][1][1][0] = 0.;
	krnls[1][1][1][1][1] = 0.;
	krnls[1][1][1][1][2] = 0.;
	krnls[1][1][1][1][3] = 0.;
	krnls[1][1][1][2][0] = -6.4;
	krnls[1][1][1][2][1] = -6.4;
	krnls[1][1][1][2][2] = 0.;
	krnls[1][1][1][2][3] = 0.;
	krnls[1][1][1][3][0] = -6.4;
	krnls[1][1][1][3][1] = -6.4;
	krnls[1][1][1][3][2] = -3.2;
	krnls[1][1][1][3][3] = 0.;
	krnls[1][1][2][0][0] = 0.;
	krnls[1][1][2][0][1] = 0.;
	krnls[1][1][2][0][2] = 0.;
	krnls[1][1][2][0][3] = 0.;
	krnls[1][1][2][1][0] = 0.;
	krnls[1][1][2][1][1] = 0.;
	krnls[1][1][2][1][2] = 0.;
	krnls[1][1][2][1][3] = 0.;
	krnls[1][1][2][2][0] = 0.;
	krnls[1][1][2][2][1] = 1.6;
	krnls[1][1][2][2][2] = 0.;
	krnls[1][1][2][2][3] = 0.;
	krnls[1][1][2][3][0] = 0.;
	krnls[1][1][2][3][1] = 1.6;
	krnls[1][1][2][3][2] = 1.6;
	krnls[1][1][2][3][3] = 0.;
	krnls[1][1][3][0][0] = 0.;
	krnls[1][1][3][0][1] = 0.96;
	krnls[1][1][3][0][2] = 0.96;
	krnls[1][1][3][0][3] = 0.;
	krnls[1][1][3][1][0] = 0.;
	krnls[1][1][3][1][1] = 0.;
	krnls[1][1][3][1][2] = 0.96;
	krnls[1][1][3][1][3] = 0.96;
	krnls[1][1][3][2][0] = 1.6;
	krnls[1][1][3][2][1] = 0.;
	krnls[1][1][3][2][2] = 0.;
	krnls[1][1][3][2][3] = 0.96;
	krnls[1][1][3][3][0] = 1.6;
	krnls[1][1][3][3][1] = 0.;
	krnls[1][1][3][3][2] = 0.;
	krnls[1][1][3][3][3] = 0.;
	krnls[1][1][4][0][0] = 0.;
	krnls[1][1][4][0][1] = 0.;
	krnls[1][1][4][0][2] = 0.;
	krnls[1][1][4][0][3] = 0.;
	krnls[1][1][4][1][0] = 0.;
	krnls[1][1][4][1][1] = 0.;
	krnls[1][1][4][1][2] = 0.;
	krnls[1][1][4][1][3] = 0.;
	krnls[1][1][4][2][0] = 8.;
	krnls[1][1][4][2][1] = 0.;
	krnls[1][1][4][2][2] = 0.;
	krnls[1][1][4][2][3] = 0.;
	krnls[1][1][4][3][0] = 8.;
	krnls[1][1][4][3][1] = 0.;
	krnls[1][1][4][3][2] = 0.;
	krnls[1][1][4][3][3] = 0.;
	krnls[1][1][5][0][0] = -19.2;
	krnls[1][1][5][0][1] = -1.6;
	krnls[1][1][5][0][2] = -1.6;
	krnls[1][1][5][0][3] = -1.6;
	krnls[1][1][5][1][0] = -1.6;
	krnls[1][1][5][1][1] = -1.6;
	krnls[1][1][5][1][2] = -1.6;
	krnls[1][1][5][1][3] = -1.6;
	krnls[1][1][5][2][0] = -1.6;
	krnls[1][1][5][2][1] = -1.6;
	krnls[1][1][5][2][2] = -1.6;
	krnls[1][1][5][2][3] = -1.6;
	krnls[1][1][5][3][0] = -1.6;
	krnls[1][1][5][3][1] = -1.6;
	krnls[1][1][5][3][2] = -1.6;
	krnls[1][1][5][3][3] = -1.6;
	krnls[1][1][6][0][0] = -12.8;
	krnls[1][1][6][0][1] = 3.2;
	krnls[1][1][6][0][2] = 3.2;
	krnls[1][1][6][0][3] = 0.;
	krnls[1][1][6][1][0] = 0.;
	krnls[1][1][6][1][1] = 0.;
	krnls[1][1][6][1][2] = 3.2;
	krnls[1][1][6][1][3] = 3.2;
	krnls[1][1][6][2][0] = 0.;
	krnls[1][1][6][2][1] = 0.;
	krnls[1][1][6][2][2] = 0.;
	krnls[1][1][6][2][3] = 3.2;
	krnls[1][1][6][3][0] = 0.;
	krnls[1][1][6][3][1] = -9.6;
	krnls[1][1][6][3][2] = 0.;
	krnls[1][1][6][3][3] = 0.;
	krnls[1][1][7][0][0] = 0.;
	krnls[1][1][7][0][1] = -1.6;
	krnls[1][1][7][0][2] = -1.6;
	krnls[1][1][7][0][3] = -1.6;
	krnls[1][1][7][1][0] = 0.;
	krnls[1][1][7][1][1] = 0.;
	krnls[1][1][7][1][2] = -1.6;
	krnls[1][1][7][1][3] = -1.6;
	krnls[1][1][7][2][0] = 0.;
	krnls[1][1][7][2][1] = 6.4;
	krnls[1][1][7][2][2] = 0.;
	krnls[1][1][7][2][3] = -1.6;
	krnls[1][1][7][3][0] = 0.;
	krnls[1][1][7][3][1] = 6.4;
	krnls[1][1][7][3][2] = 6.4;
	krnls[1][1][7][3][3] = 0.;


}

void indiv::calScore(totalLayer& _layers, const trainData& _trainData, int dataNum){
	//_layers.frontL;
	//_trainData.numOfData;
	double iter;
	for (int j = 0; j < size_frontL[0][0]; j++){ //channel
		krnls[0][j].getNext(_trainData.input[dataNum], _layers.frontL[0][j]);
	}
	for (int i = 0; i < depthF-1; i++){
		for (int j = 0; j < size_frontL[i+1][0]; j++){ //channel
			krnls[i+1][j].getNext(_layers.frontL[i], _layers.frontL[i+1][j]);
		}
	}
	flatten(_layers.frontL[depthF-1],_layers.rearL[0]); //insert flatten function to make it mat1
	//void getNext(const layer1& _input, layer1& _target);
	for (int i = 0; i < depthR; i++){
		conns[i].getNext(_layers.rearL[i], _layers.rearL[i + 1]);
		thsds[i].getNext(_layers.rearL[i + 1]);
	}
	for (int i = 0; i < size_rearL[depthR]; i++){
		iter=(_layers.rearL[depthR][i] - _trainData.expectedResult[dataNum][i]);
		score += iter*iter;
	}
};

void indiv::calTotalScore(totalLayer& _layers, const trainData& _trainData){
	score = 0;
	for (int i = 0; i < _trainData.numOfData; i++){
		calScore(_layers, _trainData, i);
	}
};

void indiv::rand(){
	for (int i = 0; i < depthF; i++){
		for (int j = 0; j < size_frontL[i][0]; j++){
			krnls[i][j].random();
		}
	}
	for (int i = 0; i < depthR; i++){
		conns[i].random();
		thsds[i].random();
	}
};

void indiv::copy(const indiv& _ref){
	for (int i = 0; i < depthF; i++){
		for (int j = 0; j < size_frontL[i][0]; j++){
			krnls[i][j].copy(_ref.krnls[i][j]);
		}
	}
	for (int i = 0; i < depthR; i++){
		conns[i].copy(_ref.conns[i]);
		thsds[i].copy(_ref.thsds[i]);
	}
	score = _ref.score;
}

indiv& indiv::operator=(const indiv& _ref){
	this->~indiv();
	init(_ref.depthF, _ref.depthR, _ref.size_frontL, _ref.size_rearL);
	copy(_ref);
	return *this;
}

void indiv::setConst(T constant){
	for (int i = 0; i < depthF; i++){
		for (int j = 0; j < size_frontL[i][0]; j++){
			krnls[i][j].setConst(constant);
		}
	}
	for (int i = 0; i < depthR; i++){
		conns[i].setConst(constant);
		thsds[i].setConst(constant);
	}
}

void indiv::mutate(T _foot){
	mutate(_foot, 1);
	mutate(_foot, 2);
}

void indiv::mutate(T _foot, int typenumber){
	//1:mutate kernel(front Layer)
	//2:mutate rear Layer
	//3:mutate conn
	//4:mutate thsd
	switch (typenumber)
	{
	case 1:
		for (int i = 0; i < depthF; i++){
			for (int j = 0; j < size_frontL[i][0]; j++){
				krnls[i][j].mutate(_foot);
			}
		}
		break;
	case 2:
		for (int i = 0; i < depthR; i++){
			conns[i].mutate(_foot);
			thsds[i].mutate(_foot);
		}
		break;
	case 3:
		for (int i = 0; i < depthR; i++){
			conns[i].mutate(_foot);
		}
		break;
	case 4:
		for (int i = 0; i < depthR; i++){
			thsds[i].mutate(_foot);
		}
		break;
	default:
		cout<<"indiv::mutate function typeNumber error";
	}
}

string toStr();

void show();