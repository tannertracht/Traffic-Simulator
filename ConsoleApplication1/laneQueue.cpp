#include "laneQueue.h"
#include <iostream>
#include <stdlib.h>
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
	newCar->setNext(temp);
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
		if (head != nullptr) {
			head->setNext(nullptr);
		}
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
		// Moves the image
		if (temp->getNext() != nullptr) {
			if ((abs(temp->getNext()->image.getPosition().x - temp->image.getPosition().x)) >= 200) {
				temp->image.move(-0.05f, 0);
			}
		}
		else {
			temp->image.move(-0.05f, 0);
		}
		// Checks if the image is still on the screen (left side)
		if (temp->image.getPosition().x < 0) {
			// Removed images that have left the screen
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
