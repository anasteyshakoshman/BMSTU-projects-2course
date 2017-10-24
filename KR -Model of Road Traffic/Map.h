#include "Include.h"


class Map
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	std::vector<std::string> TileMap;
	int Height;
	int Weight;
public:
	Map();

	Map(const sf::String file);
	void draw(sf::RenderWindow & window);
	

	Map & operator =(const Map & other);
	
	~Map();

	int getHeight() const;

	int getWeight() const;
	
	std::vector<std::string>  getTM() const;
};









