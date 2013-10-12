/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

#include <cstddef>

#include "./global.h"

namespace acs {

class Random {
public:
	Random();

	virtual ~Random() = default;

	/*
	 * Write into |output| |choices| random values based on |seed|.
	 * Produces random floating-point values in the interval [0, 1)
	 */
	void GenerateChoices(int choices, double* output);

	/*
	 * Generate a floating-point value in the interval [0, 1).
	 */
	double next();

	std::mt19937& engine();

	void set_seed(uint64_t seed);
	uint64_t seed() const;

private:
	std::uniform_real_distribution<double> distribution_;
	std::mt19937 mersenne_engine_;  // Mersenne twister MT19937

	uint64_t seed_;

	DISALLOW_COPY_AND_ASSIGN(Random);
};

}  // namespace acs

#endif  // RANDOM_H_
