#include "Game.hpp"
#include "Ball.hpp"
#include "Parameters.hpp"
#include <cstdlib>
#include <iostream>

Game::Game(Paddle *p1, Paddle *p2, Ball *ball){
	this->p1 = p1;
	this->p2 = p2;
	this->ball = ball;
}

Game::~Game(){}

void Game::update(){
	if(IsKeyDown(KEY_W)){p1->setSpeed(-3.5f);}
	else if (IsKeyDown(KEY_S)){p1->setSpeed(3.5f);}
	else {p1->setSpeed(0.0f);}
	if (IsKeyDown(KEY_UP)) {p2->setSpeed(-3.5f);}
	else if (IsKeyDown(KEY_DOWN)) {p2->setSpeed(4.5f);}
	else {p2->setSpeed(0.0f);}
	if (IsKeyDown(KEY_ENTER) && ball->getSpeed() == 0){
		rand() % 2 == 0 ? ball->setSpeed(BALL_SPEEDX, rand() % 2 == 0 ? BALL_SPEEDY : -BALL_SPEEDY)
		:
		ball->setSpeed(-BALL_SPEEDX, rand() % 2 == 0 ? BALL_SPEEDY : -BALL_SPEEDY);
	}
	if (ball->getX() + ball->getwidth() < 0 || ball->getX() > SCREEN_WIDTH){
		ball->reset();
	}
	if (ball->hitPaddle(this->p1)){
		ball->setSpeed(-ball->getSpeed(), ball->getSpeedy());
	}
	if (ball->hitPaddle(this->p2)){
		ball->setSpeed(-ball->getSpeed(), ball->getSpeedy());
	}
	p1->update();
	p2->update();
	ball->update();
}

void Game::loop(){
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
	SetTargetFPS(60);
	while (!WindowShouldClose()){
		this->update();
		BeginDrawing();
		ClearBackground(RAYWHITE);
		this->render();
		EndDrawing();
	}
	CloseWindow();
	this->p1->~Paddle();
	this->p2->~Paddle();
	this->~Game();
}

void Game::render(){
	p1->draw();
	p2->draw();
	ball->draw();
}
