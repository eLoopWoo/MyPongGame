#include "paddle.h"
#include "iostream"
#include "string"

void paddle::settings(sf::RenderWindow *win, float x = 94, float y = 250) {
	this->window = win;
	pad.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
	radius = 50;
	pad.setSize(sf::Vector2f(10, radius));

	this->score = 0;


	(*font).loadFromFile("C:\\abc.ttf");
	// Create a text
	(*text).setFont(*font);
	(*text).setCharacterSize(30);
	(*text).setStyle(sf::Text::Bold);
	//(*text).setColor(sf::Color(44,127,255));
}

paddle::paddle(sf::RenderWindow *win,float x=94,float y=250)
{
	this->window = win;
	pad.setPosition(sf::Vector2f(x, y));
	this->x = x;
	this->y = y;
	radius = 50;
	pad.setSize(sf::Vector2f(10, radius));

	this->score = 0;


	(*font).loadFromFile("C:\\abc.ttf");
	// Create a text
	(*text).setFont(*font);
	(*text).setCharacterSize(30);
	(*text).setStyle(sf::Text::Bold);
	//(*text).setColor(sf::Color(44,127,255));

}


paddle::~paddle()
{
}



void paddle::move(float y) {



	this->y = y+get_y();
	pad.setPosition(sf::Vector2f(this->x, this->y));

	if (get_y() > 432-50) {
		set_y(432-50 );
	}
	if (get_y() < 48+15) {
		set_y(48+15 );
	}

}


void paddle::set_y(float x) {
	this->y = x;

}

float paddle::get_x() {
	return (x);
}

float paddle::get_y() {
	return (y);
}

void paddle::print() {
	(*window).draw(pad);
}

int paddle::get_radius() {
	return(this->radius);
}


void paddle::set_score(int x) {
	this->score = get_score() + x;
}
int paddle::get_score() {
	return(this->score);
}

sf::Text* paddle::toString() {
	(*text).setString(std::to_string(get_score()));
	return (text);
}