#pragma once
#include "Include.h"

class Map;
class Car
{
	int X, Y;      //координаты типа int, так как y типа float число записывалось с каким-то непонятным приращением
	int dX, dY;    // пример : я писала float x = 0.2 (оно записывалосось как 0.200000007 ), при увелечении координат это приращение увеличивалось и влияло координаты
	int Speed;     
	int Direction;
	double Oil;
	sf::Sprite Sprite;              
	sf::Color Color;
	bool ChangeDir;     //переменная, для контроля за тем, чтобы машинка не могла менять напрвление на перекрестке по 10 раз 
	bool Life;
	static std::vector<Car> AllCars;
public:
	
	static std::vector<Car> & Vec();
	Car(const sf::Texture & texture, sf::Color col, const Map & map, sf::RenderWindow & window);
	Car(const sf::Texture & texture, const sf::Color col, const Map & map, sf::RenderWindow & window, const int x, const int y, const int direction);
	~Car();
	void go(sf::RenderWindow &, const Map &  map, const bool crash);
	std::vector<int> freeDirections(const Map &  map) const;
	void changeDirection(const int direct);
	int getX() const;
	int getY() const;
	int mX() const;
	int mY() const;
	int mdX() const;
	int mdY() const;
	bool lightAround(const Map & map) const;
	int nextCar(const Map & map, const bool crash) const;
	int mod(const int num) const;
	int getSpeed() const;
	void signAround(const Map & map);
	void changeSpeed(const int newSpeed);
	int okrugl(const int xy) const;
	bool getLife() const;
	bool crashAround();
	


};
