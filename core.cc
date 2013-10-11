/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./core.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>

#include <cstdlib>
#include <cstdio>

#include "./acs.h"

namespace acs {

Core::Core(const char* input, const char* output) :
		input_(input), output_(output) {
	Init();
}

void Core::Main() {
	controller_.Update(image_);

	ACSEdgeDetection algorithm(image_, controller_);
	algorithm.Compute();

	controller_.Wait();

	// cv::imwrite(output_, algorithm.pheromone());
}

void Core::Init() {
	image_ = cv::imread(input_, CV_LOAD_IMAGE_GRAYSCALE);
	if (!image_.data) {
		fprintf(stderr, "Input file %s doesn't exists\n", input_);
		exit(EXIT_FAILURE);
	}
}

}  // namespace acs
