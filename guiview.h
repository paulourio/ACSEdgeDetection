/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef GUIVIEW_H_
#define GUIVIEW_H_

#include <opencv2/core/core.hpp>

#include "./global.h"
#include "./view.h"

namespace acs {

/**
 * Implementation of GUI mode using OpenCV and Qt.
 */
class GUIView: public View {
public:
	GUIView();

	virtual ~GUIView() = default;

	void Show();

	void WaitKey() const;

	const cv::Mat& image() const {
		return image_;
	}

	void set_image(cv::Mat image);

private:
	void CreateWidgets();

	cv::Mat image_;

	DISALLOW_COPY_AND_ASSIGN(GUIView);
};

}  // namespace acs

#endif  // GUIVIEW_H_
