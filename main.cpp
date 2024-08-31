#include "Game.hpp"

int	main(){
	srand(time(0));
	Paddle *p1 = new Paddle(10,25);
	Paddle *p2 = new Paddle(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 125);
	Ball *ball = new Ball();
	Game *game = new Game(p1, p2, ball);
	game->loop();
	return 0;
}

/*
 * Compile:
 * c++ main.cpp -lraylib -I /opt/homebrew/Cellar/raylib/5.0/include -std=c++11
 */
