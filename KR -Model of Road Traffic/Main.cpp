#include "FunctionForMain.h"

void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Model of ROAD TRAFFIC", sf::Style::Fullscreen);   //окно
	View view;   //камера
	Map map("map.png", 'd');   //карта 

	sf::Texture texture;
	texture.loadFromFile("images/car.png");

	sf::Clock clock;    //часы
	std::pair <int, int> currentClock(0, 0);    //first - текущее время, second - переменная для addCar          
	float time = 0.;
	bool crash = false;

	createTrLightAndRSign(window, map);  //создание светофоров

	while (window.isOpen())     
	{
		sf::Event event;
		time = clock.getElapsedTime().asMicroseconds();
		clock.restart();   //запуск часов
		time = time / 800;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		window.clear();
		Work(window, map, view, texture, currentClock, time, crash);
		window.display();               //вывод в окно
	}	 
}


