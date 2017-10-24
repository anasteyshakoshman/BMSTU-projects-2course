#include "Include.h"

#pragma once
class Map;

class TrafficLight
{
	sf::CircleShape Circle;
	sf::Color Color;
	float X;
	float Y;
public:
	static std::vector<TrafficLight> AllTrafficLight;

	TrafficLight(sf::RenderWindow &, const Map & map, const int x, const int y);
	const sf::Color getColor();
	~TrafficLight();
	int getX() const;
	int getY() const;
	bool work(const float & clock, sf::RenderWindow & window);
};

