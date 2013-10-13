/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./ant.h"

#include <opencv2/core/core.hpp>

#include <cassert>

#include "./random.h"

struct Move {
	Move(cv::Point2i point, double probability) :
			point(point), probability(probability) {
	}

	cv::Point2i point;
	double probability;
};

namespace acs {

static const double kAlpha = 2.5;
static const double kBeta = 2.0;

Ant::Ant(cv::Point2i position, const cv::Mat& image, const cv::Mat& pheromone,
		Random* random, double imax) :
				pos_(position),
				image_(image),
				pheromone_(pheromone),
				random_(random),
				memory_(random_, image.cols),
				imax_(imax) {
}

Ant::Ant(const Ant& ant) :
				pos_(ant.pos_),
				image_(ant.image_),
				pheromone_(ant.pheromone_),
				random_(ant.random_),
				memory_(ant.random_, ant.image_.cols),
				imax_(ant.imax_) {
}

void Ant::move() {
	for (int step = 0; step < 70; ++step){
	double total = 0.0;
	std::vector<Move> moves;

	/* Add in |moves| all possible moves */
	moves.reserve(8);
	for (int i = -1; i < +2; ++i) {
		for (int j = -1; j < +2; ++j) {
			if (i == 0 && j == 0)
				continue;
			cv::Point2i new_point(pos_.x + j, pos_.y + i);
			if (!IsValidPoint(new_point))
				continue;
			if (memory_.contains(new_point))
				continue;
			double p = Probability(new_point);
			if (std::isfinite(p) && p > 0.0) {
				total += p;
				moves.push_back(Move(new_point, p));
			}
		}
	}
	if (moves.empty()) {
		int x = random_->next() * image_.cols;
		int y = random_->next() * image_.rows;
		memory_.clear();
		set_pos(cv::Point2i(x, y));
		return;
	}
	/* Normalize all |moves| probabilities */
	for (auto& m : moves)
		m.probability /= total;
	/* Pick one move */
	double choice = random_->next();
	auto move = moves.begin();
	while (move != moves.end()) {
		choice -= move->probability;
		if (choice <= 0.0) {
			set_pos(move->point);
			return;
		}
		++move;
	}
	set_pos(moves.back().point);}
}

void Ant::set_pos(cv::Point2i position) {
	pos_ = position;
	memory_.push(pos_);
}

double Ant::Probability(cv::Point2i p) const {
	if (!IsValidPoint(p))
		return 0.0;
	double phero = std::pow(pheromone_.at<double>(p), kAlpha);
	double heuristic = std::pow(HeuristicInformation(p), kBeta);
	double ret = phero * heuristic;
	if (std::isinf(ret))
		return 0.1e-10;
	return ret;
}

double Ant::HeuristicInformation(cv::Point2i p) const {
	double m = Variation(p, -1, -1, +1, +1);

	m = std::max(m, Variation(p, -1, +1, +1, -1));
	m = std::max(m, Variation(p, 0, +1, 0, -1));
	m = std::max(m, Variation(p, -1, 0, +1, 0));

	// m = std::max(m, Variation(p, -2, -1, +2, +1));
	// m = std::max(m, Variation(p, -2, +1, +2, -1));
	// m = std::max(m, Variation(p, -1, -2, +1, +2));
	// m = std::max(m, Variation(p, +1, -2, -1, +2));

	double ret = m / imax_;
	if (std::isinf(ret))
		return 0.1e-10;
	assert(ret <= 1.0);
	return ret;
}

double Ant::ShadowedPixel(const cv::Point2i& p) const {
	if (!IsValidPoint(p))
		return 0.0;
	uchar pixel = image_.at<uchar>(p);
	return static_cast<double>(pixel);
}

double Ant::Variation(const cv::Point2i& p, int x1, int y1, int x2,
		int y2) const {
	cv::Point2i p1(p.x + x1, p.y + y1);
	cv::Point2i p2(p.x + x2, p.y + y2);
	return std::abs(ShadowedPixel(p1) - ShadowedPixel(p2));
}

bool Ant::IsValidPoint(const cv::Point2i& p) const {
	return (0 <= p.y && p.y < image_.rows && 0 <= p.x && p.x < image_.cols);
}

}  // namespace acs

