#include "layers.h"
#include <math.h>

void flatten(const channelLayer2& _input, layer1& _output) {
    int i;
    for(i = 0; i < _input->size[0]; i++) {
        _output.elem[i] = _input[i][0][0];
    }
}

conn::conn(){};
conn::conn(const unsigned int n0, const unsigned int n1):mat2(n0, n1){};
void conn::getNext(const layer1& _input, layer1& _target){
	mat2::product(_input, _target);
}

krnl::krnl(){};
krnl::krnl(const unsigned int n0, const unsigned int n1) :mat2(n0, n1){};

void krnl::getNext(const channelLayer2& _input, layer2& _target){
	
}

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


trainData::trainData(unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize){
	numOfData = numOfInput;
	input = new channelLayer2[numOfInput];
	expectedResult=new layer1[numOfInput];
	for (int i = 0; i < numOfData; i++){
		input[i]=new layer2[1];
		input[i][0].init(input_lenx, input_leny);
		expectedResult[i].init(outputSize);
	}
}

trainData::~trainData(){
	for (int i = 0; i < numOfData; i++){
		delete[] input[i];
	}
	delete[] input;
	delete[] expectedResult;
}
/*vector type constructor
trainData::trainData(unsigned int numOfInput, unsigned int input_lenx, unsigned int input_leny, unsigned int outputSize){
	numOfData = numOfInput;
	input.reserve(numOfInput);
	//expectedResult.reserve(numOfInput);
	for (int i = 0; i < numOfData; i++){
		input.push_back(new layer2[1]);
		input[i][0].init(input_lenx, input_leny);
	//	expectedResult.push_back(layer1());
	//	expectedResult[i] = new layer1(outputSize);
	}
	
}
*/

void trainData::checkInit(){
	cout << "numOfData: " << numOfData << endl;
	cout << sizeof(input)<< endl;
	cout << sizeof(expectedResult) << endl;
	cout << input[0][0].size[0] << endl;
	cout << input[0][0].size[1] << endl;
	cout << input[1][0].size[0] << endl;
	cout << input[1][0].size[1] << endl;
	cout << expectedResult[0].size[0] << endl;
	cout << expectedResult[1].size[0] << endl;
}