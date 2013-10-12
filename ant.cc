/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./ant.h"

#include <opencv2/core/core.hpp>

#include "./random.h"

namespace acs {

static const float kAlpha = 2.5f;
static const float kBeta = 2.0f;
static const float kRho = 0.04f;
static const float kB = 0.08f;

Ant::Ant(cv::Point2i position, cv::Mat& image, cv::Mat& pheromone,
		Random& random, float imax) :
		pos_(position), image_(image), pheromone_(pheromone), random_(random), memory_(
				random_, image.cols), imax_(imax) {
}

Ant::Ant(const Ant& ant) :
		pos_(ant.pos_), image_(ant.image_), pheromone_(ant.pheromone_), random_(
				ant.random_), memory_(ant.random_, ant.image_.cols), imax_(
				ant.imax_) {
}

void Ant::move() {
	for (int i = -1; i < +2; ++i) {
		for (int j = -1; j < +2; ++j) {
			if (i == 0 && j == 0)
				continue;

		}
	}
}

float Ant::Probability(cv::Point2i p) const {
	if (p.y < 0 || p.y >= image_.rows || p.x < 0 || p.x >= image_.cols)
		return 0.0f;
	float phero = std::pow(pheromone_.at<float>(p), kAlpha);

}

float Ant::HeuristicInformation(cv::Point2i p) const {

}

}  // namespace acs

