#pragma once
class Camera {
	public:
		float screenX, screenY;

		Camera();
		~Camera();

		float getCameraX();
		float getCameraY();

		void updateCamera();
};

