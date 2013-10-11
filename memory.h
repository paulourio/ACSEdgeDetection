/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef MEMORY_H_
#define MEMORY_H_

#include <deque>

#include <opencv2/core/core.hpp>

#include "./random.h"

namespace acs {

class Memory {
public:
	Memory(Random& random, int image_size);

	virtual ~Memory() = default;

	/* Append |point| to the memory and discards old points if necessary. */
	void push(cv::Point2i point);

	/* Check if a point is already in the memory. */
	bool contains(cv::Point2i point);

private:
	/* Memory length parameter used on initialization. */
	float GetA(int image_size) const;

	void Init(int image_size);

	Random& random_;
	std::deque<cv::Point2i> memory_;
	int memory_capacity_;
};

}  // namespace acs

#endif  // MEMORY_H_
