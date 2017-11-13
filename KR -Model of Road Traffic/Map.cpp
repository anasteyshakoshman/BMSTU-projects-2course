#include "Map.h"
#include "RoadSign.h"

Map::Map(const sf::String file, const char simvol)
{
	Texture.loadFromFile("images/" + file);
	Sprite.setTexture(Texture);
	if (simvol == 'a')
	{
		Height = 14;
		Weight = 26;
		TileMap =
		{
			"00000000000000000000000000",
			"0                        0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0rpprrrrrrpprrrrrrrrrrpp 0",
			"0 rr      rr          rr 0",
			"0 rr     srrs         rr 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0 rr     srrs     rr  rr 0",
			"0 rr      rr      rr  rr 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0rpprrrrrrpprrrrrrpprrpp 0",
			"0                        0",
			"00000000000000000000000000"
		};
	}
	else if (simvol == 'b')
	{
		Height = 48;
		Weight = 80;

		TileMap =
		{
			"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
			"0                                                                              0",
			"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
			"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
			"0 rr            rr            rr       rr    rr                       rr    rr 0",
			"0 rr           srrs           rr       rr    rr   hlpprrrrrrrrrrpp    rr    rr 0",
			"0 rr hl pprrrrrrpprrrrpprrrrrrpp  hl   pprrrrpp   mnpprrrrrrrrrrpp    rr    rr 0",
			"0 rr mnrpprrrrrrpprrrrpprrrrrrpp  mn   pprrrrpp     rr          rr    rr    rr 0",
			"0 rr    rr     srrs   rr      rr             rr     rr         srrs   rr    rr 0",
			"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
			"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
			"0 rr    rr      rr    rr  hl          rr     rr     hl         srrs         rr 0",
			"0 pprrrrpp      rr    rr  mn         srrs    rr     mn          rr   hl     rr 0",
			"0 pprrrrpp  pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp   mn     rr 0",
			"0 rr        pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp          rr 0",
			"0 rr        rr        rr       rr    srrs          hl  rr                   rr 0",
			"0 rr       srrs      srrs      rr     rr           mn  rr  pprrrrrrpp   hl  rr 0",
			"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  pprrrrrrpp   mn  rr 0",
			"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  rr      rr       rr 0",
			"0 rr       srrs      srrs      rr             rr           rr     srrs      rr 0",
			"0 rr        rr        rr       rr         hl  rr           pprrrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpprrpprrrrpprrrpprrpp         mn  rr           pprrrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpprrpprrrrpprrrpprrpp            srrs                 srrs      rr 0",
			"0 rr            rr         rr      hl pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
			"0 rr    hl      rr         rr      mn pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
			"0 rr    mn      rr         rr         rr     srrs     rr   rr      rr       rr 0",
			"0 rr            rr         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
			"0 pprrrrrrrrrrrrpp         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
			"0rpprrrrrrrrrrrrpp         rr         rr      rr      rr                    rr 0",
			"0 rr            rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
			"0 rr            rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
			"0 rr            rr         rr        srrs     rr      rr              hl    rr 0",
			"0 rr        pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr              mn    rr 0",
			"0 rr   hl   pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr                    rr 0",
			"0 rr   mn   rr        rr       rr    srrs     rr      rr                    rr 0",
			"0 rr        rr        rr       rr     rr      rr      pprrrrrrrrrrrpp   hl  rr 0",
			"0 pprrrrrrrrpp        rr       rr     rr      rr      pprrrrrrrrrrrpp   mn  rr 0",
			"0 pprrrrrrrrpp        rr       rr     rr      rr      rr           rr       rr 0",
			"0 rr        rr   pprrrpprrrrrrrpp     rr     srrs    srrs          rr       rr 0",
			"0 rr        rr   pprrrpprrrrrrrpp     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpp   rr            rr     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpp   rr       hl   rr     rr     srrs    srrs   rr              rr 0",
			"0 rr        rr   rr       mn   rr     rr      rr      rr    rr       hl     rr 0",
			"0 rr        rr   rr            rr     rr      rr      rr    rr       mn     rr 0",
			"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
			"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
			"0                                                                              0",
			"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
		};

	}
	else if (simvol == 'd')
	{
		Weight = 26;
		Height = 21;
		TileMap =
		{
			"00000000000000000000000000",
			"0      y            k    0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0rpprrrrrrpprrrrrrrrrrpp 0",
			"0 rr  y   rr       k  rr 0",
			"0 rr     srrs    y    rr 0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0 rr  y  srrs     y   rr 0",
			"0 rr   y  rr      k   rr 0",
			"0 pprrrrrrpprrpprrrrrrpp 0",
			"0rpprrrrrrpprrpprrrrrrpp 0",
			"0 rr          rr   n  rr 0",
			"0 rr    k    srrs     rr 0",
			"0 pprrrrrrrrrrpprrrrrrpp 0",
			"0 pprrrrrrrrrrpprrrrrrpp 0",
			"0 rr    y    srrs     rr 0",
			"0 rr      y   rr  k   rr 0",
			"0 pprrrrrrrrrrpprrrrrrpp 0",
			"0rpprrrrrrrrrrpprrrrrrpp 0",
			"0     k             y    0",
			"00000000000000000000000000"
		};
	}
	else if (simvol == 'c')
	{
		Weight = 26;
		Height = 11;
		TileMap =
		{
			"00000000000000000000000000",
			"0         y              0",
			"0 pprrrrrrrrrrrrrrrrrrpp 0",
			"0rpprrrrrrrrrrrrrrrrrrpp 0",
			"0 rr       y          rr 0",
			"0krr                  rrk0",
			"0 rrk                krr 0",
			"0 rr       y          rr 0",
			"0 pprrrrrrrrrrrrrrrrrrpp 0",
			"0rpprrrrrrrrrrrrrrrrrrpp 0",
			"0             y          0",
			"00000000000000000000000000"
		};
	}
	Simvol = simvol;
	
};


Map::Map(Map & other)
{
	Texture =  other.Texture;
	Sprite =  other.Sprite;
	TileMap = other.TileMap;
	Height = other.Height;
	Weight = other.Weight;
	Simvol = other.Simvol;
}


char Map::getSimvol() const
{
	return Simvol;
}


int Map::getHeight() const
{
	return Height;
}

int Map::getWeight() const
{
	return Weight;
}


void Map::draw(sf::RenderWindow & window)   //заполнение карты в зависимости от char
{
	int x = 0, y = 0;
	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Weight; ++j)
		{
			

			switch (TileMap[i][j])
			{
			case '0':
			{
						Sprite.setTextureRect(sf::IntRect(0, 0, pix, pix));
						break;
			}
			case 'r':
			{
						Sprite.setTextureRect(sf::IntRect(pix, 0, pix, pix));
						break;
			}
			case 'p':
			{
						Sprite.setTextureRect(sf::IntRect(pix, 0, pix, pix));
						break;
			}
			case 'h':
			{
						Sprite.setTextureRect(sf::IntRect(3 * pix, pix, pix, pix));
						break;
			}
			case 'l':
			{
						Sprite.setTextureRect(sf::IntRect(4 * pix, pix, pix, pix));
						break;
			}
			case 'm':
			{
						Sprite.setTextureRect(sf::IntRect(3 * pix, 2 * pix, pix, pix));
						break;
			}
			case 'n':
			{
						Sprite.setTextureRect(sf::IntRect(4 * pix, 2 * pix, pix, pix));
						break;
			}
			case ' ':
			{
						Sprite.setTextureRect(sf::IntRect(2 * pix, 0, pix, pix));
						break;
			}
			case 's':
			{
						Sprite.setTextureRect(sf::IntRect(2 * pix, 0, pix, pix));
						break;
			}
			default:
			{
					   CreateRoadSign(i, j);
			}
			}
			Sprite.setPosition(j * pix, i * pix);
			window.draw(Sprite);
		}
	}
};

sf::Sprite Map::getSprite()
{
	return Sprite;
}

void Map::CreateRoadSign(const int y, const int x)
{
	int poz_x = 5 * pix, poz_y = 0, limit = 60;
	if (x <= Weight - 2)  //direction = 1
	{
		if (TileMap[y][x + 1] == 'r' && TileMap[y][x + 2] == 'r')
			poz_x += pix;
	}
	if (y <= Height - 2)   //direction = 2
	{
		if (TileMap[y + 1][x] == 'r' && TileMap[y + 2][x] == 'r')
			poz_x += 2 * pix;
	}
	if (x >= 2)                                                          //direction = 3
	{
		if (TileMap[y][x - 1] == 'r' && TileMap[y][x - 2] == 'r')
			poz_x += 3 * pix;
	}
	if (TileMap[y][x] == 'y') poz_y += pix;
	Sprite.setTextureRect(sf::IntRect(poz_x, poz_y, pix, pix));
}

Map & Map::operator =(const Map & other)
{
	if (&other != this)
	{
		Height = other.Height;
		Weight = other.Weight;
		TileMap = other.TileMap;
		Texture = other.Texture;
		Sprite = other.Sprite;
	}
	return *this;
};

Map::~Map()
{
	TileMap.clear();
};




std::vector<std::string>  Map::getTM() const
{
	return TileMap;
};


