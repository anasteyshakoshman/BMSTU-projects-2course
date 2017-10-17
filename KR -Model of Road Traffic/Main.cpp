#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include <stdlib.h>

void Cars(Map & map)
{
	Car car(sf::Color::Blue, map, 7, 6);
	Car car1(sf::Color::Green, map, 9, 6);
	Car car2(sf::Color::Red, map, 10, 6);
	Car car3(sf::Color::Yellow, map, 12, 6);
	Car car4(sf::Color::Black, map, 13, 6);
	Car car5(sf::Color::Transparent, map, 15, 6);
}

void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Cars", sf::Style::Fullscreen);   //окно
	View view;   //камера
	Map map("map.png");   //карта
	//Car car(sf::Color::Blue, map, 7, 6);
	Cars(map);
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
		/*window.draw(car.getSprite());
		car.go(map, window);*/
		for (int i = 0; i < Car::AllCars.size(); ++i)
		{
			window.draw(Car::AllCars[i].getSprite());
			Car::AllCars[i].go(map, window);
		}
		std::cout << std::endl;
		window.display();
	}	
}


