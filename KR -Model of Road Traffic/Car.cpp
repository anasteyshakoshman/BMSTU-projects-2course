
#include "Car.h"
#include <math.h>
#include <ctime>
#include "Map.h"
#include "TrafficLight.h"



std::vector<Car> Car::AllCars;

Car::Car(const sf::Color col, const Map &  map, sf::RenderWindow & window)
{
	Image.loadFromFile("images/car0.png");
	Image.createMaskFromColor(sf::Color::White);   //убираем белый фон у спрайта машинки
	Texture.loadFromImage(Image);
	Sprite.setTexture(Texture);
	Sprite.setColor(col);
	Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix)); 
	if (map.getSimvol() == 'a')
	{
		X = 4;
		Y = 3;
	}
	else if (map.getSimvol() == 'b')
	{
		X = 7;
		Y = 7;
	}
	X *= pix;
	Y *= pix;
	Speed = 0.1 * pix; 
	dX = Speed;          
	dY = 0;
	Direction = 0; // 0 (+X), 1 (+Y), 2(-X), 3(-Y)      //   -------------------------------->  X
	Oil = 100.;                                          //   |
	//TLMap = map;                                      //   |                                 
	ChangeDir = false;                                  //   |
	Sprite.setPosition(X, Y);                           //   |
	AllCars.push_back(*this);                           //   \/
	window.draw(Sprite);                                // Y
};




Car::~Car()
{
	X = 0;
	Y = 0;
	dX = 0;
	dY = 0;
	Speed  = 0;
	Direction = 0;
	Oil = 0;
};


const int Car::getX() const
{
	return X;
};

const int Car::getY() const
{
	return Y;
};



const int Car::mX() const         //  (mapX) перевод координат в доступные для подстановки в карту
{
	int x = X;
	if (x % pix == 0) return x / pix;
	else
	{
		int ost = x;
		while (ost > pix) ost -= pix;
		if (Direction == 0 || Direction == 1) return (x - ost) / pix;   //floor    если направление положительное, округляем в меньшую сторону
		if (Direction == 2 || Direction == 3) return (x - ost + pix) / pix;   //ceil       если направление отрицательно,  в большую
	}
};

const int Car::mY() const               //тот же mX(), только для Y
{
	int y = Y;
	if (y % pix == 0) return y / pix;
	else
	{
		int ost = y;
		while (ost > pix) ost -= pix;
		if (Direction == 0 || Direction == 1) return (y - ost) / pix;   //floor
		if (Direction == 2 || Direction == 3) return (y - ost + pix) / pix;   //ceil
	}
};

const int Car::mdX() const      // возвращает либо 1, либо - 1, либо 0
{          
	return dX / Speed;
};

const int Car::mdY() const
{
	return dY / Speed;
};

bool Car::operator !=(const Car & other) 
{
	return Color == other.Color && X == other.X && Y == other.Y && Direction == other.Direction;
};


const bool Car::nextCar(const int dx, const int dy, const Map & TLMap) const   //чтобы машинки не врезались
{                                                                              // вызывается в след. методе chageDirection
	int interval = 0;
	if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p')  interval = 10;
	for (auto it = AllCars.begin(); it != AllCars.end(); ++it )
	{
		if ((X + dx * interval + dx/Speed * pix) == it->getX() && (Y + dy * interval + dy/Speed * pix) == it->getY()) return false;
	}
	return true;  
};


bool Car::changeCoordinate(const int direct, const Map & map)   //смена направления машинки
{
	bool change = false;
	if (Direction != direct)    
	{
		if (!direct && nextCar(Speed, 0, map))   //заодно идет проверка : нет ли впереди машины
		{                                         //если есть, то данная машина не должна ехать (возвращаем change = false)
			dX = Speed;                           // и затем в методе go не произойдеt  приращение координат (X += dX)
			dY = 0;
			change = true;
			Image.loadFromFile("images/car0.png");
		}
		if (direct == 1 && nextCar(0, Speed, map))
		{
			dX = 0;
			dY = Speed;
			change = true;
			Image.loadFromFile("images/car1.png");
		}
		if (direct == 2 && nextCar(-Speed, 0, map))
		{
			dX = -Speed;
			dY = 0;
			change = true;
			Image.loadFromFile("images/car2.png");
		}
		if (direct == 3 && nextCar(0, -Speed, map))
		{
			dX = 0;
			dY = -Speed;
			change = true;
			Image.loadFromFile("images/car3.png");
		}
		if (change)
		{
			Image.createMaskFromColor(sf::Color::White);   //убираем белый фон у спрайта машинки
			Texture.loadFromImage(Image);
			Sprite.setTexture(Texture);
			Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix));
			Direction = direct;
			ChangeDir = true;               //если машинка поменяла направление, то она не может его еще раз поменять, пока не уедет с данного перекрестка
		}
		return change;
	}	
	else return nextCar(dX, dY, map);
};





const std::vector<int> Car::freeDirections(const Map &  TLMap) const  //возвращает вектор возможных свободных напрвлений
{                                                                     // вызывается в методе go (в котором уже рандомно выбирается одно из свободных направлений)

//	if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'r' || \                         //неудавшаяся попытка систематизировать поиск направлений и избавится от switch
//		TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && \
//(TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p' || \
//		TLMap.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'r' || \
//		TLMap.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'))\
//		vec.push_back(Direction);
//
//	if (TLMap.getTM()[mY() + mdX() * pow(-1, Direction)][mX() + mdY() * pow(-1, Direction)] == 'r' && \
//		TLMap.getTM()[mY() + mdY() + mdX()][mX() + mdX() * pow(-1, Direction) + mdY() * pow(-1, Direction)] == 'r' && !ChangeDir)
//		vec.push_back((Direction + 1) % 4);
//
//	if (TLMap.getTM()[mY() - 2 * mdX() * pow(-1, Direction)][mX() - 2 * mdY() * pow(-1, Direction)] == 'r' &&\
//		TLMap.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'&& !ChangeDir)
//		vec.push_back((Direction + 3) % 4);


	std::vector<int> vec;
	/*if (X % pix != 0 && Y % pix != 0)
	{
		vec.push_back(Direction);
	}
	else
	{*/
		switch (Direction)
		{
		case 0:
		{
				  if (TLMap.getTM()[mY()][mX() + 1] == 'r' || \
					  TLMap.getTM()[mY()][mX() + 1] == 'p' && (TLMap.getTM()[mY()][mX() + 2] == 'p' || \
					  TLMap.getTM()[mY()][mX() + 2] == 'r' || TLMap.getTM()[mY() - 2][mX() + 1] == 'r'))\
					  vec.push_back(0);
				  if (TLMap.getTM()[mY() + 1][mX()] == 'r' && TLMap.getTM()[mY() + 1][mX() + 1] == 'r' && !ChangeDir) vec.push_back(1);
				  if (TLMap.getTM()[mY() - 2][mX()] == 'r' && TLMap.getTM()[mY() - 2][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  break;
		}
		case 1:
		{
				  if (TLMap.getTM()[mY() + 1][mX()] == 'r' || \
					  TLMap.getTM()[mY() + 1][mX()] == 'p' && (TLMap.getTM()[mY() + 2][mX()] == 'p' || \
					  TLMap.getTM()[mY() + 2][mX()] == 'r' || TLMap.getTM()[mY() + 1][mX() + 2] == 'r'))\
					  vec.push_back(1);
				  if (TLMap.getTM()[mY()][mX() - 1] == 'r' && TLMap.getTM()[mY() + 1][mX() - 1] == 'r' && !ChangeDir) vec.push_back(2);
				  if (TLMap.getTM()[mY()][mX() + 2] == 'r' && TLMap.getTM()[mY() - 1][mX() + 2] == 'r'&& !ChangeDir) vec.push_back(0);
				  break;
		}
		case 2:
		{
				  if (TLMap.getTM()[mY()][mX() - 1] == 'r' || \
					  TLMap.getTM()[mY()][mX() - 1] == 'p' && (TLMap.getTM()[mY()][mX() - 2] == 'p' || \
					  TLMap.getTM()[mY()][mX() - 2] == 'r' || TLMap.getTM()[mY() + 2][mX() - 1] == 'r'))\
					  vec.push_back(2);
				  if (TLMap.getTM()[mY() - 1][mX()] == 'r' && TLMap.getTM()[mY() - 1][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  if (TLMap.getTM()[mY() + 2][mX()] == 'r' && TLMap.getTM()[mY() + 2][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(1);
				  break;
		}
		case 3:
		{
				  if (TLMap.getTM()[mY() - 1][mX()] == 'r' || \
					  TLMap.getTM()[mY() - 1][mX()] == 'p' && (TLMap.getTM()[mY() - 2][mX()] == 'p' || \
					  TLMap.getTM()[mY() - 2][mX()] == 'r' || TLMap.getTM()[mY() - 1][mX() - 2] == 'r'))\
					  vec.push_back(3);
				  if (TLMap.getTM()[mY()][mX() + 1] == 'r' && TLMap.getTM()[mY() - 1][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(0);
				  if (TLMap.getTM()[mY()][mX() - 2] == 'r' && TLMap.getTM()[mY() + 1][mX() - 2] == 'r'&& !ChangeDir) vec.push_back(2);
				  break;
		}
		}
	/*}	*/
	return vec;
}



bool Car::lightAround(const Map & TLMap) const      //проверка на светофоры
{                                              
	int koef = 1;
	if (Direction == 1 || Direction == 3) koef = -1;
	
	if (TLMap.getTM()[mY() + mdY()][mX() + mdX()] == 'p')   //чтобы реагировала только на светофор, предназначающийся ей (т.е., стоящий перед перекрестком)
	{
		for (auto it = TrafficLight::AllTrafficLight.begin(); it != TrafficLight::AllTrafficLight.end(); ++it)
		{
			if (mX() + koef * mdY() == it->getX()  && mY() + koef * mdX() == it->getY() && it->getColor() == sf::Color::Red) 
				return false;
		}  
	}	
	return true;
}


void Car::go(sf::RenderWindow & window, const Map &  TLMap)         //основной метод движения 
{
	if (TLMap.getTM()[mY()][mX()] == 'r' && ChangeDir)  ChangeDir = false;      // как только машинка уехала с перекрестка, на котором поменяла направление
	srand(time(0));                                                            // (т.е. выехала на 'r'), она снова может его менять
	std::vector<int> freeDir;
	if (lightAround(TLMap)) freeDir = freeDirections(TLMap);     //проверяем светофор, если есть и красный, то freedir будет пустым, и приращение X (Y) не произойдет
	if (freeDir.size())
	{		
			int random = rand() % freeDir.size();          //random имеет диапозон от 0 до кол-ва свободных направлений
			if (changeCoordinate(freeDir[random], TLMap))     //движемся, если впереди нет машины
			{
						X += dX;
						Y += dY;
						Sprite.move(dX, dY);
						Oil -= 0.00000000001;
			}
	}	
	window.draw(Sprite);     // вне зависимости от того, двигалась ли машина, рисуем ее
}
