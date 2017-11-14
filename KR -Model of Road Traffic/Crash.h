#pragma once
#include "Include.h"
class Crash
{
	sf::CircleShape Red1;
	sf::CircleShape Red2;
	sf::CircleShape Yellow1;
	sf::CircleShape Yellow2;
	int Time;
	int X1, Y1;
	int X2, Y2;
	int RadiusRed, RadiusYellow;
	static std::vector<Crash> AllCrash;
public:
	static std::vector<Crash> & Vec();
	Crash(sf::RenderWindow & window, const int x1, const int y1, const int x2, const int y2);
	int work(sf::RenderWindow & window);
	int getX1() const;
	int getY1() const;
	int getX2() const;
	int getY2() const;
	~Crash();
};

