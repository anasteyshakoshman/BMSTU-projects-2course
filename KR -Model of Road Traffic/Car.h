#include "Include.h"
class Map;
class Car
{
	double X, Y;
	double dX, dY;
	double Speed;
	int Direction; 
	float Oil;
	sf::Image Image;
	sf::Texture Texture;
	sf::Sprite Sprite;
	sf::Color Color;
	bool ChangeDir;
public:
	static std::vector<Car> AllCars;
	/*Car(const sf::Color, Map &);*/
	Car(const sf::Color, Map &, const double x, const double y);
	~Car();
	void go(Map &, sf::RenderWindow &);
	const bool around(Map &);
	const sf::Sprite & getSprite();
	const std::vector<int> freeDirections(Map & map);
	bool coordinateChange(const std::vector<int>, const int index);
	const double getX();
	const double getY();
	void okruglenie();
	void changedir();
	const bool nextCar(const double dx, const double dy);

	
	

};
