#include "layers.h"

conn::conn(){};
conn::conn(const unsigned int n0, const unsigned int n1):mat2(n0, n1){};

krnl::krnl(){};
krnl::krnl(const unsigned int n0, const unsigned int n1) :mat2(n0, n1){};

thsd::thsd(){};
thsd::thsd(const unsigned int n0) :mat1(n0){};