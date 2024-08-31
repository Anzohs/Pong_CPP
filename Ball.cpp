#include "Ball.hpp"

Ball::Ball()
{
	this->x = SCREEN_WIDTH / 2;
	this->y = SCREEN_HEIGHT / 2;
	this->height = 12.5f;
	this->width = 12.5f;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
}

bool Ball::hitPaddle(Paddle *paddle){
	if (this->x > paddle->getx() + paddle->getwidth() || paddle->getx() > this->x + this->width){return false;}
    if (this->y > paddle->gety() + paddle->getheight() || paddle->gety() > this->y + this->height){return false;}
    return true;
}

void Ball::update(){
	if (this->y <= 0)
		this->ySpeed *= -1;
	if (this->y + this->height >= SCREEN_HEIGHT)
		this->ySpeed *= -1;
	this->x += this->xSpeed;
	this->y += this->ySpeed;

}

void Ball::draw(){
	DrawRectangle(this->x, this->y, this->width, this->height, BLACK);
}

void Ball::setSpeed(float xSpeed, float ySpeed){
	this->xSpeed = xSpeed;
	this->ySpeed = ySpeed;
}

void Ball::reset(){
	this->x = SCREEN_WIDTH / 2;
	this->y = SCREEN_HEIGHT / 2;
	this->xSpeed = 0.0f;
	this->ySpeed = 0.0f;
}

float Ball::getSpeed(){
	return this->xSpeed;
}
float Ball::getSpeedy(){
	return this->ySpeed;
}

float Ball::getX(){
	return this->x;
}

float Ball::getwidth(){
	return this->width;
}
