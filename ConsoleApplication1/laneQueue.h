#pragma once
#include "carNode.h"
#include <string>
class laneQueue
{
public:
	laneQueue(sf::RenderWindow*, std::string);
	~laneQueue();
	void addCar();
	void pop();
	void drawCars();
	void moveCarsToStopLine();
private:
	sf::RenderWindow* window;
	carNode* head;
	bool green = false;
	float speed = 0.05f;
	sf::Vector2i startPos;
	sf::Vector2f movement;
	std::string movementDirection;
};

