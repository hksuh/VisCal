#include "indiv.h"
#include "visCal_File_IO.h"
#pragma once

class population{
  public:
    population();
    ~population();
    
    void learn();
    void learn(unsigned int);
    
    /* size infos */
    int num;
    unsigned int depthF;
    unsigned int depthR;
    unsigned int** size_frontL;
    unsigned int* size_rearL;
    
    /* laysers */
    struct totalLayer layers;
    
    /* individuals */
    indiv * ref;
    indiv * trial;
    
    /* training data */
	trainData data = txtIn();
	double foot;
};