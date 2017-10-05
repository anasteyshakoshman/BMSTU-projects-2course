#include "Include.h"
class Map;
class Car
{
	int X, Y;
	int dX, dY;
	//float Speed;
	int Direction; 
	float Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
public:
	Car(const sf::Color, Map &);
	~Car();
	void go(Map &, sf::RenderWindow &);
	const bool around(Map &);
	const sf::Sprite & getSprite();
	std::vector<int> freeeDirections(Map & map);
	void coordinateChange(const std::vector<int>, const int index);
	const int getX()
	{
		return X;
	}
	const int getY()
	{
		return Y;
	}
};
