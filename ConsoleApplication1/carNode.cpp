#include "carNode.h"



carNode::carNode()
{
	previous = nullptr;
	next = nullptr;
	image.setSize(sf::Vector2f(50, 50));
	image.setOutlineColor(sf::Color::Red);
	image.setOutlineThickness(5);
	image.setPosition(750, 50);
	image.setOrigin(image.getSize().x / 2, image.getSize().y / 2);
}


carNode::~carNode()
{
}

carNode * carNode::getPrevious()
{
	return previous;
}

void carNode::setPrevious(carNode* node)
{
	previous = node;
}

carNode * carNode::getNext()
{
	return next;
}

void carNode::setNext(carNode * node)
{
	next = node;
}
