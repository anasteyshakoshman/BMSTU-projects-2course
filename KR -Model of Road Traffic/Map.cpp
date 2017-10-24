#include "Map.h"
Map::Map(const sf::String file)
{
	Texture.loadFromFile("images/" + file);
	Sprite.setTexture(Texture);
	Height = 48;
	Weight = 80;
	TileMap =
	{
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
		"00pprrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrpprrrrrrrrrrrrrrrrrrpprrrrrrrrrpprrrrpp00",
		"00pprrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrpprrrrrrrrrrrrrrrrrrpprrrrrrrrrpprrrrpp00",
		"00rr         f                rr       rr       f          rr        srrs   rr00",
		"00rr                          rr    f  pprrrrpp   hl  f    pprrrrrrrrrpprrrrpp00",
		"00rr  hlrrrrrrrrpp    pprrrrrrpp  hl   pprrrrpp   mn       pprrrrrrrrrpprrrrpp00",
		"00rr  mnrrrrrrrrpp    pprrrrrrpp  mn         rr            rr        srrs   rr00",
		"00rr          f rr    rr      rr             pprrrrrrrrrrrrpp         rr    rr00",
		"00rr    f       pprrrrpp      pprrrrrrpp  f  pprrrrrrrrrrrrpp   pprrrrpprrrrpp00",
		"00rr            pprrrrpp f    pprrrrrrpp     rr     hl          pprrrrpprrrrpp00",
		"00rr     ff     rr        hl          rr     rr     mn f        rr          rr00",
		"00rr   f        rr        mn     f   srrs    rr                 rr   hl     rr00",
		"00rr        pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrrrrrrpprrpp   mn     rr00",
		"00rr      f pprrpprrrrpp     f pprrrrrpprrrrrpprrrrrrrrrrrrrpprrpp          rr00",
		"00rr        rr        rr       rr    srrs          hl f     rr     f        rr00",
		"00rr        rr        pprrrrrrrpp     rr           mn pprrrrpprrrrrpp   hl  rr00",
		"00pprrrrrrrrpp        pprrrrrrrpp     pprrrrrrpp      pprrrrpprrrrrpp   mn  rr00",
		"00pprrrrrrrrpp     f        f  rr     pprrrrrrpp      rr           rr       rr00",
		"00rr                  pprrrrrrrpp    f        rr      rr       f  srrs      rr00",
		"00rr                  pprrrrrrrpp         hl  rr    f pprrrrrrrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrrrrrrpp   rr              f   mn  rr      pprrrrrrrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrrrrrrpp   rr  hl             f   srrs     rr          srrs      rr00",
		"00rr        f    rr   rr  mn  f    hl   pprrrrpprrrrrrpp     f     rr       rr00",
		"00rr    hl   pprrpprrrpp           mn   pprrrrpprrrrrrpp           rr       rr00",
		"00rr    mn   pprrpprrrpp                rr   srrs     rr           rr       rr00",
		"00rr         rr       rr      pprrrrrrrrpprrrrpp      pprrrpprrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrrpprpp    rr      pprrrrrrrrpprrrrpp      pprrrpprrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrrpprpp    rr      rr              rr           rr               rr00",
		"00rr          f rr    rr      pprrrrrrpp      rr           pprrrpprrrrrrrrrrpp00",
		"00rr     f      rr    rr      pprrrrrrpp      rr       f   pprrrpprrrrrrrrrrpp00",
		"00rr   f        rr f  rr         f   srrs     rr                rr    hl    rr00",
		"00rr        pprrpprrrrpp       pprrrrrpprrrrrrpprrrrrrrrrrrrpprrpp    mn    rr00",
		"00rr   hl   pprrpprrrrpp     f pprrrrrpprrrrrrpprrrrrrrrrrrrpprrpp          rr00",
		"00rr   mn   rr        rr       rr    srrs  f         f      rr     f        rr00",
		"00rr        rr        pprrrrrrrpp     rr              pprrrrpprrrrrpp   hl  rr00",
		"00pprrrrrrrrpp        pprrrrrrrpp     pprrrrrrpp   f  pprrrrpprrrrrpp   mn  rr00",
		"00pprrrrrrrrpp     f        f  rr     pprrrrrrpp      rr           rr       rr00",
		"00rr       frr   pprrrrrrrrrrrrpp    f       srrs     rr         f rr       rr00",
		"00rr        rr   pprrrrrrrrrrrrpp     pprrrrrrpprrrrrrpprrrrrrrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrpp   rr             f     pprrrrrrpprrrrrrpprrrrrrrrrrrpprrrrrrrpp00",
		"00pprrrrrrrrpp   rr       hl             f   srrs     rr    rr              rr00",
		"00rr        f    rr       mn  f       f       rr      rr    rr       hl     rr00",
		"00rr   f         rr                           rr      rr    rr       mn     rr00",
		"00pprrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp00",
		"00pprrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp00",
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
		"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
	};
};


int Map::getHeight() const
{
	return Height;
}

int Map::getWeight() const
{
	return Weight;
}


void Map::draw(sf::RenderWindow & window)
{
	for (int i = 0; i < Height; ++i)
	{
		for (int j = 0; j < Weight; ++j)
		{
			switch (TileMap[i][j])
			{
			case '0':
			{
						Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
						break;
			}
			case 'r':
			{
						Sprite.setTextureRect(sf::IntRect(120, 0, 120, 120));
						break;
			}
			case 'p':
			{
						Sprite.setTextureRect(sf::IntRect(120, 0, 120, 120));
						break;
			}
			case 'h':
			{
						Sprite.setTextureRect(sf::IntRect(360, 120, 120, 120));
						break;
			}
			case 'l':
			{
						Sprite.setTextureRect(sf::IntRect(480, 120, 120, 120));
						break;
			}
			case 'm':
			{
						Sprite.setTextureRect(sf::IntRect(360, 240, 120, 120));
						break;
			}
			case 'n':
			{
						Sprite.setTextureRect(sf::IntRect(480, 240, 120, 120));
						break;
			}
			default:
			{
						Sprite.setTextureRect(sf::IntRect(240, 0, 120, 120));
						break;
			}
			}
			Sprite.setPosition(j * 120, i * 120);
			window.draw(Sprite);
		}
	}
};

Map & Map::operator =(const Map & other)
{
	if (&other != this)
	{
		this->Height = other.Height;
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


