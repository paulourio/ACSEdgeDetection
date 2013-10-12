/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef CORE_H_
#define CORE_H_

#include <opencv2/core/core.hpp>

#include "./global.h"
#include "./guicontroller.h"

namespace acs {

class Core {
public:
	Core(const char* input, const char* output);

	virtual ~Core() = default;

	void Main();

private:
	void Init();

	const char* input_;
	const char* output_;
	acs::GUIController controller_;
	cv::Mat image_; /* Input image */

	DISALLOW_COPY_AND_ASSIGN(Core);
};

}  // namespace acs

#endif  // CORE_H_
