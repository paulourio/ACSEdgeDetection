/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef ACS_H_
#define ACS_H_

#include <opencv2/core/core.hpp>

#include <vector>

#include "./ant.h"
#include "./global.h"
#include "./guicontroller.h"
#include "./random.h"

namespace acs {

/*
 * Edge detection algorithm.
 */
class ACSEdgeDetection {
public:
	ACSEdgeDetection(const cv::Mat& input, GUIController* controller);

	virtual ~ACSEdgeDetection() = default;

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

	void UpdatePheromoneTrail();

	void UpdateView();
	void UpdateFinalView();

	const cv::Mat& image_;
	GUIController* controller_;

	cv::Mat pheromone_;
	Random random_;
	std::vector<Ant> ants_;

	int ant_count_;
	int max_cyles_;

	DISALLOW_COPY_AND_ASSIGN(ACSEdgeDetection);
};

}  // namespace acs

#endif  // ACS_H_
