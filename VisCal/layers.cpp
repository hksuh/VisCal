#include "layers.h"
#include <math.h>

totalLayer::totalLayer() {
    frontL = nullptr;
    rearL = nullptr;
}

totalLayer::~totalLayer() {
    delete[] frontL;
    delete[] rearL;
}

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
krnl::krnl(const unsigned int n0, const unsigned int n1, const unsigned int n2) :mat3(n0, n1, n2){};

void krnl::getNext(const channelLayer2& _input, layer2& _target){
	int chN, i1N, i2N, j1N, j2N;
	int ch, i1, i2, j1, j2;
	chN = size[0];
	i1N = _target.size[0];
	j1N = _target.size[1];
	i2N = size[1];
	j2N = size[2];
	double iter;
	double iter2;

	if (maxPool>1){
		for (i1 = 0; i1 < i1N; i1++){
			for (j1 = 0; j1 < j1N; j1++){
				iter = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							//cout << i1 << ";;;" << j1 << ";;;" << ch << ";;;" << i2 << ";;;" << j2 << endl;
							iter += elem[ch][i2][j2] * _input[ch][2 * i1 + i2][2 * j1 + j2];
						}
					}
				}
				iter2 = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							iter2 += elem[ch][i2][j2] * _input[ch][2 * i1 + i2+1][2 * j1 + j2];
						}
					}
				}
				if (iter2>iter){ iter = iter2; }

				iter2 = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							iter2 += elem[ch][i2][j2] * _input[ch][2 * i1 + i2 ][2 * j1 + j2 +1];
						}
					}
				}
				if (iter2>iter){ iter = iter2; }

				iter2 = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							iter2 += elem[ch][i2][j2] * _input[ch][2 * i1 + i2 + 1][2 * j1 + j2+1];
						}
					}
				}
				if (iter2>iter){ iter = iter2; }

				_target[i1][j1] = .5*(tanh(iter - thr) + 1.);
			}
		}
/*		int i3, j3;
		for (i1 = 0; i1 < i1N; i1++){
			for (j1 = 0; j1 < j1N; j1++){
				i3 = 0; j3 = 0;
				iter = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							iter += elem[ch][i2][j2] * _input[ch][maxPool * i1 + i2 + i3][maxPool * j1 + j2 + j3];
						}
					}
				}
				_target[i1][j1] = iter;
				j3++;
				while (i3 < maxPool){
					iter = 0;
					for (ch = 0; ch < chN; ch++){
						for (i2 = 0; i2 < i2N; i2++){
							for (j2 = 0; j2 < j2N; j2++){
								iter += elem[ch][i2][j2] * _input[ch][maxPool * i1 + i2 + i3][maxPool * j1 + j2 + j3];
							}
						}
					}
					if (iter>_target[i1][j1]){ _target[i1][j1] = iter; };
					j3++;
					if (j3 == maxPool){ j3 = 0; i3++; }
				}
				iter = _target[i1][j1] - thr;
				_target[i1][j1] = .5*(tanh(iter)+1.);
			}
		}
		*/
	}
	else{
		for (i1 = 0; i1 < i1N; i1++){
			for (j1 = 0; j1 < j1N; j1++){
				iter = 0;
				for (ch = 0; ch < chN; ch++){
					for (i2 = 0; i2 < i2N; i2++){
						for (j2 = 0; j2 < j2N; j2++){
							iter += elem[ch][i2][j2] * _input[ch][i1 + i2][j1 + j2];
						}
					}
				}
				_target[i1][j1] = .5*(tanh(iter-thr)+1.);
			}
		}
	}
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