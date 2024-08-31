#ifndef BALL_HPP
#define BALL_HPP

#include "Paddle.hpp"
#include "Parameters.hpp"

class Ball{
	public:
		Ball();
		~Ball();
		void update();
		void draw();
		void setSpeed(float x, float y);
		bool hitPaddle(Paddle* paddle);
		float getSpeed();
		float getSpeedy();
		void reset();
		float getX();
		float getwidth();
	private:
	float x;
	float y;
	float width;
	float height;
	float xSpeed;
	float ySpeed;
};

#endif
