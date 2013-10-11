/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./acs.h"

#include <cmath>

#include <algorithm>
#include <iostream>
#include <vector>

#include <opencv2/imgproc/imgproc.hpp>

#include "./ant.h"

namespace acs {

/* Paper's constants */
static const float kAlpha = 2.5f;
static const float kBeta = 2.0f;
static const float kRho = 0.04;
static const float kB = 0.08;
static const float kTmin = 0.001;  // Pheromone threshold minimum value.

ACSEdgeDetection::ACSEdgeDetection(cv::Mat& image, GUIController& controller) :
		image_(image), controller_(controller), pheromone_(image.rows,
				image.cols, CV_32FC1) {
	int m = static_cast<int>(std::sqrt(image.rows * image.cols));
	set_ant_count(m);
	set_max_cyles(m);
	pheromone_ = kTmin;
}

ACSEdgeDetection::~ACSEdgeDetection() {
}

void ACSEdgeDetection::Compute() {
	InitAnts();
}

void ACSEdgeDetection::InitAnts() {
	std::vector<int> pos_x;
	std::vector<int> pos_y;

	ants_.reserve(ant_count_);
	pos_x.reserve(ant_count_);
	pos_y.reserve(ant_count_);

	for (int i = 0; i < ant_count_; ++i) {
		pos_x.push_back(i % image_.rows);
		pos_y.push_back(i % image_.cols);
	}
	std::shuffle(pos_x.begin(), pos_x.end(), random_.engine());
	std::shuffle(pos_y.begin(), pos_y.end(), random_.engine());

	for (int i = 0; i < ant_count_; ++i) {
		cv::Point2i start_pos(pos_x[i], pos_y[i]);
		ants_.push_back(Ant(start_pos, image_, pheromone_, random_));
	}
}

void ACSEdgeDetection::UpdateView() {
	cv::Mat img(image_.rows, image_.cols, CV_8UC3);

	/* Translate the pheromone matrix into grayscale */
	for (int i = 0; i < image_.rows; ++i) {
		for (int j = 0; j < image_.cols; ++j) {
			float tmp = pheromone_.at<float>(i, j) * 255.0f;
			if (tmp > 254.0f)
				tmp = 254.0f;
			int v = 254 -  static_cast<int>(tmp);
			img.at<cv::Vec3b>(i, j) = cv::Vec3b(v, v, v);
		}
	}
	/* Paint the ants over the pheromone trails */
	for (auto a: ants_)
		img.at<cv::Vec3b>(a.pos()) = cv::Vec3b(0, 0, 254);
	controller_.Update(img);
}

}  // namespace acs
