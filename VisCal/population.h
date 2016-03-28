#include "indiv.h"
#pragma once

class population{
public:
	const int num = 30;
	indiv * ref = new indiv[num];
	indiv * trial = new indiv[num];
	unsigned int depthF=2;
	unsigned int depthR=3;
	unsigned int** size_frontL=new unsigned int*[depthF];
	unsigned int* size_rearL=new unsigned int[depthR+1];


	population(){
		for (int i = 0; i < depthF; i++){
			size_frontL[i] = new unsigned int[3];
		}
		size_frontL[0][0] = 16;
		size_frontL[0][1] = 8;
		size_frontL[0][2] = 8;
		size_frontL[1][0] = 32;
		size_frontL[1][1] = 1;
		size_frontL[1][2] = 1;
		
		size_rearL[0] = size_frontL[depthF - 1][0];
		size_rearL[1] = 6;
		size_rearL[2] = 6;
		size_rearL[3] = 1;
		for (int i = 0; i < num; i++){
			ref[i].init(depthF,depthR,size_frontL,size_rearL);
			ref[i].rand();

			trial[i].init(depthF, depthR, size_frontL, size_rearL);
			trial[i].init(depthF, depthR, size_frontL, size_rearL);
		}
	}
};