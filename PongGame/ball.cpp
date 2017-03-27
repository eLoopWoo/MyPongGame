#include "ball.h"
#include "gameWindow.h"



void ball::settings(sf::RenderWindow *win, float z, float w)
{
	window = win;
	x = z;
	y = w;
	(*b).setPosition(sf::Vector2f(x, y));
	(*b).setRadius(10);
}


ball::ball(float z,float w)
{
	x = z;
	y = w;
	(*b).setPosition(sf::Vector2f(x, y));
	(*b).setRadius(10);
}
ball::ball(sf::RenderWindow *win,float z, float w)
{
	window = win;
	x = z;
	y = w;
	(*b).setPosition(sf::Vector2f(x, y));
	(*b).setRadius(10);
}


void ball::setWindow(sf::RenderWindow *win) {
	window = win;
}
void ball::print() {
	(*window).draw(*b);
}
void ball::move(float z, float w) {
	x = z;
	y = w;
	(*b).setPosition(sf::Vector2f(x, y));
}
void ball::set_x(float z) {
	x = z;
	(*b).setPosition(sf::Vector2f(z, get_y()));
}
void ball::set_y(float w) {
	y = w;
	(*b).setPosition(sf::Vector2f(get_x(), w));
}
float ball::get_x() {
	return x;
}
float ball::get_y() {
	return y;
}


float ball::get_velocity_x(){
	return velocity_x;
}
float ball::get_velocity_y(){
	return  velocity_y;
}
void ball::set_velocity_x(float z) {
	velocity_x = z;
}
void ball::set_velocity_y(float z) {
	velocity_y = z;
}





void ball::control() {

	if (get_x() > 576 - 2*(*b).getRadius()) {
		set_velocity_x(-1 * get_velocity_x());
	}
	
	if (get_x() < 64 + 2 * (*b).getRadius()) {
		set_velocity_x(-1 * get_velocity_x());
	}
	if (get_y() > 432 - 2 * (*b).getRadius()) {
		set_velocity_y(-1* get_velocity_y());
	}
	if (get_y() < 48 + 2 * (*b).getRadius()) {
		set_velocity_y(-1 * get_velocity_y());
	}
	
}

void ball::play() {

	control();
	set_x(get_x() + get_velocity_x());
	set_y(get_y() + get_velocity_y());
	

}

void ball::collision() {
	set_velocity_x(-1 * get_velocity_x());
}

void ball::randomStart() {

	this->velocity_x = (rand() % 10) / 10 + 2;
	this->velocity_y = (rand() % 10) / 10 + 2;
	int direction = 0;
	direction = rand() % 2;
	if (direction)
		this->velocity_x *= -1;
	direction = rand() % 2;
	if (direction)
		this->velocity_y *= -1;
	
}