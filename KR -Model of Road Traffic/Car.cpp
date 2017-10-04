
#include "Car.h"
#include "Map.h"


Car::Car(const sf::String F, Map & map)
{
	Image.loadFromFile("images/" + F);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 100));
	map.getTM()[6][7] = 'c';
	X = 840;
	Y = 720;
	dX = 0;
	dY = 0;
	Speed = 0;
	Direction = 1; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)
	Oil = 10.0;
	Sprite.setPosition(X, Y);
}

const sf::Sprite & Car::getSprite()
{
	return Sprite;
}


Car::~Car()
{
	X = 0;
	Y = 0;
	W = 0;
	H = 0;
	dX = 0;
	dY = 0;
	Speed  = 0;
	Direction = 0;
	Oil = 0;
}

bool Car::around(Map & map)
{
	if (map.getTM()[X + dX][Y + dY] == 'r' && map.getTM()[X + 2 * dX][Y + 2 * dY]) return true;
	else return false;
}

void Car::go(Map & map)
{
	int random = 0;
	switch (Direction)
	{
	case 0:
	{
			  do
			  {
				  random = rand() % 3;
				  if (!random) dX = 120;
				  if (random == 1) dY = 120;
				  else dY = -120;
			  } 
			  while (!around(map));
			  break;
	}	
	case 1:
	{
			  do
			  {
				  random = rand() % 3;
				  if (!random) dY = 120;
				  if (random == 1) dX = 120;	
				  else  dX = -120;
			  } 
			  while (!around(map));
			  break;

	}		
	case 2:
	{
			  do
			  {
				  random = rand() % 3;
				  if (!random) dY = -120;
				  if (random == 1) dX = -120;
				  else  dX = 120;
			  } 
			  while (!around(map));
			  break;

	}		
	case 3:
	{
			  do
			  {
				  random = rand() % 3;
				  if (!random) dX = -120;
				  if (random == 1) dY = 120;
				  else dY = -120;
			  } 
			  while (around(map));			 
			  break;

		}
		X += dX;
		Y += dY;
		if (dX == 120)
		{
			Direction = 0;
			Sprite.setScale(1., 0.);
		}
		if (dX == -120)
		{
			Direction = 2;
			Sprite.setScale(-1., 0.);
		}
		if (dY == 120)
		{
			Direction = 1;
			Sprite.setScale(0., 1.);
		}
		if (dY == -120)
		{
			Direction = 3;
			Sprite.setScale(0., -1.);
		}
		Sprite.setPosition(X, Y);
		dX = 0; 
		dY = 0;
	}
	


	
}
