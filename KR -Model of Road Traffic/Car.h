#include "Include.h"
class Map;
class Car
{
	float X, Y;
	float dX, dY;
	float Speed;
	int Direction; 
	float Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
	bool ChangeDir;
	static std::vector<Car> AllCars;
public:
	Car(const sf::Color, Map &);
	~Car();
	void go(Map &, sf::RenderWindow &);
	const bool around(Map &);
	const sf::Sprite & getSprite();
	std::vector<int> freeeDirections(Map & map);
	void coordinateChange(const std::vector<int>, const int index);
	const float getX()
	{
		return X;
	}
	const float getY()
	{
		return Y;
	}

};
