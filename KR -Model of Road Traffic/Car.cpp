
#include "Car.h"
#include <math.h>
#include <ctime>
#include "Map.h"
#include "TrafficLight.h"
#include "RoadSign.h"
#include "Crash.h"

std::vector<Car> Car::AllCars;

Car::Car(const sf::Texture & texture, const sf::Color col, const Map &  map, sf::RenderWindow & window)
{
	Sprite.setTexture(texture);
	Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix)); 
	Sprite.setColor(col);
	int random = rand() % 2;
	if (map.getSimvol() == 'a' || map.getSimvol() == 'c' || map.getSimvol() == 'd' || map.getSimvol() == 'e')
	{
		X = pix;
		if (!random || map.getSimvol() == 'e') Y = 3 * pix;
		else if(map.getSimvol() == 'c' ) Y =  9 * pix;
		else Y = 11 * pix;
	}
	else if (map.getSimvol() == 'b')
	{
		if (!random)
		{
			X = 7 * pix;
			Y = 7 * pix;
		}
		else
		{
			X = pix;
			Y = 28 * pix;
		}		
	}
	if (!random) Speed = 0.025 * pix;
	else Speed = 0.05 * pix;
	dX = Speed;
	dY = 0;
	Direction = 0;                                 // 0 (+X), 1 (+Y), 2(-X), 3(-Y)     
	Oil = 100.;                                         
	ChangeDir = false;                                  
	Sprite.setPosition(X, Y);   
	Life = true;
	AllCars.push_back(*this);                         
	window.draw(Sprite);                               
};


Car::Car(const sf::Texture & texture, const sf::Color col, const Map &  map, sf::RenderWindow & window, const int x, const int y, const int direction)
{
	Sprite.setTexture(texture);
	Sprite.setColor(col);
	X = x * pix;
	Y = y * pix;
	Speed = 0.025 * pix;
	dX = Speed;
	dY = 0;
	Direction = direction;                         // 0 (+X), 1 (+Y), 2(-X), 3(-Y)      
	Oil = 100.;                                                                                                  
	ChangeDir = false;                                 
	Sprite.setPosition(X, Y);  
	if(!Direction) Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix));
	else if (Direction == 1) Sprite.setTextureRect(sf::IntRect(pix, 0, pix, pix));
	else if (Direction == 2) Sprite.setTextureRect(sf::IntRect(0, pix, pix, pix));
	else Sprite.setTextureRect(sf::IntRect(pix, pix, pix, pix));
	Life = true;
	AllCars.push_back(*this);                           
	window.draw(Sprite);                               
};





int Car::getSpeed() const
{
	return Speed;
}

int Car::okrugl(const int xy) const
{
	if (xy % pix == 0) return xy;
	int ost = xy;
	while (ost > pix) ost -= pix;
	if (Direction == 0 || Direction == 1) return xy - ost;   //floor
	if (Direction == 2 || Direction == 3) return xy - ost + pix;    //ceil
}


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


int Car::getX() const
{
	return X;
};

int Car::getY() const
{
	return Y;
};

bool Car::getLife() const
{
	return Life;
}

int Car::mX() const         //  (mapX) перевод координат в доступные для подстановки в карту
{
	 return X / pix;
};

int Car::mY() const               //тот же mX(), только для Y
{
	 return Y / pix;
};

int Car::mdX() const      // возвращает либо 1, либо - 1, либо 0
{          
	return dX / Speed;
};

int Car::mdY() const
{
	return dY / Speed;
};







void Car::changeDirection(const int direct)   //смена направления машинки
{
	if (!direct)   
	{
		dX = Speed;                       
		dY = 0;
		Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix));
	}
	if (direct == 1)
	{
		dX = 0;
		dY = Speed;
     	Sprite.setTextureRect(sf::IntRect(pix, 0, pix, pix));
	}
	if (direct == 2)
	{
		dX = -Speed;
		dY = 0;
		Sprite.setTextureRect(sf::IntRect(0, pix, pix, pix));
	}
	if (direct == 3)
	{
		dX = 0;
		dY = -Speed;
		Sprite.setTextureRect(sf::IntRect(pix, pix, pix, pix));
	}
		Direction = direct;
		ChangeDir = true;               //если машинка поменяла направление, то она не может его еще раз поменять, пока не уедет с данного перекрестка
};





std::vector<int> Car::freeDirections(const Map &  map) const  //возвращает вектор возможных свободных напрвлений
{                                                                     // вызывается в методе go (в котором уже рандомно выбирается одно из свободных направлений)

//	if (map.getTM()[mY() + mdY()][mX() + mdX()] == 'r' || \                         //неудавшаяся попытка систематизировать поиск направлений и избавится от switch
//		map.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && \
//(map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'p' || \
//		map.getTM()[mY() + 2 * mdY()][mX() + 2 * mdX()] == 'r' || \
//		map.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'))\
//		vec.push_back(Direction);
//
//	if (map.getTM()[mY() + mdX() * pow(-1, Direction)][mX() + mdY() * pow(-1, Direction)] == 'r' && \
//		map.getTM()[mY() + mdY() + mdX()][mX() + mdX() * pow(-1, Direction) + mdY() * pow(-1, Direction)] == 'r' && !ChangeDir)
//		vec.push_back((Direction + 1) % 4);
//
//	if (map.getTM()[mY() - 2 * mdX() * pow(-1, Direction)][mX() - 2 * mdY() * pow(-1, Direction)] == 'r' &&\
//		map.getTM()[mY() + mdY() - 2 * mdX() * pow(-1, Direction)][mX() + mdX() - 2 * mdY() * pow(-1, Direction)] == 'r'&& !ChangeDir)
//		vec.push_back((Direction + 3) % 4);


	std::vector<int> vec;
	if (X % pix == 0 && Y % pix == 0)
	{
		switch (Direction)
		{
		case 0:
		{
				  if (map.getTM()[mY()][mX() + 1] == 'r' || \
					  map.getTM()[mY()][mX() + 1] == 'p' && (map.getTM()[mY()][mX() + 2] == 'p' || \
					  map.getTM()[mY()][mX() + 2] == 'r' || map.getTM()[mY() - 2][mX() + 1] == 'r'))\
					  vec.push_back(0);
				  if (map.getTM()[mY() + 1][mX()] == 'r' && map.getTM()[mY() + 1][mX() + 1] == 'r' && !ChangeDir) vec.push_back(1);
				  if (map.getTM()[mY() - 2][mX()] == 'r' && map.getTM()[mY() - 2][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  break;
		}
		case 1:
		{
				  if (map.getTM()[mY() + 1][mX()] == 'r' || \
					  map.getTM()[mY() + 1][mX()] == 'p' && (map.getTM()[mY() + 2][mX()] == 'p' || \
					  map.getTM()[mY() + 2][mX()] == 'r' || map.getTM()[mY() + 1][mX() + 2] == 'r'))\
					  vec.push_back(1);
				  if (map.getTM()[mY()][mX() - 1] == 'r' && map.getTM()[mY() + 1][mX() - 1] == 'r' && !ChangeDir) vec.push_back(2);
				  if (map.getTM()[mY()][mX() + 2] == 'r' && map.getTM()[mY() - 1][mX() + 2] == 'r'&& !ChangeDir) vec.push_back(0);
				  break;
		}
		case 2:
		{
				  if (map.getTM()[mY()][mX() - 1] == 'r' || \
					  map.getTM()[mY()][mX() - 1] == 'p' && (map.getTM()[mY()][mX() - 2] == 'p' || \
					  map.getTM()[mY()][mX() - 2] == 'r' || map.getTM()[mY() + 2][mX() - 1] == 'r'))\
					  vec.push_back(2);
				  if (map.getTM()[mY() - 1][mX()] == 'r' && map.getTM()[mY() - 1][mX() - 1] == 'r'&& !ChangeDir) vec.push_back(3);
				  if (map.getTM()[mY() + 2][mX()] == 'r' && map.getTM()[mY() + 2][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(1);
				  break;
		}
		case 3:
		{
				  if (map.getTM()[mY() - 1][mX()] == 'r' || \
					  map.getTM()[mY() - 1][mX()] == 'p' && (map.getTM()[mY() - 2][mX()] == 'p' || \
					  map.getTM()[mY() - 2][mX()] == 'r' || map.getTM()[mY() - 1][mX() - 2] == 'r'))\
					  vec.push_back(3);
				  if (map.getTM()[mY()][mX() + 1] == 'r' && map.getTM()[mY() - 1][mX() + 1] == 'r'&& !ChangeDir) vec.push_back(0);
				  if (map.getTM()[mY()][mX() - 2] == 'r' && map.getTM()[mY() + 1][mX() - 2] == 'r'&& !ChangeDir) vec.push_back(2);
				  break;
		}
		}
	}	
	else vec.push_back(Direction);
	return vec;
}



int Car::nextCar(const Map & map, const bool crash) const   //чтобы машинки не врезались
{   
	for (int i = 0; i < AllCars.size(); ++i)
	{
		if ((X + mdX() * pix) == AllCars[i].X && (Y + mdY() * pix) == AllCars[i].Y)
		{
			if (crash) return i;
			else return -1;
		}
		else if ((Direction == 0 || Direction == 2) && X + mdX() * pix == AllCars[i].X && mod(Y - AllCars[i].Y) < pix)
		{
			if (crash) return i;
			else return -1;
		}
		else if ((Direction == 1 || Direction == 3) && Y + mdY() * pix == AllCars[i].Y && mod(X - AllCars[i].X) < pix)
		{
			if (crash) return i;
			else return -1;
		}
	}
	return -2;
	
};

int Car::mod(const int num) const
{
	return sqrt(num * num);
}

void Car::changeSpeed(const int newSpeed)
{
	if (Speed != newSpeed)
	{
		Speed = newSpeed;
		if (dX < 0) dX = -Speed;
		else if(dX > 0) dX = Speed;
		if (dY < 0) dY = -Speed;
		else if(dY > 0) dY = Speed;
	}
}

bool Car::lightAround(const Map & map) const      //проверка на светофоры
{                                              
	if (map.getTM()[mY() + mdY()][mX() + mdX()] == 'p' && X % 120 == 0 && Y % 120 == 0)   //чтобы реагировала только на светофор, предназначающийся ей (т.е., стоящий перед перекрестком)
	{
		int koef = 1;
		if (Direction == 1 || Direction == 3) koef = -1;
		for (auto it = TrafficLight::Vec().begin(); it != TrafficLight::Vec().end(); ++it)
		{
			if (mX() + koef * mdY() == it->getX()  && mY() + koef * mdX() == it->getY() && (it->getColor() == sf::Color::Red || it->getColor() == sf::Color::Yellow)) 
				return false;
		}  
	}	
	return true;
}

void Car::signAround(const Map & map)
{
	if (X % 120 == 0 && Y % 120 == 0)
	{
		int koef = 1;
		if (Direction == 1 || Direction == 3) koef = -1;
		for (auto it = RoadSign::Vec().begin(); it != RoadSign::Vec().end(); ++it)
		{
			if (mX() + koef * mdY() == it->getX() && mY() + koef * mdX() == it->getY())
			{
				changeSpeed(it->getLimit());
			}
		}
	}	
}


bool Car::crashAround()
{
	if (X % pix == 0 && Y % pix == 0)
	{
		for (auto it = Crash::Vec().begin(); it != Crash::Vec().end(); ++it)
		{
			if ((X + mdX() * pix == it->getX1() && Y + mdY() * pix == it->getY1()) || (X + mdX() * pix == it->getX2() && Y + mdY() * pix == it->getY2()))
				return false;
		}
	}
	return true;
}


std::vector<Car> & Car::Vec()
{
	return AllCars;
}


void Car::go(sf::RenderWindow & window, const Map &  map, const bool crash)         //основной метод движения 
{
	std::vector<int> freeDir;
	bool change = false;
	int motion = -1;
	srand(time(0));

    if (map.getTM()[mY()][mX()] == 'r' && ChangeDir)  ChangeDir = false;      // как только машинка уехала с перекрестка, на котором поменяла направление // (т.е. выехала на 'r'), она снова может его менять
    signAround(map);                                        //проверка на знаки
	if (lightAround(map)) freeDir = freeDirections(map);     //проверяем светофор, если есть и красный, то freedir будет пустым, и приращение X (Y) не произойдет
	if (freeDir.size())
	{
			int random = rand() % freeDir.size();          //random имеет диапозон от 1 до кол-ва свободных направлений
			if (Direction != freeDir[random])
			{
				changeDirection(freeDir[random]);
				change = true;
			}
			if (!change)
			{
				motion = nextCar(map, crash); 
				if (motion != -1 && Life && crashAround())                   //если перед машиной нет другой машины или если возможная авария
				{
					X += dX;
					Y += dY;
					Sprite.setPosition(X, Y);
					Oil -= 0.00000000001;
				}
			}			
			if (motion > -1)	
			{
				Crash(window, okrugl(X), okrugl(Y), okrugl(AllCars[motion].X), okrugl(AllCars[motion].Y));
				Life = false;
				AllCars[motion].Life = false;
			}
	}	
	 window.draw(Sprite);     // вне зависимости от того, двигалась ли машина, рисуем ее (не рисуем только если произошла авария)
}
