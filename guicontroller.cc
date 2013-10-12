/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./guicontroller.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "./guiview.h"

namespace acs {

GUIController::GUIController() :
		Controller() {
	view_.set_controller(this);
}

void GUIController::Update(cv::Mat image) {
	view_.set_image(image);
}

void GUIController::Wait() const {
	view_.WaitKey();
}

}  // namespace acs
