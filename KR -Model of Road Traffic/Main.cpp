#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"

void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Cars", sf::Style::Fullscreen);   //окно
	Map map("map.png");   //карта
	View view;   //камера
	sf::Clock clock;    //часы
	float CurrentClock = 0;     //текущее время
	while (window.isOpen())     
	{
		sf::Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();   //запускаем часы
		time = time / 800;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		view.work(window, time);  //включаем камеру

		window.clear();
		map.draw(window);   //рисуем карту
		//window.draw();
		window.display();   //вывод на дисплей
	}	
}