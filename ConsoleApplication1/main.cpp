#include <SFML/Graphics.hpp>
#include <iostream>
#include "laneQueue.h"
using namespace std;
// Figure out how to use getPosition
// pop objects off the queue when they leave the window
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::RenderWindow* pointerWindow = &window;
	laneQueue lane(pointerWindow);
	bool green = false;
	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		lane.drawCars();
		lane.moveCarsToStopLine();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::C) {
					lane.addCar();
				}
				else if (event.key.code == sf::Keyboard::G) {
					green = true;
				}
			}
		}
		window.display();
	}

	return 0;
}