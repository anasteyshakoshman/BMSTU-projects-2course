#include "Include.h"

class Car
{
	float X, Y;
	float W, H;  
	float dX, dY;
	float Speed;
	float Direction; 
	float Oil;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
public:
	Car(const sf::String, sf::Color, const float, const float, const float, const float);
	~Car();
};
