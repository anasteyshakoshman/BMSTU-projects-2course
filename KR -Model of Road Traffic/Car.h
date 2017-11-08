#pragma once
#include "Include.h"

class Map;
class Car
{
	//Map TLMap;
	int X, Y;      //координаты типа int, так как y типа float число записывалось с каким-то непонятным приращением
	int dX, dY;    // пример : я писала float x = 0.2 (оно записывалосось как 0.200000009), при увелечении координат это приращение увеличивалось и влияло координаты
	int Speed;     
	int Direction;
	double Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;              
	sf::Color Color;
	bool ChangeDir;     //переменная, для контроля за тем, чтобы машинка не могла менять напрвление на перекрестке по 10 раз 
	
public:
	static std::vector<Car> AllCars;

	Car(const sf::Color col, const Map & map, sf::RenderWindow & window);
	~Car();
	void go(sf::RenderWindow &, const Map &  TLMap);
	const std::vector<int> freeDirections(const Map &  TLMap) const;
	bool changeCoordinate(const int direct, const Map & map);
	const int getX() const;
	const int getY() const;
	const int mX() const;
	const int mY() const;
	const int mdX() const;
	const int mdY() const;
	bool lightAround(const Map & TLMap) const;
	const bool nextCar(const int dx, const int dy, const Map & TLMap) const;
	bool operator !=(const Car & other);





};
