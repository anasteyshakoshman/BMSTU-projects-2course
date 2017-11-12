#pragma once
#include "Include.h"

class Map;
class Car
{
	int X, Y;      //координаты типа int, так как y типа float число записывалось с каким-то непонятным приращением
	int dX, dY;    // пример : я писала float x = 0.2 (оно записывалосось как 0.200000009), при увелечении координат это приращение увеличивалось и влияло координаты
	int Speed;     
	int Direction;
	double Oil;
	sf::Texture Texture;
	sf::Sprite Sprite;              
	sf::Color Color;
	bool ChangeDir;     //переменная, для контроля за тем, чтобы машинка не могла менять напрвление на перекрестке по 10 раз 
	
public:
	static std::vector<Car> AllCars;

	Car(const sf::Color col, const Map & map, sf::RenderWindow & window);
	Car(const sf::Color col, const Map & map, sf::RenderWindow & window, const int x, const int y, const int direction);
	~Car();
	void go(sf::RenderWindow &, const Map &  map);
	std::vector<int> freeDirections(const Map &  map) const;
	void changeDirection(const int direct, const Map & map);
	int getX() const;
	int getY() const;
	int mX() const;
	int mY() const;
	int mdX() const;
	int mdY() const;
	bool lightAround(const Map & map) const;
	bool nextCar(const Map & map) const;
	int mod(const int num) const;
	int getSpeed() const;




};
