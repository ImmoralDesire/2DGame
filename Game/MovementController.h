#pragma once

class MovementController {
	public:
		float movingForward;
		float movingUp;

		MovementController();
		~MovementController();

		void update();
};

