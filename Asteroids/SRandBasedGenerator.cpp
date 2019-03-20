#include "SRandBasedGenerator.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

SRandBasedGenerator::SRandBasedGenerator() { srand(std::time(0)); }

SRandBasedGenerator::~SRandBasedGenerator() {}

int SRandBasedGenerator::nextInt() { return rand(); }

int SRandBasedGenerator::nextInt(int low, int high) {
  return low + (nextInt() % abs(high - low));
}
