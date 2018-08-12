#pragma once

class Vec2f {
	private:
		float x, y;

	public:
		Vec2f() {}
		Vec2f(float x, float y) : x(x), y(y) {}
		~Vec2f();

		void add(Vec2f vec);
		void subtract(Vec2f vec);
		void multiply(Vec2f vec);
		Vec2f normal();
};

