/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef ACS_H_
#define ACS_H_

#include <opencv2/core/core.hpp>

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

private:
	cv::Mat input_;
	cv::Mat pheromone_;
	GUIController controller_;
};

}  // namespace acs

#endif  // ACS_H_
