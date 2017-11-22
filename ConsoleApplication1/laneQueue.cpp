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

void laneQueue::moveCarsToStopLine()
{
	bool search = true;
	if (head == nullptr) {
		return;
	}
	carNode* temp = head;
	do {
		// Moves the image
		if (temp->image.getPosition().x <= window->getSize().x/2){
			// If the image has reached the stop line it will not advance
		}
		else if (temp->getNext() != nullptr) {
			// Checks if the image is the first image in the queue
			if ((abs(temp->getNext()->image.getPosition().x - temp->image.getPosition().x)) >= (temp->image.getSize().x + 25)) {
				// If it isn't the first image it will check the spacing between itself and the next car and only move 
				// if it has the space
				temp->image.move(-0.05f, 0);
			}
		}
		else {
			// If the image is the front image it does not check for spacing in front
			temp->image.move(-0.05f, 0);
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
