#pragma once
#include "Include.h"

class Map;
class Car
{
	//Map TLMap;
	int X, Y;
	int dX, dY;
	int Speed;
	int Direction;
	float Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
	bool ChangeDir;
	
public:
	static std::vector<Car> AllCars;

	Car(const sf::Color col, const Map & map, sf::RenderWindow & window, const int x, const int y);
	~Car();
	void go(sf::RenderWindow &, const Map &  TLMap);
	const std::vector<int> freeDirections(const Map &  TLMap) const;
	bool coordinateChange(const std::vector<int>, const int index, const Map & map);
	const int getX() const;
	const int getY() const;
	const int mX() const;
	const int mY() const;
	const int mdX() const;
	const int mdY() const;
	bool lightAround(const Map & TLMap) const;
	const bool nextCar(const int dx, const int dy, const Map & TLMap) const;





};
