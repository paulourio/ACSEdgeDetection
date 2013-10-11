/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./acs.h"

namespace acs {

ACSEdgeDetection::ACSEdgeDetection(cv::Mat input, GUIController controller) :
		input_(input), pheromone_(input.rows, input.cols, CV_32FC1), controller_(
				controller) {
	pheromone_ = 0.0001f;
}

ACSEdgeDetection::~ACSEdgeDetection() {
}

void ACSEdgeDetection::Compute() {
}

}  // namespace acs
