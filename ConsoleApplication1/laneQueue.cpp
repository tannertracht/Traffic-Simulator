#include "laneQueue.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
laneQueue::laneQueue(sf::RenderWindow* realWindow, string direction)
{
	movementDirection = direction;
	head = nullptr;
	window = realWindow;
	stopLineDistance = window->getSize().x / 10;
	if (direction == "north") {
		startPos.x = window->getSize().x / 2 + 25;
		startPos.y = window->getSize().y;
		movement.x = 0;
		movement.y = -speed;
	}
	else if (direction == "east") {
		startPos.x = 0;
		startPos.y = window->getSize().y / 2 + 25;
		movement.x = speed;
		movement.y = 0;
	}
	else if (direction == "south") {
		startPos.x = window->getSize().x / 2 - 25;
		startPos.y = 0;
		movement.x = 0;
		movement.y = speed;
	}
	else if (direction == "west") {
		startPos.x = window->getSize().x;
		startPos.y = window->getSize().y / 2 - 25;
		movement.x = -speed;
		movement.y = 0;
	}
}


laneQueue::~laneQueue()
{
}

void laneQueue::addCar()
{
	carNode* newCar = new carNode(startPos);
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
	carNode temp(startPos);
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

void laneQueue::moveCarsToStopLine()
{
	bool search = true, stop = false;
	if (head == nullptr) {
		return;
	}
	carNode* temp = head;
	do {
		stop = false;
		// Checks if car is past the decided stop line (could be optimized)
		if (movementDirection == "north" && temp->image.getPosition().y <= window->getSize().y / 2 + stopLineDistance) {
			stop = true;
		}
		else if (movementDirection == "east" && temp->image.getPosition().x >= window->getSize().x / 2 - stopLineDistance) {
			stop = true;
		}
		else if (movementDirection == "south" && temp->image.getPosition().y >= window->getSize().y / 2 - stopLineDistance) {
			stop = true;
		}
		else if (movementDirection == "west" && temp->image.getPosition().x <= window->getSize().x / 2 + stopLineDistance) {
			stop = true;
		}
		// Moves the image
		if (stop) {
			// If the image has reached the stop line it will not advance
		}
		else if (temp->getNext() != nullptr) {
			// Checks if the image is the first image in the queue
			if ((abs(temp->getNext()->image.getPosition().x - temp->image.getPosition().x)) >= (temp->image.getSize().x + 25) || (abs(temp->getNext()->image.getPosition().y - temp->image.getPosition().y)) >= (temp->image.getSize().y + 25)) {
				// If it isn't the first image it will check the spacing between itself and the next car and only move 
				// if it has the space
				temp->image.move(movement.x, movement.y);
			}
		}
		else {
			// If the image is the front image it does not check for spacing in front
			temp->image.move(movement.x, movement.y);
		}
		// Checks if the image is still on the screen (left side)
		//if (temp->image.getPosition().x < 0) {
		//	// Removed images that have left the screen
		//	if (temp->getPrevious() == nullptr) {
		//		pop();
		//		return;
		//	}
		//	else {
		//		temp = temp->getPrevious();
		//		pop();
		//	}
		//}
		//else {
		if (temp->getPrevious() != nullptr) {
			temp = temp->getPrevious();
		}
		else {
			return;
		}
		//}
	} while (search);
}
