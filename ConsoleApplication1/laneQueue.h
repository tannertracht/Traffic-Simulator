#pragma once
#include "carNode.h"
class laneQueue
{
public:
	laneQueue(sf::RenderWindow*);
	~laneQueue();
	void addCar();
	void pop();
	void drawCars();
	void moveCars();
private:
	sf::RenderWindow* window;
	carNode* head;
};

