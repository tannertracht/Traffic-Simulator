#include "carNode.h"



carNode::carNode()
{
	previous = nullptr;
	image.setSize(sf::Vector2f(50, 50));
	image.setOutlineColor(sf::Color::Red);
	image.setOutlineThickness(5);
	image.setPosition(750, 50);
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
