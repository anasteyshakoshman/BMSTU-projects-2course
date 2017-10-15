#include "Include.h"


class Map
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	std::vector<std::string> TileMap;
	int Height;
	int Weight;
public:
	Map(const sf::String file)
	{
		Texture.loadFromFile("images/" + file);
		Sprite.setTexture(Texture);
		Height = 48;
		Weight = 80;
		TileMap = 
		{
			"01111111111111111111111111111111111111111111111111111111111111111111111111111110",
			"0pprrrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrpp0",
			"0rr           f                rr       rr       f          rr          f    rr0",
			"0rr                            rr    f  pprrrrpp   hl  f    pprrrrrrrrrrrrrrrpp0",
			"0rr  hlrrrrrrrrrrpp            rr  hl   pprrrrpp   mn       pprrrrrrrrrrrrrrrpp0",
			"0rr  mnrrrrrrrrrrpp    pprrrrrrpp  mn         rr            rr      hl       rr0",
			"0rr            f rr    pprrrrrrpp             pprrrrrrrrrrrrpp      mn f     rr0",
			"0rr    f         pprrrrpp      pprrrrrrpp  f  pprrrrrrrrrrrrpp   pprrrrrrrrrrpp0",
			"0rr              pprrrrpp f    pprrrrrrpp     rr     hl          pprrrrrrrrrrpp0",
			"0rr     f  f     rr        hl          rr     rr     mn f        rr          rr0",
			"0rr   f          rr f      mn     f    rr     rr                 rr    hl    rr0",
			"0rr          pprrpprrrrpp       pprrrrrpprrrrrpprrrrrrrrrrrrrpprrpp    mn    rr0",
			"0rr        f pprrpprrrrpp     f pprrrrrpprrrrrpprrrrrrrrrrrrrpprrpp          rr0",
			"0rr          rr        rr       rr     rr           hl f     rr     f        rr0",
			"0rr          rr        pprrrrrrrpp     rr           mn pprrrrpprrrrrpp   hl  rr0",
			"0pprrrrrrrrrrpp        pprrrrrrrpp     pprrrrrrpp      pprrrrpprrrrrpp   mn  rr0",
			"0pprrrrrrrrrrpp     f        f  rr     pprrrrrrpp      rr           rr       rr0",
			"0rr       f            pprrrrrrrpp    f        rr      rr       f   rr       rr0",
			"0rr                    pprrrrrrrpp         hl  rr    f pprrrrrrrrrrrpprrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrpp   rr              f   mn  rr      pprrrrrrrrrrrpprrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrpp   rr  hl             f    rr      rr                    rr0",
			"0rr          f    rr   rr  mn  f    hl   pprrrrpprrrrrrpp     f       hl     rr0",
			"0rr    hl     pprrpprrrpp           mn   pprrrrpprrrrrrpp             mn     rr0",
			"0rr    mn     pprrpprrrpp                rr            rr                    rr0",
			"0rr           rr       rr      pprrrrrrrrpprrrpp       pprrrpprrrrrrrrrrrrrrrpp0",
			"0pprrrrrrrrrrrpprpp    rr      pprrrrrrrrpprrrpp       pprrrpprrrrrrrrrrrrrrrpp0",
			"0pprrrrrrrrrrrpprpp    rr      rr             rr            rr               rr0",
			"0rr            f rr    rr      rr             rr            rr         f     rr0",
			"0rr    f         pprrrrpp      pprrrrrrpp  f  pprrrrrrrrrrrrpprrrrrrrrrrrrrrrpp0",
			"0rr              pprrrrpp f    pprrrrrrpp     pprrrrrrrrrrrrpprrrrrrrrrrrrrrrpp0",
			"0rr     f  f     rr                    rr     rr        f        rr        f rr0",
			"0rr   f          rr f             f    rr     rr                 rr    hl    rr0",
			"0rr          pprrpprrrrpp       pprrrrrpprrrrrrrrrrrrrrrrrrrrpprrpp    mn    rr0",
			"0rr   hl   f pprrpprrrrpp     f pprrrrrpprrrrrrrrrrrrrrrrrrrrpprrpp          rr0",
			"0rr   mn     rr        rr       rr     rr   f         f      rr     f        rr0",
			"0rr          rr        pprrrrrrrpp     rr              pprrrrpprrrrrppr  hl  rr0",
			"0pprrrrrrrrrrpp        pprrrrrrrpp     rrrrrrrrpp   f  pprrrrpprrrrrppr  mn  rr0",
			"0pprrrrrrrrrrpp     f        f  rr     rrrrrrrrpp      rr           rr       rr0",
			"0rr       f       pprrrrrrrrrrrrpp    f        rr      rr         f rr       rr0",
			"0rr               pprrrrrrrrrrrrpp    hl       rr      rr           pprrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrpp             f    mn       rr   f  rr           pprrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrpp       hl             f    rr      rr    rr       rr     rr0",
			"0rr          f    rr       mn  f       f       rr      rr             hl     rr0",
			"0rr   f           rr                           rr      rr             mn     rr0",
			"0pprrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrpprrrrrrrrrrrrrrrrrrrrpp0",
			"0pprrrrrrrrrrrrrrrpprrrrrrrrrrrrrrrrrrrrrrrrrrrpprrrrrrpprrrrrrrrrrrrrrrrrrrrpp0",
			"01111111111111111111111111111111111111111111111111111111111111111111111111111110",
		};
	}

	void draw(sf::RenderWindow & window)
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
					case 'f':
					{
						Sprite.setTextureRect(sf::IntRect(0, 120, 120, 120));
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
					case ' ':
					{
						Sprite.setTextureRect(sf::IntRect(240, 0, 120, 120));
						break;
					}
					case '1':
					{
						Sprite.setTextureRect(sf::IntRect(0, 0, 120, 120));
						break;
					}
					case 'c':
					{
						Sprite.setTextureRect(sf::IntRect(120, 0, 120, 120));
						break;
					}
				}
				Sprite.setPosition(j * 120, i * 120);
				window.draw(Sprite);
			}
		}
	}

	~Map()
	{
		TileMap.clear();
	}


	

	std::vector<std::string> & getTM()
	{
		return TileMap;
	}
};









