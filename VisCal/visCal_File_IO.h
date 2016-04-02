#include "indiv.h"
#include <fstream>
#pragma once

trainData& txtIn();
trainData& txtIn(const char* name, unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize);

//성공적으로 읽어들이면 0 아니면 error number 반환
int readChL2(ifstream& _file, channelLayer2& _target);
int readL1(ifstream& _file, layer1& _target);

