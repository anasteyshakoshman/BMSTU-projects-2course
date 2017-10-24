#include "TrafficLight.h"
#include "Map.h"

std::vector<TrafficLight> TrafficLight::AllTrafficLight;


TrafficLight::TrafficLight(sf::RenderWindow & window, const Map & map, const int x, const int y)
{
	Circle.setRadius(30);
	X = x * 120;
	Y = y * 120;
	if (map.getTM()[y + 1][x + 1] == 'p')  // direction = 1
	{
		Color = sf::Color::Red;
		Circle.setPosition(X + 60, Y + 60);
	}
	else if (map.getTM()[y + 1][x - 1] == 'p')   // direction = 2
	{
		Color = sf::Color::Green;
		Circle.setPosition(X, Y + 60);
	}
	else if (map.getTM()[y - 1][x - 1] == 'p')   // direction = 3
	{
		Color = sf::Color::Red;
		Circle.setPosition(X, Y);
	}
	else if (map.getTM()[y - 1][x + 1] == 'p')    // direction = 0
	{
		Color = sf::Color::Green;
		Circle.setPosition(X + 60, Y);
	}
	Circle.setFillColor(Color);
	window.draw(Circle);
	AllTrafficLight.push_back(*this);
}


bool TrafficLight::work(const float & clock, sf::RenderWindow & window)
{
	bool change = false;
	if (clock == 3600)
	{
		if (Color == sf::Color::Red) Color = sf::Color::Green;
		else Color = sf::Color::Red;
		Circle.setFillColor(Color);
		change = true;
	}
	window.draw(Circle);
	return change;
}

int TrafficLight::getX() const
{
	return X;
}
int TrafficLight::getY() const
{
	return Y;
}


const sf::Color TrafficLight::getColor()
{
	return Color;
}



TrafficLight::~TrafficLight()
{
	X = 0;
	Y = 0;
}
