#include "indiv.h"
#include "visCal_File_IO.h"
#pragma once

class population{
  public:
    population();
    ~population();
    
    void learn(T);
    void learn(unsigned int, T);
    int shell();
    
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
    
    /* auxiliary info */
    T max_score;
};