#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include "TrafficLight.h"
#include <stdlib.h>



void createTrafficLight(sf::RenderWindow & window, const Map & map)
{
	for (int i = 0; i < map.getHeight(); ++i)
	{
		for (int j = 0; j < map.getWeight(); ++j)
		{
			if (map.getTM()[i][j] == 's') TrafficLight(window, map, j, i);
		}
	}
}


void addCar(sf::RenderWindow & window, Map & map)
{
	std::string tmp;
	sf::Color color;
	bool enter = false;
	while (!enter)
	{
		std::cout << "Enter color of your car : ";
		std::cin >> tmp;
		if (tmp == "Green" || tmp == "green")
		{
			color = sf::Color::Green;
			enter = true;
		}
		else if (tmp == "Black" || tmp == "black")
		{
			color = sf::Color::Black;
			enter = true;
		}
		else if (tmp == "Yellow" || tmp == "yellow")
		{
			color = sf::Color::Yellow;
			enter = true;
		}
		else if (tmp == "Red" || tmp == "red")
		{
			color = sf::Color::Red;
			enter = true;
		}
		else if (tmp == "Blue" || tmp == "blue")
		{
			color = sf::Color::Blue;
			enter = true;
		}
	} 
	Car(color, map, window, 7, 6);
}



void Cars(const Map & map, sf::RenderWindow & window )
{
	Car (sf::Color::Blue, map, window, 8, 7);
	Car (sf::Color::Green, map, window, 9, 7);
	Car (sf::Color::Red, map, window, 10, 7);
	Car (sf::Color::Yellow, map, window, 11, 7);
	Car (sf::Color::Black, map, window, 12, 7);
	Car (sf::Color::Transparent, map, window, 13, 7);
} 

void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Cars"/*, sf::Style::Fullscreen*/);   //окно
	View view;   //камера
	Map map("map.png");   //карта
	Car car1(sf::Color::Red, map, window, 10, 7);
	Car car(sf::Color::Blue, map, window, 8, 7);
	//Cars(map, window);
	sf::Clock clock;    //часы
	float currentClock = 0;     //текущее время
	createTrafficLight(window, map);
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


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			std::cout << "";
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			addCar(window, map);
		}
		view.work(window, time);  //включаем камеру
		window.clear();
		currentClock += 1;
		map.draw(window);   //рисуем карту
		for (auto it = Car::AllCars.begin(); it != Car::AllCars.end(); ++it)
		{
			it->go(window, map);
		}
		for (auto it = TrafficLight::AllTrafficLight.begin(); it != TrafficLight::AllTrafficLight.end(); ++it)
		{
			if (it->work(currentClock, window))
				currentClock = 0;
		}
		window.display();
	}	
}


