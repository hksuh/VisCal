#include "indiv.h"
#include <fstream>
#pragma once

trainData& txtIn();
trainData& txtIn(const char* name, unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize);

//���������� �о���̸� 0 �ƴϸ� error number ��ȯ
int readChL2(ifstream& _file, channelLayer2& _target);
int readL1(ifstream& _file, layer1& _target);

