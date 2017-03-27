#pragma once
#include <SFML\Graphics.hpp>
class paddle
{
private:
	sf::RectangleShape pad;
	sf::RectangleShape* my_paddle;
	sf::RenderWindow* window;

	int radius;
	float x;
	float y;

	int score;



	sf::Font fot;

	sf::Text tet;


	sf::Font* font = &fot;
	sf::Text* text = &tet;




public:
	paddle();
	void settings(sf::RenderWindow *win, float x, float y);
	paddle(sf::RenderWindow *win,float x,float y);
	~paddle();
	void move(float y);
	float get_x();
	float get_y();
	void print();

	void set_y(float x);

	int get_radius();


	void set_score(int x);
	int get_score();
	sf::Text* toString();

};

