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
	laneQueue northLane(pointerWindow, "north");
	laneQueue eastLane(pointerWindow, "east");
	laneQueue southLane(pointerWindow, "south");
	laneQueue westLane(pointerWindow, "west");
	bool green = false;
	while (window.isOpen())
	{
		sf::Event event;
		window.clear();
		northLane.drawCars();
		northLane.moveCarsToStopLine();
		eastLane.drawCars();
		eastLane.moveCarsToStopLine();
		southLane.drawCars();
		southLane.moveCarsToStopLine();
		westLane.drawCars();
		westLane.moveCarsToStopLine();
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					northLane.addCar();
				}
				else if (event.key.code == sf::Keyboard::Right) {
					eastLane.addCar();
				}
				else if (event.key.code == sf::Keyboard::Down) {
					southLane.addCar();
				}
				else if (event.key.code == sf::Keyboard::Left) {
					westLane.addCar();
				}
			}
		}
		window.display();
	}

	return 0;
}