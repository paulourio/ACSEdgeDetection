/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./acs.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cmath>

#include <algorithm>
#include <vector>

#include "./ant.h"

namespace acs {

static const double kRho = 0.01;
static const double kB = 0.08;

/* Paper's constants */
static const double kTmin = 0.0001;  // Pheromone threshold minimum value.

ACSEdgeDetection::ACSEdgeDetection(const cv::Mat& image,
		GUIController* controller) :
				image_(image),
				controller_(controller),
				pheromone_(image.rows, image.cols, CV_64FC1) {
	int m = static_cast<int>(std::sqrt(image.rows * image.cols));
	set_ant_count(m);
	set_max_cyles(m * 2.0);
	pheromone_ = kTmin;
}

void ACSEdgeDetection::Compute() {
	InitAnts();
	for (int c = 0; c < max_cyles(); ++c) {
		for (auto& a : ants_)
			a.move();
		UpdatePheromoneTrail();
		UpdateView();
	}
	cv::waitKey(0);
	UpdateFinalView();
}

void ACSEdgeDetection::InitAnts() {
	std::vector<int> pos_x;
	std::vector<int> pos_y;

	ants_.reserve(ant_count_);
	pos_x.reserve(ant_count_);
	pos_y.reserve(ant_count_);

	int values = ant_count_;
	if (values > image_.rows || values > image_.cols)
		values = std::max(image_.rows, image_.cols) * 2;
	for (int i = 0; i < values; ++i) {
		pos_x.push_back(i % image_.rows);
		pos_y.push_back(i % image_.cols);
	}
	std::shuffle(pos_x.begin(), pos_x.end(), random_.engine());
	std::shuffle(pos_y.begin(), pos_y.end(), random_.engine());

	uchar tmp = *std::max_element(image_.begin<uchar>(), image_.end<uchar>());
	double imax = static_cast<double>(tmp);

	for (int i = 0; i < ant_count_; ++i) {
		cv::Point2i start_pos(pos_x[i], pos_y[i]);
		ants_.push_back(Ant(start_pos, image_, pheromone_, &random_, imax));
	}
}

void ACSEdgeDetection::UpdatePheromoneTrail() {
	for (int i = 0; i < image_.rows; ++i) {
		for (int j = 0; j < image_.cols; ++j) {
			cv::Point2i p(j, i);
			double old = (1.0 - kRho) * pheromone_.at<double>(p);
			double delta = 0.0;
			double h = ants_.front().HeuristicInformation(p);
			if (h >= kB)
				for (auto& a : ants_)
					if (a.pos() == p)
						delta += h;
			double np = old + delta;
			pheromone_.at<double>(p) = (np > kTmin) ? np : kTmin;
		}
	}
}

void ACSEdgeDetection::UpdateView() {
	cv::Mat img(image_.rows, image_.cols, CV_8UC3);

	double max = cv::mean(pheromone_)[0];

	/* Translate the pheromone matrix into grayscale */
	for (int i = 0; i < image_.rows; ++i) {
		for (int j = 0; j < image_.cols; ++j) {
			double tmp = pheromone_.at<double>(i, j) / max * 255.0;
			if (tmp > 255)
				tmp = 255;
			int v = 255 - static_cast<int>(tmp);
			img.at<cv::Vec3b>(i, j) = cv::Vec3b(v, v, v);
		}
	}
	/* Paint the ants over the pheromone trails */
	for (auto& a : ants_)
		img.at<cv::Vec3b>(a.pos()) = cv::Vec3b(0, 0, 254);
	controller_->Update(img);
}

void ACSEdgeDetection::UpdateFinalView() {
	cv::Mat img(image_.rows, image_.cols * 2, CV_8UC1);

	for (int i = 0; i < image_.rows; ++i) {
		for (int j = 0; j < image_.cols; ++j) {
			img.at<uchar>(i, j) = image_.at<uchar>(i, j);

			double tmp = pheromone_.at<double>(i, j);
			int oj = image_.cols + j;
			if (tmp > kB)
				img.at<uchar>(i, oj) = 0;
			else
				img.at<uchar>(i, oj) = 255;
		}
	}
	controller_->Update(img);
}

}  // namespace acs
