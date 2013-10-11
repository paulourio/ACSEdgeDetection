/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./random.h"

#include <ctime>

namespace acs {

Random::Random() {
	set_seed(time(NULL));
}

void Random::GenerateChoices(int choices, float* output) {
	if (choices <= 0)
		return;
	for (int i = 0; i < choices; ++i)
		output[i] = next();
}

float Random::next() {
	return distribution_(mersenne_engine_);
}

std::mt19937& Random::engine() {
	return mersenne_engine_;
}

void Random::set_seed(uint64_t seed) {
	mersenne_engine_.seed(seed);
	seed_ = seed;
}

uint64_t Random::seed() const {
	return seed_;
}

}  // namespace acs
