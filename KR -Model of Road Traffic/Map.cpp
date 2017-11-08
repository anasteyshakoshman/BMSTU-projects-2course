#include "Map.h"
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
			"0           s            0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0 pprrrrrrpprrrrrrrrrrpp 0",
			"0 rr     srrs         rr 0",
			"0srrs    srrs       ssrr 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0 rrs    srrs    srrssrrs0",
			"0 rr     srrs    srrs rr 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0 pprrrrrrpprrrrrrpprrpp 0",
			"0        s       s       0",
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
			"0                 s             s        s     s                        s      0",
			"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
			"0 pprrrrrrrrrrrrpprrrrrrrrrrrrpprrrrrrrpprrrrpprrrrrrrrrrrrrrrrrrrrrrrpprrrrpp 0",
			"0 rr           srrs          srrs     srrs  srrs                     srrs   rr 0",
			"0 rr           srrs     s     rr       rr    rr   hlpprrrrrrrrrrpp    rr    rr 0",
			"0 rr hl pprrrrrrpprrrrpprrrrrrpp  hl   pprrrrpp   mnpprrrrrrrrrrpp    rr    rr 0",
			"0 rr mnrpprrrrrrpprrrrpprrrrrrpp  mn   pprrrrpp     rr          rr    rr    rr 0",
			"0 rr    rr     srrs  srrs     rr             rr     rr         srrs  srrs  srr 0",
			"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
			"0 rr    rr      rr    rr      pprrrrrrpp     rr     pprrrrrrrrrrpprrrrpprrrrpp 0",
			"0 rrs   rr      rr    rr  hl          rr     rr     hl         srrs  s     srrs0",
			"0 pprrrrpp     srrs  srr  mn         srrs   srrs    mn   s      rr   hl     rr 0",
			"0 pprrrrpp  pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp   mn     rr 0",
			"0 rrs       pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrpprrrrrrrpp          rr 0",
			"0 rr        rr s     srrs      rr    srrs   s      hl srrs                  rr 0",
			"0srrs      srrs      srrs     srr     rr           mn  rr  pprrrrrrpp   hl  rr 0",
			"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  pprrrrrrpp   mn  rr 0",
			"0 pprrrrrrrrpprrrrrrrrpprrrrrrrpp     pprrrrrrpprrrrrrrpp  rr      rr       rr 0",
			"0 rrs      srrs      srr      srrs            rr           rr     srrs     srr 0",
			"0srrs      srrs   s  srrs    s rr         hl  rr           pprrrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpprrpprrrrpprrrpprrpp         mn  rr           pprrrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpprrpprrrrpprrrpprrpp            srrs       s         srrs     srrs0",
			"0 rrs      s   srrs  s    srrs     hl pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
			"0 rr    hl      rr         rr      mn pprrrrrrpprrrrrrpprrrpp      rr       rr 0",
			"0 rr    mn      rr         rr        srr     srrs    srrs  rr      rr       rr 0",
			"0srrs           rr         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
			"0 pprrrrrrrrrrrrpp         pprrrrrrrrrpp      rr      rr   pprrrrrrpp       rr 0",
			"0 pprrrrrrrrrrrrpp         rr        srrs     rr     srrs                  srr 0",
			"0 rrs           rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
			"0 rr            rr         rr         rr      rr      pprrrrrrrrrrrrrrrrrrrrpp 0",
			"0 rr           srrs     s  rr        srrs    srrs     rrs             hl   srrs0",
			"0 rr        pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr              mn    rr 0",
			"0 rr   hl   pprrpprrrrpprrrpp  pprrrrrpprrrrrrpp      rr                    rr 0",
			"0 rr   mn   rr s     srrs      rr    srrs    srrs    srrs                   rr 0",
			"0srrs      srr        rr       rr     rr      rr      pprrrrrrrrrrrpp   hl  rr 0",
			"0 pprrrrrrrrpp        rr       rr     rr      rr      pprrrrrrrrrrrpp   mn  rr 0",
			"0 pprrrrrrrrpp       srrs     srr     rr      rr      rrs          rr       rr 0",
			"0 rrs      srrs  pprrrpprrrrrrrpp    srrs    srrs    srrs     s   srrs     srr 0",
			"0srrs      srr   pprrrpprrrrrrrpp     pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpp   rr  s        srrs    pprrrrrrpprrrrrrpprrrrpprrrrrpprrrrrrrpp 0",
			"0 pprrrrrrrrpp   rr       hl   rr     rrs    srrs    srrs  srrs   s        srrs0",
			"0 rrs      srrs  rr       mn   rr     rr      rr      rr    rr       hl     rr 0",
			"0 rr       srrs srrs          srrs   srrs    srrs    srrs  srrs      mn     rr 0",
			"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
			"0 pprrrrrrrrpprrrpprrrrrrrrrrrrpprrrrrpprrrrrrpprrrrrrpprrrrpprrrrrrrrrrrrrrpp 0",
			"0          s    s                s   s       s       s     s                   0",
			"00000000000000000000000000000000000000000000000000000000000000000000000000000000",
		};

	}
	Simvol = simvol;
	
};


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
			default:
			{
						Sprite.setTextureRect(sf::IntRect(2 * pix, 0, pix, pix));
						break;
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


