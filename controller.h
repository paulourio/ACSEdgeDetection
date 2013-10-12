/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "./global.h"

namespace acs {

/**
 * Abstract class for a controller.
 */
class Controller {
public:
	Controller() = default;

	virtual ~Controller() = default;

private:
	DISALLOW_COPY_AND_ASSIGN(Controller);
};

}  // namespace acs

#endif  // CONTROLLER_H_
