#include "indiv.h"

indiv::indiv(){
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
		//for loop should be made after we set kernel
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
	delete[] size_rearL;
}

void indiv::calScore(totalLayer& _layers, const trainData& _trainData, int dataNum){
	//_layers.frontL;
	//_trainData.numOfData;
	double iter;
	for (int j = 0; j < size_frontL[0][0]; j++){ //channel
		krnls[0][j].getNext(_trainData.input[dataNum], _layers.frontL[0][j]);
	}
	for (int i = 0; i < depthF-1; i++){
		for (int j = 0; j < size_frontL[i][0]; j++){ //channel
			krnls[i][j].getNext(_layers.frontL[i], _layers.frontL[i+1][j]);
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
//void rand(){
	
//};
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