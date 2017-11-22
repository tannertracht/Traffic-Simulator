#pragma once
#include <SFML\Graphics.hpp>
class carNode
{
public:
	carNode();
	~carNode();
	carNode* getPrevious();
	void setPrevious(carNode*);
	sf::RectangleShape image;
private:
	carNode* previous;
};

