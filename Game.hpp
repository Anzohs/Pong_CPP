#ifndef GAME_H
#define GAME_H

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Parameters.hpp"

class Game
{
	public:
	Game(Paddle *p1, Paddle *p2, Ball *ball);
	~Game();
	void update();
	void render();
	void loop();
	private:
	Paddle *p1;
	Paddle *p2;
	Ball *ball;
};

#endif
