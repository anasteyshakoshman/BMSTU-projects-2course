
#include "Car.h"
#include <math.h>
#include <ctime>
#include "Map.h"
#include "TrafficLight.h"



std::vector<Car> Car::AllCars;

Car::Car(const sf::Color col, const Map &  map, sf::RenderWindow & window, const int x, const int y)
{
	Image.loadFromFile("images/car0.png");
	Image.createMaskFromColor(sf::Color::White);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setColor(col);
	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	X = x * 120;
	Y = y * 120;
	Speed = 0.05 * 120;
	dX = Speed;
	dY = 0;
	Direction = 0; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)
	Oil = 100;
	//TLMap = map;
	ChangeDir = false;
	Sprite.setPosition(X, Y);
	AllCars.push_back(*this);
	window.draw(Sprite);
};




Car::~Car()
{
	X = 0;
	Y = 0;
	dX = 0;
	dY = 0;
	Speed  = 0;
	Direction = 0;
	Oil = 0;
};


const int Car::getX() const
{
	return X;
};

const int Car::getY() const
{
	return Y;
};


const bool Car::nextCar(const int dx, const int dy, const Map & TLMap) const
{
	int interval = 2;
	if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p' /*\
		|| TLMap.getTM()[*/ ) interval *= 10;
	for (auto it = AllCars.begin(); it != AllCars.end(); ++it)
	{
		if (X + dx * interval + 120 == it->getX() && Y + dy * interval + 120 == it->getY()) return false;
	}
	return true;
};


bool Car::coordinateChange(const std::vector<int> vec, const int index, const Map & map)
{
	bool change = false;
	if (Direction != vec[index])
	{
		if (!vec[index] && nextCar(Speed, 0, map))
		{
			dX = Speed;
			dY = 0;
			change = true;
			Image.loadFromFile("images/car0.png");
		}
		if (vec[index] == 1 && nextCar(0, Speed, map))
		{
			dX = 0;
			dY = Speed;
			change = true;
			Image.loadFromFile("images/car1.png");
		}
		if (vec[index] == 2 && nextCar(-Speed, 0, map))
		{
			dX = -Speed;
			dY = 0;
			change = true;
			Image.loadFromFile("images/car2.png");
		}
		if (vec[index] == 3 && nextCar(0, -Speed, map))
		{
			dX = 0;
			dY = -Speed;
			change = true;
			Image.loadFromFile("images/car3.png");
		}
		if (change)
		{
			Direction = vec[index];
			ChangeDir = true;
			Image.createMaskFromColor(sf::Color::White);
			Texture.loadFromImage(Image);
			Sprite.setTexture(Texture);
			Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
		}
		return change;
	}	
	else return nextCar(dX, dY, map);
};

const int Car::mX() const
{
	int x = X;
	if (x % 120 == 0) return x / 120;
	else
	{
		int ost = x;
		while (ost > 120) ost -= 120;
		if (Direction == 0 || Direction == 1) return (x - ost) / 120;   //floor
		if (Direction == 2 || Direction == 3) return (x - ost + 120) / 120;   //ceil
	}
};

const int Car::mY() const
{
	int y = Y;
	if (y % 120 == 0) return y / 120;
	else
	{
		int ost = y;
		while (ost > 120) ost -= 120;
		if (Direction == 0 || Direction == 1) return (y - ost) / 120;   //floor
		if (Direction == 2 || Direction == 3) return (y - ost + 120) / 120;   //ceil
	}
};

const int Car::mdX() const
{
	return dX / 6;
};

const int Car::mdY() const
{
	return dY / 6;
};



const std::vector<int> Car::freeDirections(const Map &  TLMap) const
{
	std::vector<int> vec;

//	if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'r' || \
//		TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && \
//(TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p' || \
//		TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'r' || \
//		TLMap.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'))\
//		vec.push_back(Direction);
//
//	if (TLMap.getTM()[mY() + mdX() * pow(-1, Direction)][mX() + mdY() * pow(-1, Direction)] == 'r' && \
//		TLMap.getTM()[mY() + mdY() + mdX()][mX() + mdX() * pow(-1, Direction) + mdY() * pow(-1, Direction)] == 'r' && !ChangeDir)
//		vec.push_back((Direction + 1) % 4);
//
//	if (TLMap.getTM()[mY() - 2 * mdX() * pow(-1, Direction)][mX() - 2 * mdY() * pow(-1, Direction)] == 'r' &&\
//		TLMap.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'&& !ChangeDir)
//		vec.push_back((Direction + 3) % 4);

	                                   								
	switch (Direction)                     
	{
		case 0:
		{
				  if (TLMap.getTM()[mY()][mX() + 1] == 'r' || \
					  TLMap.getTM()[mY()][mX() + 1] == 'p' && (TLMap.getTM()[mY()][mX() + 2] == 'p' ||\
					  TLMap.getTM()[mY()][mX() + 2] == 'r' || TLMap.getTM()[mY() - 2][mX() + 1] == 'r'))\
					  vec.push_back(0);
				  if (TLMap.getTM()[mY() + 1][mX()] == 'r' && TLMap.getTM()[mY() + 1][mX() + 1] == 'r' && !ChangeDir) vec.push_back(1);
				  if (TLMap.getTM()[mY() - 2][mX()] == 'r' && TLMap.getTM()[mY() - 2][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  break;
		}
		case 1:
		{
				  if (TLMap.getTM()[mY() + 1][mX()] == 'r' || \
					  TLMap.getTM()[mY() + 1][mX()] == 'p' && (TLMap.getTM()[mY() + 2][mX()] == 'p' ||\
					  TLMap.getTM()[mY() + 2][mX()] == 'r' || TLMap.getTM()[mY() + 1][mX() + 2] == 'r'))\
					  vec.push_back(1);
				  if (TLMap.getTM()[mY()][mX() - 1] == 'r' && TLMap.getTM()[mY() + 1][mX() - 1] == 'r' && !ChangeDir) vec.push_back(2);
				  if (TLMap.getTM()[mY()][mX() + 2] == 'r' && TLMap.getTM()[mY() - 1][mX() + 2] == 'r'&& !ChangeDir) vec.push_back(0);
				  break;
		}
		case 2:
		{
				  if (TLMap.getTM()[mY()][mX() - 1] == 'r' || \
					  TLMap.getTM()[mY()][mX() - 1] == 'p' && (TLMap.getTM()[mY()][mX() - 2] == 'p' ||\
					  TLMap.getTM()[mY()][mX() - 2] == 'r' || TLMap.getTM()[mY() + 2][mX() - 1] == 'r'))\
					  vec.push_back(2);
				  if (TLMap.getTM()[mY() - 1][mX()] == 'r' && TLMap.getTM()[mY() - 1][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  if (TLMap.getTM()[mY() + 2][mX()] == 'r' && TLMap.getTM()[mY() + 2][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(1);
				  break;
		}
		case 3:
		{
				  if (TLMap.getTM()[mY() - 1][mX()] == 'r' || \
					  TLMap.getTM()[mY() - 1][mX()] == 'p' && (TLMap.getTM()[mY() - 2][mX()] == 'p' ||\
					  TLMap.getTM()[mY() - 2][mX()] == 'r' || TLMap.getTM()[mY() - 1][mX() - 2] == 'r'))\
					  vec.push_back(3);
				  if (TLMap.getTM()[mY()][mX() + 1] == 'r' && TLMap.getTM()[mY() - 1][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(0);
				  if (TLMap.getTM()[mY()][mX() - 2] == 'r' && TLMap.getTM()[mY() + 1][mX() - 2] == 'r'&& !ChangeDir) vec.push_back(2);
				  break;
		}
	}
	return vec;
}



bool Car::lightAround(const Map & TLMap) const
{
	int koef = 1;
	if (Direction == 1 || Direction == 3) koef = -1;
	for (auto it = TrafficLight::AllTrafficLight.begin(); it != TrafficLight::AllTrafficLight.end(); ++it)
	{
		if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p')
		{
			if (mX() + koef * mdY() == it->getX() && mY() + koef * mdX() == it->getY()\
				&& it->getColor() == sf::Color::Red) return false;
		}
	}
	return true;
}


void Car::go(sf::RenderWindow & window, const Map &  TLMap)
{
	if (TLMap.getTM()[mY()][mX()] == 'r' && ChangeDir)  ChangeDir = false;
	srand(time(0));
	std::vector<int> freeDir;
	if (lightAround(TLMap)) freeDir = freeDirections(TLMap);
	if (freeDir.size())
	{		
			int random = rand() % freeDir.size();
			for (int i = 0; i < freeDir.size(); ++i)
			{
				if (random == i)
				{
					if (coordinateChange(freeDir, i, TLMap))
					{
						X += dX;
						Y += dY;
						Sprite.move(dX, dY);
						Oil -= 0.00000000001;
					}
				}
			}			
	}	
	window.draw(Sprite);
}
