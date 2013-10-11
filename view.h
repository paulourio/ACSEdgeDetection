/* Copyright © 2013 Paulo Roberto Urio <paulourio@gmail.com> */
#ifndef VIEW_H_
#define VIEW_H_

namespace acs {

class Controller;

/**
 * The main controller should receive an instance of TrainerView as the
 * front-end.
 */
class View {
public:
	virtual ~View() = default;

	/**
	 * @return The controller responsible for this view.
	 */
	Controller* controller() const {
		return controller_;
	}

	/**
	 * Set the controller responsible for this view.  Usually it's called
	 * on controller initialization.
	 * @param controller
	 */
	void set_controller(Controller* controller) {
		controller_ = controller;
	}

private:
	Controller* controller_;
};

}  // namespace acs

#endif  // VIEW_H_
