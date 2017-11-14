#pragma once

#include "Include.h"
#include "Car.h"
#include "Map.h"
#include "View.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Crash.h"
#include <ctime>


void createTrLightAndRSign(sf::RenderWindow & window, const Map & map)        //создание светофоров
{
	for (int i = 0; i < map.getHeight(); ++i)
	{
		for (int j = 0; j < map.getWeight(); ++j)
		{
			if (map.getTM()[i][j] == 's') TrafficLight(window, map, j, i);
			else if (map.getTM()[i][j] == 'y' || map.getTM()[i][j] == 'k') RoadSign( j, i, map.getTM()[i][j]);
		}
	}
}

void addCar(const sf::Texture & texture, sf::RenderWindow & window, const Map & map, std::pair <int, int> & currentClock)   //функция добавления машинки
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
		Car(texture, color, map, window);
	}
}


bool isCrash()
{
	if (Car::Vec().size() > 30)
	{
		int random = rand() % 10;
		if (random < 3) return true;
	}
	return false;
}



void Work(sf::RenderWindow & window, Map & map, View & view, const sf::Texture & texture, std::pair<int, int> & currentClock, float time, bool & crash)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		std::cout << 1;//для Local  Windows Debugger (ставлю keyboard)
	}
	view.work(window, time);  //включаю камеру
	map.draw(window);   //рисую карту
	++currentClock.first;
	addCar(texture, window, map, currentClock);

	for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it) //запуск работы светофоров
	{
		it->work(currentClock.first, window);
	}
	for (int i = 0; i < Car::Vec().size(); ++i)   //запусk движения машинок
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || isCrash()) crash = true;
		Car::Vec()[i].go(window, map, crash);
		crash = false;
	}
	for (int i = 0; i < Car::Vec().size(); ++i)
	{
		if (!Car::Vec()[i].getLife()) 
			Car::Vec().erase(Car::Vec().begin() + i);
	}
	for (int i = 0; i < Crash::Vec().size(); ++i)
	{
		if (Crash::Vec()[i].work(window) == 3000) 
			Crash::Vec().erase(Crash::Vec().begin() + i);
	}
}



