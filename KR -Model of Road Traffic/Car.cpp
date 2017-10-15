
#include "Car.h"
#include "Map.h"

std::vector<Car> Car::AllCars;

Car::Car(const sf::Color col, Map & map)
{
	Image.loadFromFile("images/car0.png");     
	Image.createMaskFromColor(sf::Color::White);
	Texture.loadFromImage(Image);      
	Sprite.setTexture(Texture);        
	Sprite.setColor(col);              
	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));  
	X = 7; 
	Y = 6;
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

void Car::coordinateChange(const std::vector<int> vec, const int index)
{
	if (Direction != vec[index])
	{
		if (!vec[index])
		{
			dX = Speed;
			dY = 0;
			Image.loadFromFile("images/car0.png");
		}
		if (vec[index] == 1)
		{
			dX = 0;
			dY = Speed;
			Image.loadFromFile("images/car1.png");
		}
		if (vec[index] == 2)
		{
			dX = -Speed;
			dY = 0;
			Image.loadFromFile("images/car2.png");
		}
		if (vec[index] == 3)
		{
			dX = 0;
			dY = -Speed;
			Image.loadFromFile("images/car3.png");
		}
		Direction = vec[index];
		ChangeDir = true;
		Image.createMaskFromColor(sf::Color::White);
		Texture.loadFromImage(Image);
		Sprite.setTexture(Texture);
		Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
	}	                      
}


std::vector<int> Car::freeeDirections(Map & map)
{
	std::vector<int> vec;
	if (Oil)
	{
		switch (Direction)
		{
		case 0:
		{
				  if (map.getTM()[int(Y)][int(X) + 1] == 'r' || \
					  map.getTM()[int(Y)][int(X) + 1] == 'p' && (map.getTM()[int(Y)][int(X) + 2] == 'p' ||\
					  map.getTM()[int(Y)][int(X) + 2] == 'r' ||  map.getTM()[int(Y) - 2][int(X) + 1] == 'r')) \
						  vec.push_back(0);
					  if (map.getTM()[int(Y) + 1][int(X)] == 'r' && map.getTM()[int(Y) + 1][int(X) + 1] == 'r' && !ChangeDir) vec.push_back(1);
					  if (map.getTM()[int(Y) - 2][int(X)] == 'r' && map.getTM()[int(Y) - 2][int(X) - 1] == 'r'&& !ChangeDir) vec.push_back(3);
					  break;
			}
			case 1:
			{
					  if (map.getTM()[int(Y) + 1][int(X)] == 'r' ||  \
						  map.getTM()[int(Y) + 1][int(X)] == 'p' && (map.getTM()[int(Y) + 2][int(X)] == 'p' ||\
						  map.getTM()[int(Y) + 2][int(X)] == 'r' || map.getTM()[int(Y) + 1][int(X) + 2] == 'r' )) \
						  vec.push_back(1);
					  if (map.getTM()[int(Y)][int(X) - 1] == 'r' && map.getTM()[int(Y) + 1][int(X) - 1] == 'r'&& !ChangeDir) vec.push_back(2);
					  if (map.getTM()[int(Y)][int(X) + 2] == 'r' && map.getTM()[int(Y) - 1][int(X) + 2] == 'r'&& !ChangeDir) vec.push_back(0);
					  break;
			}
			case 2:
			{
					  if (map.getTM()[int(Y)][int(X) - 1] == 'r' || \
						  map.getTM()[int(Y)][int(X) - 1] == 'p' && (map.getTM()[int(Y)][int(X) - 2] == 'p' ||\
						  map.getTM()[int(Y)][int(X) - 2] == 'r' ||   map.getTM()[int(Y) + 2][int(X) - 1] == 'r' )) \
						  vec.push_back(2);
					  if (map.getTM()[int(Y) - 1][int(X)] == 'r' && map.getTM()[int(Y) - 1][int(X) - 1] == 'r'&& !ChangeDir) vec.push_back(3);
					  if (map.getTM()[int(Y) + 2][int(X)] == 'r' && map.getTM()[int(Y) + 2][int(X) + 1] == 'r'&& !ChangeDir) vec.push_back(1);
					  break;
			}
			case 3:
			{
					  if (map.getTM()[int(Y) - 1][int(X)] == 'r' ||  \
						  map.getTM()[int(Y) - 1][int(X)] == 'p' && (map.getTM()[int(Y) - 2][int(X)] == 'p' || \
						  map.getTM()[int(Y) - 2][int(X)] == 'r' || map.getTM()[int(Y) - 1][int(X) - 2] == 'r' )) \
						  vec.push_back(3);
					  if (map.getTM()[int(Y)][int(X) + 1] == 'r' && map.getTM()[int(Y) - 1][int(X) + 1] == 'r'&& !ChangeDir) vec.push_back(0);
					  if (map.getTM()[int(Y)][int(X) - 2] == 'r' && map.getTM()[int(Y) + 1][int(X) - 2] == 'r'&& !ChangeDir) vec.push_back(2);
					  break;
			}
		}
	}	
	return vec;
}



void Car::go(Map & map, sf::RenderWindow & window)
{
	if (map.getTM()[int(X)][int(Y)] == 'r' && ChangeDir) ChangeDir = false;
	auto freeDir(freeeDirections(map));
	if (freeDir.size())
	{		
			int random = rand() % freeDir.size();
			for (int i = 0; i < freeDir.size(); ++i)
			{
				if (random == i) coordinateChange(freeDir, i);
			}
		X += dX;
		Y += dY;
		Sprite.move(120 * dX, 120 * dY);
		window.draw(Sprite);
		Oil -= 0.00000000001;
	}
	
}
