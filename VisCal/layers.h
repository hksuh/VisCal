#include "matrix.h"

class calLayer1:public mat1{
};

class calLayer2:public mat2{
};

class calLayer{
	vector<vector<calLayer2>> preL;
	vector<calLayer1> postL;
};

class conn:public mat2{
public:
	void getNext(const calLayer1& _input, calLayer1 _target);
};

class krnl{
public:
	void getNext(const calLayer2& _input, calLayer2 _target);
};

class thsd{
public:
	void getNext(calLayer1& _target);
};

struct trainData{
	vector<mat2> input;
	vector<mat1> expectedResult;
};