#pragma once

#include <stdlib.h>
#include <SFML\Graphics.hpp>
class ball
{
private:
	
	sf::CircleShape c;
	sf::CircleShape* b = &c;
	sf::RenderWindow* window;
	float x=0;
	float y=0;

	float velocity_x = 2.5;
	float velocity_y = 3;
	




public:

	void set_velocity_x(float z);
	void set_velocity_y(float z);

	void ball::collision();

	float get_velocity_x();
	float get_velocity_y();


	void setWindow(sf::RenderWindow *win);
	ball();
	void settings(sf::RenderWindow *win, float x, float y);
	ball(float x,float y);
	ball(sf::RenderWindow *win,float x, float y);
	void move(float z, float w);
	void print();
	
	void set_x(float x);
	void set_y(float y);

	float get_x();
	float get_y();

	void control();

	void play();

	void randomStart();

};

