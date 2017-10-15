#include "RoadSign.h"


RoadSign::RoadSign(const float x, const float y)
{
	Circle.setRadius(60);
	Color = sf::Color::Red;
	Circle.setFillColor(Color);
	X = x;
	Y = y;
	Circle.setPosition(X, Y);
}

const sf::Color RoadSign::getColor()
{
	return Color;
}

void RoadSign::changeColor(const sf::Color color)
{
	Color = color;
	Circle.setFillColor(Color);
}

RoadSign::~RoadSign()
{
	X = 0;
	Y = 0;
}
