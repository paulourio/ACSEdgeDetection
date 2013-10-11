/* Copyright 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./ant.h"

#include <opencv2/core/core.hpp>

#include "./random.h"

namespace acs {

Ant::Ant(cv::Point2i position, cv::Mat& image, cv::Mat& pheromone,
		Random& random) :
		pos_(position), image_(image), pheromone_(pheromone), random_(random), memory_(
				random_, image.cols) {
}

}  // namespace acs
