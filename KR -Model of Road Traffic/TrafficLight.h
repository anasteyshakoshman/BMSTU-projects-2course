#include "Include.h"

#pragma once
class Map;

class TrafficLight
{
	sf::CircleShape Circle;
	sf::CircleShape BlackCircle;
	sf::Color Color;
	int X;
	int Y;
	bool LastColor;
	int TimeChange;
	static std::vector<TrafficLight> AllTrafficLight;
public:
	
	static std::vector<TrafficLight> & Vec();
	TrafficLight(sf::RenderWindow &, const Map & map, const int x, const int y);
	sf::Color getColor() const;
	~TrafficLight();
	int getX() const;
	int getY() const;
	void work(const int clock, sf::RenderWindow & window);
};

