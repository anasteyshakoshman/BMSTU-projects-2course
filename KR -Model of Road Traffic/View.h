#include "Include.h"


class View
{
	sf::View Camera;

public:

	View()
	{
		Camera.reset(sf::FloatRect(0, 0, 640, 480));
	}

	

	sf::View & getCamera()
	{
		return Camera;
	}

	


	void work(sf::RenderWindow & wind, const float time)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Camera.move(time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Camera.move(0, time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Camera.move(-time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Camera.move(0, -time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Camera.zoom(1.0100f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Camera.zoom(0.9900f); 
		}
		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Camera.setSize(4800, 2400);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Camera.setSize(9600, 5760);
		}*/

		wind.setView(Camera);
	}
};







