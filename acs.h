/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef ACS_H_
#define ACS_H_

#include <vector>

#include <opencv2/core/core.hpp>

#include "./ant.h"
#include "./guicontroller.h"

namespace acs {

/*
 * Edge detection algorithm.
 */
class ACSEdgeDetection {
public:
	ACSEdgeDetection(cv::Mat input, GUIController controller);
	virtual ~ACSEdgeDetection();

	void Compute();

	cv::Mat pheromone() const {
		return pheromone_;
	}

	int ant_count() const {
		return ant_count_;
	}

	void set_ant_count(int ants) {
		ant_count_ = ants;
	}

	int max_cyles() const {
		return max_cyles_;
	}

	void set_max_cyles(int cycles) {
		max_cyles_ = cycles;
	}

private:
	void InitAnts();

	cv::Mat image_;
	cv::Mat pheromone_;
	GUIController controller_;

	int ant_count_;
	int max_cyles_;

	std::vector<Ant> ants_;
};

}  // namespace acs

#endif  // ACS_H_
