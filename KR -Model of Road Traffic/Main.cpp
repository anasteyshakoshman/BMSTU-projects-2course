#include "FunctionForMain.h"




void main()
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Cars", sf::Style::Fullscreen);   //окно
	View view;   //камера
	Map map("map.png", 'a');   //карта  

	Car car(sf::Color::Cyan, map, window);
	Car car0(sf::Color::Magenta, map, window);
	Car car1(sf::Color::Magenta, map, window);
	Car car2(sf::Color::White, map, window);
	Car car3(sf::Color::Blue, map, window);
	Car car5(sf::Color::Green, map, window);
	Car car6(sf::Color::Red, map, window);
	Car car7(sf::Color::Magenta, map, window);
	Car car8(sf::Color::Cyan, map, window);
	Car car9(sf::Color::Red, map, window);
	Car car10(sf::Color::Magenta, map, window);
	Car car11(sf::Color::White, map, window);
	Car car12(sf::Color::Blue, map, window);
	Car car13(sf::Color::Green, map, window);
	Car car14(sf::Color::Red, map, window);
	Car car15(sf::Color::Blue, map, window);
	Car car16(sf::Color::Black, map, window);
	Car car17(sf::Color::Green, map, window);
	Car car18(sf::Color::Cyan, map, window);
	Car car19(sf::Color::Red, map, window);
	Car car20(sf::Color::Magenta, map, window);
	Car car21(sf::Color::White, map, window);
	Car car22(sf::Color::Blue, map, window);
	Car car23(sf::Color::Green, map, window);
	Car car24(sf::Color::Red, map, window);
	Car car25(sf::Color::Blue, map, window);
	Car car26(sf::Color::Black, map, window);
	Car car27(sf::Color::Green, map, window);
	Car car28(sf::Color::Cyan, map, window);
	Car car29(sf::Color::Red, map, window);
	Car car30(sf::Color::Magenta, map, window);
	Car car31(sf::Color::White, map, window);
	Car car32(sf::Color::Blue, map, window);
	Car car33(sf::Color::Green, map, window);
	Car car34(sf::Color::Red, map, window);
	Car car35(sf::Color::Blue, map, window);
	Car car36(sf::Color::Black, map, window);
	Car car37(sf::Color::Green, map, window);


	sf::Clock clock;    //часы
	std::pair <int, int> currentClock(0, 0);    //first - текущее время, second - переменная для addCar          
	float time = 0.;

	int num = 2;

	createTrafficLight(window, map);  //создание светофоров

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
		Work(window, map, view, currentClock, time, num);
		window.display();               //вывод в окно
	}	 
}


