#ifndef	PADDLE_HPP
# define PADDLE_HPP

#include "Parameters.hpp"
#include <iostream>

class Paddle
{
	public:
		Paddle(float x, float y);
		~Paddle();
		void update();
		void draw();
		void setSpeed(float speed);
		float getx();
		float gety();
		float getheight();
		float getwidth();
	private:
		float x;
		float y;
		float speed;
		float height;
		float width;
};


#endif
