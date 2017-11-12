#pragma once
#include "Include.h"


class Map
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	std::vector<std::string> TileMap;
	int Height;
	int Weight;
	char Simvol;

public:

	Map();

	Map(const sf::String file, const char simvol);

	void draw(sf::RenderWindow & window);
	
	Map & operator =(const Map & other);
	
	~Map();

	int getHeight() const;

	int getWeight() const;
	
	std::vector<std::string>  getTM() const;

	sf::Sprite getSprite();

	char getSimvol() const;

	Map(Map & other);
};









