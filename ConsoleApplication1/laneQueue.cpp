#include "laneQueue.h"
#include <iostream>
using namespace std;
laneQueue::laneQueue(sf::RenderWindow* realWindow)
{
	head = nullptr;
	window = realWindow;
}


laneQueue::~laneQueue()
{
}

void laneQueue::addCar()
{
	carNode* newCar = new carNode;
	if (head == nullptr) {
		head = newCar;
		return;
	}
	carNode* temp = head;
	while (temp->getPrevious() != nullptr) {
		temp = temp->getPrevious();
	}
	temp->setPrevious(newCar);
	return;
}

void laneQueue::pop()
{
	carNode temp;
	if (head == nullptr) {
		return;
	}
	else {
		temp = *head;
		delete head;
		head = temp.getPrevious();
		return;
	}
}

void laneQueue::drawCars()
{
	if (head == nullptr) {
		return;
	}
	carNode* temp = head;
	while (temp->getPrevious() != nullptr) {
		window->draw(temp->image);
		temp = temp->getPrevious();
	}
	window->draw(temp->image);
}

void laneQueue::moveCars()
{
	bool search = true;
	if (head == nullptr) {
		return;
	}
	carNode* temp = head;
	do {
		temp->image.move(-0.05f, 0);
		if (temp->image.getPosition().x < 0) {
			if (temp->getPrevious() == nullptr) {
				pop();
				return;
			}
			else {
				temp = temp->getPrevious();
				pop();
			}
		}
		else {
			if (temp->getPrevious() != nullptr) {
				temp = temp->getPrevious();
			}
			else {
				return;
			}
		}
	} while (search);
}
