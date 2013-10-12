/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#include "./guiview.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <string>

namespace {

const std::string kMainWindow("ACS");

}  // namespace

namespace acs {

GUIView::GUIView() :
		View() {
	CreateWidgets();
}

void GUIView::CreateWidgets() {
	cv::namedWindow(kMainWindow, CV_WINDOW_NORMAL);
	//cv::setWindowProperty(kMainWindow, CV_WND_PROP_FULLSCREEN,
	//		CV_WINDOW_FULLSCREEN);
}

void acs::GUIView::WaitKey() const {
	cv::waitKey(0);
}

void GUIView::set_image(cv::Mat image) {
	image_ = image;
	cv::imshow(kMainWindow, image_);
	cv::waitKey(1);
}

}  // namespace acs
