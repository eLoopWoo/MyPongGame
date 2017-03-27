#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <ball.h>
#include <paddle.h>
ball* pointer;

paddle* me1;
paddle* me2;

sf::RenderWindow* p;




void test(HWND hwnd, UINT uMsg, UINT timerId, DWORD dwTime) {
	if ((*pointer).get_x()-10 <= (*me1).get_x()) {
		if ((*pointer).get_y() <= (*me1).get_y() + (*me1).get_radius()+20 && (*pointer).get_y() >= (*me1).get_y()-20)
			(*pointer).collision();
		else {
			printf("player2 score\n");
			printf("|| %F |^| %F||\n", (*pointer).get_x(), (*pointer).get_y());
			(*me2).set_score(1);
			(*pointer).set_x(320);
			(*pointer).set_y(192);
			(*pointer).randomStart();
		}
	}
	if ((*pointer).get_x()+20 >= (*me2).get_x()) {
		if ((*pointer).get_y() <= (*me2).get_y() + (*me2).get_radius()+20 && (*pointer).get_y() >= (*me2).get_y()-20)
			(*pointer).collision();
		else {
			printf("player1 score\n");
			printf("|| %F |^| %F||\n", (*pointer).get_x(), (*pointer).get_y());
			(*me1).set_score(1);
			(*pointer).set_x(320);
			(*pointer).set_y(192);
			(*pointer).randomStart();

		}
	}
	(*pointer).play();
}


int main() {


	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML Application");
	p = &window;

	sf::Event event;


	sf::RectangleShape border_top(sf::Vector2f(512,10));
	border_top.setPosition(sf::Vector2f((640-512)/2, (480-384)/2));
	sf::RectangleShape border_bottom(sf::Vector2f(512,10));
	border_bottom.setPosition(sf::Vector2f((640 - 512)/2, (480 - 384) / 2+384));

	sf::RectangleShape border_left(sf::Vector2f(10, 384));//100
	border_left.setPosition(sf::Vector2f((640 - 512)/2, (480 - 384) / 2));
	sf::RectangleShape border_right(sf::Vector2f(10, 384));//500
	border_right.setPosition(sf::Vector2f(512+ (640 - 512) / 2, (480 - 384) / 2));




	paddle paddle1(p,94,250);
	paddle paddle2(p, 556, 250);

	me1 = &paddle1;
	me2 = &paddle2;

	ball ball1(p, 300, 300);
	pointer = &ball1;

	sf::Text* string;






	sf::Font fonts;
	fonts.loadFromFile("C:\\abc.ttf");
	// Create a text
	sf::Text texts("Created by eLoopWoo", fonts);
	texts.setCharacterSize(30);
	texts.setStyle(sf::Text::Bold);
	texts.setPosition(sf::Vector2f(300, 450));



	UINT_PTR timerid = SetTimer(NULL, 0, 10, (TIMERPROC)&test);

	while (window.isOpen()) {


		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if(GetAsyncKeyState(0x57))
			paddle1.move(-0.25);

		if (GetAsyncKeyState(0x53))
			paddle1.move(0.25);

		if (GetAsyncKeyState(VK_UP))
			paddle2.move(-0.25);

		if (GetAsyncKeyState(VK_DOWN))
			paddle2.move(0.25);
		


				/*
			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					switch (event.text.unicode) {
					case 'o':
						printf("%c", event.text.unicode);
						paddle2.move(-10);
						break;
					case 'l':
						printf("%c", event.text.unicode);
						paddle2.move(10);
						break;
					case 's':
						printf("%c", event.text.unicode);
						paddle1.move(10);
						break;
					case 'w':
						printf("%c", event.text.unicode);
						paddle1.move(-10);
						break;
					default:
						break;
					}
					break;
				}
				break;
			}
		}
		*/

		
		
		window.clear();
		string = (*me1).toString();
		(*string).setPosition(sf::Vector2f(220, 10));
		window.draw(*string);


		string = (*me2).toString();
		(*string).setPosition(sf::Vector2f(400, 10));
		window.draw(*string);

		window.draw(texts);
		ball1.print();
		paddle1.print();
		paddle2.print();
		window.draw(border_top);
		window.draw(border_bottom);
		window.draw(border_left);
		window.draw(border_right);
		window.display();
	}
}