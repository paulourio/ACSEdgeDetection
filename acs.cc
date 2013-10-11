/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./acs.h"

#include <cmath>

namespace acs {

/* Paper's constants */
static const float kAlpha = 2.5f;
static const float kBeta = 2.0f;
static const float kRho = 0.04;
static const float kB = 0.08;
static const float kTmin = 0.001;  // Pheromone threshold minimum value.

ACSEdgeDetection::ACSEdgeDetection(cv::Mat image, GUIController controller) :
		image_(image), pheromone_(image.rows, image.cols, CV_32FC1), controller_(
				controller) {
	int m = static_cast<int>(std::sqrt(image.rows * image.cols));
	set_ant_count(m);
	set_max_cyles(m);
	pheromone_ = kTmin;
}

ACSEdgeDetection::~ACSEdgeDetection() {
}

void ACSEdgeDetection::Compute() {

}

void ACSEdgeDetection::InitAnts() {
	std::vector<int> pos_x;
	std::vector<int> pos_y;

	ants_.reserve(ant_count_);
	pos_x.reserve(ant_count_);
	pos_y.reserve(ant_count_);

	for (int i = 0; i < ant_count_; ++i) {
		//pos_x.push_back(i % input)
	}
}

}  // namespace acs
