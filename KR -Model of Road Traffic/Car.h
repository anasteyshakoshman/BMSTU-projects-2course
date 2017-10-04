#include "Include.h"
class Map;
class Car
{
	float X, Y;
	float W, H;  
	float dX, dY;
	float Speed;
	int Direction; 
	float Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
public:
	Car(const sf::String,  Map & map);
	~Car();
	void go(Map &);
	bool around(Map &);
	const sf::Sprite & getSprite();
};
