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
	if (currentClock.first - currentClock.second >= 500 && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		currentClock.second = currentClock.first;
		srand(time(0));
		int random = rand() % 4;
		sf::Color color;
		if (!random) color = sf::Color::Green;
		else if (random == 2) color = sf::Color::Yellow;
		else if (random == 3) color = sf::Color::Red;
		else if (random == 1) color = sf::Color::Blue;
		Car(color, map, window);
	}
}




void Cars(const Map & map, sf::RenderWindow & window )   
{
	Car (sf::Color::Blue, map, window);
	Car (sf::Color::Green, map, window);
	Car (sf::Color::Red, map, window);
	Car (sf::Color::Yellow, map, window);
	Car (sf::Color::Black, map, window);
	Car (sf::Color::Transparent, map, window);
} 


void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Cars", sf::Style::Fullscreen);   //окно
	View view;   //камера
	Map map("map.png", 'a');   //карта

	size_t numCar = 1;  

	Car car(sf::Color::Blue, map, window);

	sf::Clock clock;    //часы
	std::pair <int, int> currentClock;     //first - текущее время, second - переменная для addCar
	currentClock.first = 0;
	createTrafficLight(window, map);  //создание светофоров
	while (window.isOpen())     
	{
		sf::Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();   //запуск часов
		time = time / 800;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			std::cout << 1;//для Local  Windows Debugger (ставлю keyboard)
		}
		view.work(window, time);  //включаю камеру
		window.clear();
		++ currentClock.first;
		addCar(window, map, currentClock);
		map.draw(window);   //рисую карту
		
		for (auto it = Car::AllCars.begin(); it != Car::AllCars.end(); ++it)   //запус движения машинок
		{
			it->go(window, map);
		}
		for (auto it = TrafficLight::AllTrafficLight.begin(); it != TrafficLight::AllTrafficLight.end(); ++it) //запуск работы светофоров
		{
			it->work(currentClock.first, window);
		}
		if (numCar < Car::AllCars.size())
		{
			numCar = Car::AllCars.size();
			std::cout << numCar;
		}
		



		window.display();               //вывод в окно
	}	 
}


