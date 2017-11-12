#pragma once

#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include "TrafficLight.h"
#include <ctime>


void createTrafficLight(sf::RenderWindow & window, const Map & map)        //создание светофоров
{
	for (int i = 0; i < map.getHeight(); ++i)
	{
		for (int j = 0; j < map.getWeight(); ++j)
		{
			if (map.getTM()[i][j] == 's') TrafficLight(window, map, j, i);
		}
	}
}

void addCar(sf::RenderWindow & window, const Map & map, std::pair <int, int> & currentClock)   //функция добавления машинки
{
	if (currentClock.first - currentClock.second >= 200 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currentClock.second = currentClock.first;
		srand(time(0));
		int random = rand() % 7;
		sf::Color color;
		if (!random) color = sf::Color::Green;
		else if (random == 1) color = sf::Color::Yellow;
		else if (random == 2) color = sf::Color::Red;
		else if (random == 3) color = sf::Color::Blue;
		else if (random == 4) color = sf::Color::Magenta;
		else if (random == 5) color = sf::Color::Cyan;
		else color = sf::Color::White;
		Car t(color, map, window);
	}
}



void Work(sf::RenderWindow & window, Map & map, View & view, std::pair<int, int> & currentClock, float time, int & num)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		std::cout << 1;//для Local  Windows Debugger (ставлю keyboard)
	}
	view.work(window, time);  //включаю камеру
	map.draw(window);   //рисую карту
	++currentClock.first;
	addCar(window, map, currentClock);
	
	if (currentClock.first % 300 == 0 && num < Car::AllCars.size()) num++;
	for (int i = 0; i < num; ++i)   //запусk движения машинок
	{
		Car::AllCars[i].go(window, map);
	}
	for (auto it = TrafficLight::AllTrafficLight.begin(); it != TrafficLight::AllTrafficLight.end(); ++it) //запуск работы светофоров
	{
		it->work(currentClock.first, window);
	}
}



