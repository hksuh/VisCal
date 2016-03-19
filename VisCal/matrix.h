#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class mat1: public vector<double>{
public:
	mat1():vector<double>(){}
	mat1(size_t _n,double _init) :vector<double>(_n,_init){}

	void add(const mat1& _a, const mat1& _b){}

	void flatten(const mat2& _a){}

	void flatten(const mat3& _a){}

	void show(){}
};

class mat2 : public vector<mat1>{
public:
	mat2() :vector<mat1>(){}
	mat2(size_t _n, mat1 _init) :vector<mat1>(_n, _init){}

	void sigmoid(const mat2& _thsd){}

	void show(){}
};

class mat3{};

class mat4{};

class mat5{};
