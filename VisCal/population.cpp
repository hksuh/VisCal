#include "population.h"

population::population(){
    /* initialize size information*/
    num = 30;
    depthF = 2;
    depthR = 3;
    
    /* set size information */
    size_frontL = new unsigned int*[depthF];
    size_rearL = new unsigned int[depthR+1];
    
    for (int i = 0; i < depthF; i++) {
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

    /* make layers */
    layers.frontL = new channelLayer2[depthF];
    layers.rearL = new layer1[depthR];
    
    
    /* training datas */
    int readChL2(ifstream& _file, channelLayer2& _target);
    int readL1(ifstream& _file, layer1& _target);
    
    /* make individuals */
    ref = new indiv[num];
    trial = new indiv[num];
    
    for (int i = 0; i < num; i++){
        ref[i].init(depthF,depthR,size_frontL,size_rearL);
        ref[i].rand();   /*********************???????????*****************/
        
        trial[i].init(depthF, depthR, size_frontL, size_rearL);
    }
    
    /* import training data */
    data = txtIn();
}

void population::learn() {
    for(int i = 0; i < num; i++) {
        // ref[i].mutate(&trial[i]);  // mutate 확인 못함
        ref[i].calTotalScore(layers, data);
        trial[i].calTotalScore(layers, data);
        
        if(ref[i].score < trial[i].score) {
            //copy trial[i] to ref[i]
        }
    }
}

void population::learn(unsigned int n) {
    for(int i = 0; i < n; i++) {
        learn();
    }
}