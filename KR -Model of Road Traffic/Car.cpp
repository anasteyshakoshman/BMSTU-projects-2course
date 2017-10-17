
#include "Car.h"
#include "Map.h"
#include <math.h>
#include <ctime>

std::vector<Car> Car::AllCars;

//Car::Car(const sf::Color col, Map & map)
//{
//	Image.loadFromFile("images/car0.png");     
//	Image.createMaskFromColor(sf::Color::White);
//	Texture.loadFromImage(Image);      
//	Sprite.setTexture(Texture);        
//	Sprite.setColor(col);              
//	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));  
//	X = 7; 
//	Y = 6;
//	Speed = 0.05;
//	dX = Speed;
//	dY = 0;
//	Direction = 0; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)
//	Oil = 100;
//	ChangeDir = false;
//	Sprite.setPosition(120 * X, 120 * Y);          
//	AllCars.push_back(*this);
//}

Car::Car(const sf::Color col, Map & map, const double x, const double y)
{

	Image.loadFromFile("images/car0.png");
	Image.createMaskFromColor(sf::Color::White);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setColor(col);
	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	X = x;
	Y = y;
	Speed = 0.05;
	dX = Speed;
	dY = 0;
	Direction = 0; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)
	Oil = 100;
	ChangeDir = false;
	Sprite.setPosition(120 * X, 120 * Y);
	AllCars.push_back(*this);
}

const sf::Sprite & Car::getSprite()
{
	return Sprite;
}


Car::~Car()
{
	X = 0;
	Y = 0;
	dX = 0;
	dY = 0;
	Speed  = 0;
	Direction = 0;
	Oil = 0;
}


const double Car::getX()
{
	return X;
}
const double Car::getY()
{
	return Y;
}


const bool Car::nextCar(const double dx, const double dy)
{
	for (int i = 0; i < AllCars.size(); ++i)
	{
		if (X + 4 * dx == AllCars[i].X  &&  Y + 4 * dy == Car::AllCars[i].Y) return false;
	}
	return true;
}


bool Car::coordinateChange(const std::vector<int> vec, const int index)
{
	bool change = false;
	if (Direction != vec[index])
	{
		if (!vec[index] && nextCar(Speed, 0))
		{
			dX = Speed;
			dY = 0;
			change = true;
			Image.loadFromFile("images/car0.png");
		}
		if (vec[index] == 1 && nextCar(0, Speed))
		{
			dX = 0;
			dY = Speed;
			change = true;
			Image.loadFromFile("images/car1.png");
		}
		if (vec[index] == 2 && nextCar(-Speed, 0))
		{
			dX = -Speed;
			dY = 0;
			change = true;
			Image.loadFromFile("images/car2.png");
		}
		if (vec[index] == 3 && nextCar(0, -Speed))
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
	else return nextCar(dX, dY);

}

void Car::okruglenie()
{
	X = round(X * 100) / 100.;
	Y = round(Y * 100) / 100.;
}


const std::vector<int> Car::freeDirections(Map & map)
{
	std::vector<int> vec;
	if (Oil)
	{
		switch (Direction)
		{
		    case 0:
            {
				  if (map.getTM()[floor(Y)][floor(X) + 1] == 'r' || \
					  map.getTM()[floor(Y)][floor(X) + 1] == 'p' && (map.getTM()[floor(Y)][floor(X) + 2] == 'p' ||\
					  map.getTM()[floor(Y)][floor(X) + 2] == 'r' ||  map.getTM()[floor(Y) - 2][floor(X) + 1] == 'r')) \
						  vec.push_back(0);
					  if (map.getTM()[floor(Y) + 1][floor(X)] == 'r' && map.getTM()[floor(Y) + 1][floor(X) + 1] == 'r' && !ChangeDir) vec.push_back(1);
					  if (map.getTM()[floor(Y) - 2][floor(X)] == 'r' && map.getTM()[floor(Y) - 2][floor(X) - 1] == 'r'&& !ChangeDir) vec.push_back(3);
					  break;
			}
			case 1:
			{
					  if (map.getTM()[floor(Y) + 1][floor(X)] == 'r' ||  \
						  map.getTM()[floor(Y) + 1][floor(X)] == 'p' && (map.getTM()[floor(Y) + 2][floor(X)] == 'p' ||\
						  map.getTM()[floor(Y) + 2][floor(X)] == 'r' || map.getTM()[floor(Y) + 1][floor(X) + 2] == 'r' )) \
						  vec.push_back(1);
					  if (map.getTM()[floor(Y)][floor(X) - 1] == 'r' && map.getTM()[floor(Y) + 1][floor(X) - 1] == 'r'&& !ChangeDir) vec.push_back(2);
					  if (map.getTM()[floor(Y)][floor(X) + 2] == 'r' && map.getTM()[floor(Y) - 1][floor(X) + 2] == 'r'&& !ChangeDir) vec.push_back(0);
					  break;
			}
			case 2:
			{
					  if (map.getTM()[ceil(Y)][ceil(X) - 1] == 'r' || \
						  map.getTM()[ceil(Y)][ceil(X) - 1] == 'p' && (map.getTM()[ceil(Y)][ceil(X) - 2] == 'p' || \
						  map.getTM()[ceil(Y)][ceil(X) - 2] == 'r' || map.getTM()[ceil(Y) + 2][ceil(X) - 1] == 'r')) \
						  vec.push_back(2);
					  if (map.getTM()[ceil(Y) - 1][ceil(X)] == 'r' && map.getTM()[ceil(Y) - 1][ceil(X) - 1] == 'r'&& !ChangeDir) vec.push_back(3);
					  if (map.getTM()[ceil(Y) + 2][ceil(X)] == 'r' && map.getTM()[ceil(Y) + 2][ceil(X) + 1] == 'r'&& !ChangeDir) vec.push_back(1);
					  break;
			}
			case 3:
			{
					  if (map.getTM()[ceil(Y) - 1][ceil(X)] == 'r' || \
						  map.getTM()[ceil(Y) - 1][ceil(X)] == 'p' && (map.getTM()[ceil(Y) - 2][ceil(X)] == 'p' || \
						  map.getTM()[ceil(Y) - 2][ceil(X)] == 'r' || map.getTM()[ceil(Y) - 1][ceil(X) - 2] == 'r')) \
						  vec.push_back(3);
					  if (map.getTM()[ceil(Y)][ceil(X) + 1] == 'r' && map.getTM()[ceil(Y) - 1][ceil(X) + 1] == 'r'&& !ChangeDir) vec.push_back(0);
					  if (map.getTM()[ceil(Y)][ceil(X) - 2] == 'r' && map.getTM()[ceil(Y) + 1][ceil(X) - 2] == 'r'&& !ChangeDir) vec.push_back(2);
					  break;
			}
		}
	}	
	return vec;
}



void Car::go(Map & map, sf::RenderWindow & window)
{
	if (Direction == 0 || Direction == 1)  
	{
		if (map.getTM()[floor(Y)][floor(X)] == 'r' && ChangeDir) ChangeDir = false;
	}
	if (Direction == 2 || Direction == 3) 
	{
		if (map.getTM()[ceil(Y)][ceil(X)] == 'r' && ChangeDir)  ChangeDir = false;
	}
	srand(time(0));
	auto freeDir(freeDirections(map));
	if (freeDir.size())
	{		
			int random = rand() % freeDir.size();
			for (int i = 0; i < freeDir.size(); ++i)
			{
				if (random == i)
				{
					if (coordinateChange(freeDir, i))
					{
						X += dX;
						Y += dY;
						Sprite.move(120 * dX, 120 * dY);
						Oil -= 0.00000000001;
					}
				}
			}			
	}
	okruglenie();
	window.draw(Sprite);	
}
