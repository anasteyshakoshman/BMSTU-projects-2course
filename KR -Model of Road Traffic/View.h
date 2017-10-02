#include "Include.h"


class View
{
	sf::View Camera;

public:

	View()
	{
		Camera.reset(sf::FloatRect(0, 0, 640, 480));
	}

	void viewgetXY(const float x, const float y)
	{
		float vX = x;
		float vY = y;
		if (x < 320) vX = 320;
		if (y < 240) vY = 240;
		if (y > 554) vY = 554;
		Camera.setCenter(vX, vY);
	}


	void work(sf::RenderWindow & wind, const float time)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			Camera.move(0.1*time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			Camera.move(0, 0.1*time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			Camera.move(-0.1*time, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			Camera.move(0, -0.1*time);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Camera.zoom(1.0100f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			//view.zoom(1.1f); 
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Camera.setSize(540, 380);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Camera.setSize(800, 500);
		}

		wind.setView(Camera);
	}
};







