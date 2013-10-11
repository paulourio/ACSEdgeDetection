/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef ANT_H_
#define ANT_H_

#include <opencv2/core/core.hpp>

#include "./memory.h"
#include "./random.h"

namespace acs {

class Ant {
public:
	Ant(cv::Point2i position, cv::Mat& image, cv::Mat& pheromone,
			Random& random);

	virtual ~Ant() = default;

	cv::Point2i pos_;  // Current position
private:
	cv::Mat& image_;
	cv::Mat& pheromone_;
	Random& random_;
	Memory memory_;
};

}  // namespace acs

#endif  // ANT_H_
