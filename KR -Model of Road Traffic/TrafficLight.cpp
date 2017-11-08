#include "TrafficLight.h"
#include "Map.h"

std::vector<TrafficLight> TrafficLight::AllTrafficLight;


TrafficLight::TrafficLight(sf::RenderWindow & window, const Map & map, const int x, const int y)
{
	BlackCircle.setRadius(pix / 4); //черная оконтовка
	Circle.setRadius(pix / 4 - 5);  //чтобы светофоры были меньше машин
	X = x * pix;
	Y = y * pix;
	if (map.getTM()[y + 1][x + 1] == 'p')  // direction = 1
	{
	    Color = sf::Color::Red;                             //изначально присваиваю разные цвета противополжным светофорам, затем просто их меняю
		BlackCircle.setPosition(X + pix / 2, Y + pix / 2);
		Circle.setPosition(X + pix/2 + 5, Y + pix/2 + 5);
	}
	else if (map.getTM()[y + 1][x - 1] == 'p')   // direction = 2
	{
		Color = sf::Color::Green;                             	
		BlackCircle.setPosition(X, Y + pix / 2);
		Circle.setPosition(X + 5, Y + pix / 2 + 5);
	}
	else if (map.getTM()[y - 1][x - 1] == 'p')   // direction = 3
	{
		Color = sf::Color::Red;                             
		BlackCircle.setPosition(X , Y );
		Circle.setPosition(X + 5, Y + 5);
	}
	else if (map.getTM()[y - 1][x + 1] == 'p')    // direction = 0
	{
		Color = sf::Color::Green;                             
		BlackCircle.setPosition(X + pix / 2, Y);
		Circle.setPosition(X + pix/2 + 5, Y + 5);
	}
	BlackCircle.setFillColor(sf::Color::Black);
	Circle.setFillColor(Color);
	window.draw(BlackCircle);
	window.draw(Circle);
	AllTrafficLight.push_back(*this);
}


void TrafficLight::work(const int  clock, sf::RenderWindow & window)
{
	if (clock % 500 == 0)     //цвет светофоров меняется каждые 1000 microseconds 
	{
		if (Color == sf::Color::Red) Color = sf::Color::Green;
		else Color = sf::Color::Red;
		Circle.setFillColor(Color);
	}
	window.draw(BlackCircle);
	window.draw(Circle);
}

int TrafficLight::getX() const
{
	return X / pix;
}
int TrafficLight::getY() const
{
	return Y / pix;
}


sf::Color TrafficLight::getColor() const
{
	return Color;
}



TrafficLight::~TrafficLight()
{
	X = 0;
	Y = 0;
}
