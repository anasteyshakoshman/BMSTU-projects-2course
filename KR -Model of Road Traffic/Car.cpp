
#include "Car.h"
#include "Map.h"


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
	//map.getTM()[Y][X] = 'c';
	dX = 0;
	dY = 0;
	//Speed = 0;
	Direction = 0; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)
	Oil = 10;
	Sprite.setPosition(120 * X, 120 * Y);
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
	//Speed  = 0;
	Direction = 0;
	Oil = 0;
}

void Car::coordinateChange(const std::vector<int> vec, const int index)
{
	if (!vec[index])
	{
		dX = 1;
		dY = 0;
		Image.loadFromFile("images/car0.png");
	}
	if (vec[index] == 1)
	{
		dX = 0;
		dY = 1;
		Image.loadFromFile("images/car1.png");
	}
	if (vec[index] == 2)
	{
		dX = -1;
		dY = 0;	
		Image.loadFromFile("images/car2.png");
	}
	if (vec[index] == 3)
	{
		dX = 0;
		dY = -1;
		Image.loadFromFile("images/car3.png");
	}
	Direction = vec[index];
	Image.createMaskFromColor(sf::Color::White);
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
}


std::vector<int> Car::freeeDirections(Map & map)
{
	std::vector<int> vec;
	if (Oil)
	{
		if (map.getTM()[Y][X + 1] == 'r' && map.getTM()[Y][X + 2] == 'r' && Direction != 2) vec.push_back(0);
		if (map.getTM()[Y + 1][X] == 'r' && map.getTM()[Y + 2][X] == 'r' && Direction != 3) vec.push_back(1);
		if (map.getTM()[Y][X - 1] == 'r' && map.getTM()[Y][X - 2] == 'r' && Direction != 0) vec.push_back(2);
		if (map.getTM()[Y - 1][X] == 'r' && map.getTM()[Y - 2][X] == 'r' && Direction != 1) vec.push_back(3);
	}	
	return vec;
}



void Car::go(Map & map, sf::RenderWindow & window)
{
	auto freeDir(freeeDirections(map));
	if (freeDir.size())
	{
		int random = rand() % freeDir.size();
		for (int i = 0; i < freeDir.size(); ++i)
		{
			if (random == i) coordinateChange(freeDir, i);
		}		
		map.getTM()[Y][X] = 'r';
		X += dX;
		Y += dY;
		//map.getTM()[Y][X] = 'c';
		Sprite.move(120 * dX, 120 * dY);
		window.draw(Sprite);
		//Oil -= 01;
		dX = 0;
		dY = 0;
	}	
}
