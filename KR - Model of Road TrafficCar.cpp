
#include "Car.h"

Car::Car(const sf::String F, sf::Color col, const float x, const float y, const float w, const float h)
{
	Texture.loadFromFile("images/" + F);
	Sprite.setTexture(Texture);
	X = x;
	Y = y;
	W = w;
	H = h;
	Color = col;
	dX = 0;
	dY = 0;
	Speed = 0;
	Direction = 0;
	Oil = 10.0;
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
