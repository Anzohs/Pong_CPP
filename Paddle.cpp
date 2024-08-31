#include "Paddle.hpp"

Paddle::Paddle(float x, float y){
	this->x = x;
	this->y = y;
	this->height = 80.0f;
	this->width = 15.0f;
	this->speed = 0.0f;
}

Paddle::~Paddle(){}

void Paddle::update(){
	if (this->speed < 0) {this->y = std::max(0.0f, this->y + this->speed);}
	else if (this->speed > 0) {this->y = std::min((float)SCREEN_HEIGHT - this->height, this->y + this->speed);}
}

void Paddle::draw(){
	DrawRectangle(this->x, this->y, this->width, this->height, BLACK);
}

void Paddle::setSpeed(float speed){this->speed = speed;}

float Paddle::getx(){return this->x;}
float Paddle::gety(){return this->y;}
float Paddle::getheight(){return this->height;}
float Paddle::getwidth(){return this->width;}
