#include "Include.h"

#pragma once
class RoadSign
{
	sf::CircleShape Circle;
	sf::Color Color;
	float X;
	float Y;

public:
	RoadSign(const float x, const float y);
	const sf::Color getColor();
	void changeColor(const sf::Color color);
	~RoadSign();
};

