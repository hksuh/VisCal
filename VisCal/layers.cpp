#include "layers.h"
#include <math.h>

conn::conn(){};
conn::conn(const unsigned int n0, const unsigned int n1):mat2(n0, n1){};
void conn::getNext(const layer1& _input, layer1& _target){
	mat2::product(_input, _target);
}

krnl::krnl(){};
krnl::krnl(const unsigned int n0, const unsigned int n1) :mat2(n0, n1){};

thsd::thsd(){};
thsd::thsd(const unsigned int n0) :mat1(n0){};
T thsd::sigmoid(T value, T threshold){
	return ((T)1) / (1 + exp(threshold - value));
}
void thsd::getNext(layer1& _target){
	for (int i = 0; i < size[0]; i++){
		_target[i]=sigmoid(_target[i], elem[i]);
	}
}