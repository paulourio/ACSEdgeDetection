/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./acs.h"

namespace acs {

ACSEdgeDetection::ACSEdgeDetection(cv::Mat input, GUIController controller) :
		input_(input), controller_(controller) {
}

ACSEdgeDetection::~ACSEdgeDetection() {
}

void ACSEdgeDetection::Compute() {
}

}  // namespace acs
