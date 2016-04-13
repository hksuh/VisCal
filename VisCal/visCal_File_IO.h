#include "indiv.h"
#include <fstream>
#pragma once

trainData& txtIn();
trainData& txtIn(const char* name, unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize);

//성공적으로 읽어들이면 0 아니면 error number 반환
int readChL2(ifstream& _file, channelLayer2& _target);
int readL1(ifstream& _file, layer1& _target);

int readKrnl(ifstream& _file, krnl& _target);
int readKrnls(ifstream& _file, krnl** _target);
int readConn(ifstream& _file, conn& _target);
int readConns(ifstream& _file, conn* _target);
int readthsd(ifstream& _file, thsd& _target);
int readthsds(ifstream& _file, thsd* _target);

int readIndiv(ifstream& _file, indiv& _target);
int readIndivs(ifstream& _file, indiv* _target);