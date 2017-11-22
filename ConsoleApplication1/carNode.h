#pragma once
#include <SFML\Graphics.hpp>
class carNode
{
public:
	carNode();
	~carNode();
	carNode* getPrevious();
	void setPrevious(carNode*);
	carNode* getNext();
	void setNext(carNode*);
	sf::RectangleShape image;
private:
	carNode* previous;
	carNode* next;
};

