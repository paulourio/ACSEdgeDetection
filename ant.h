/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef ANT_H_
#define ANT_H_

#include <opencv2/core/core.hpp>

#include "./global.h"
#include "./memory.h"
#include "./random.h"

namespace acs {

class Ant {
public:
	Ant(cv::Point2i position, cv::Mat& image, cv::Mat& pheromone,
			Random& random, float imax);

	Ant(const Ant& ant);

	virtual ~Ant() = default;

	const cv::Point2i& pos() const {
		return pos_;
	}

	void move();

private:
	float Probability(cv::Point2i p) const;
	float HeuristicInformation(cv::Point2i p) const;

	cv::Point2i pos_;  // Current position
	cv::Mat& image_;
	cv::Mat& pheromone_;
	Random& random_;
	Memory memory_;
	float imax_;

	void operator =(const Ant&);
};

}  // namespace acs

#endif  // ANT_H_
