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
	Ant(cv::Point2i position, const cv::Mat& image, const cv::Mat& pheromone,
			Random* random, double imax);

	Ant(const Ant& ant);

	virtual ~Ant() = default;

	const cv::Point2i& pos() const {
		return pos_;
	}

	const Memory& memory() const {
		return memory_;
	}

	void move();

	double HeuristicInformation(cv::Point2i p) const;

private:
	double Probability(cv::Point2i p) const;

	/* Return either a true pixel of a shadow, if p is not inside the bounds */
	double ShadowedPixel(const cv::Point2i& p) const;
	double Variation(const cv::Point2i& p, int x1, int y1, int x2,
			int y2) const;
	bool IsValidPoint(const cv::Point2i& p) const;

	void set_pos(cv::Point2i position);

	void operator =(const Ant&) = delete;

	cv::Point2i pos_;  // Current position
	const cv::Mat& image_;
	const cv::Mat& pheromone_;
	Random* random_;
	Memory memory_;
	double imax_;
};

}  // namespace acs

#endif  // ANT_H_
