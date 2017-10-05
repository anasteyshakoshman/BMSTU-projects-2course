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
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rr           f                rr       rr       f          rr          f    rr0",
			"0rr                            rr    f  rrrrrrrr   hl  f    rrrrrrrrrrrrrrrrrrr0",
			"0rr  hlrrrrrrrrrrrr            rr  hl   rrrrrrrr   mn       rrrrrrrrrrrrrrrrrrr0",
			"0rr  mnrrrrrrrrrrrr    rrrrrrrrrr  mn         rrrrrrrrrrrrrrrr      hl       rr0",
			"0rr            f rr    rrrrrrrrrr             rrrrrrrrrrrrrrrr      mn f     rr0",
			"0rr    f         rrrrrrrr      rrrrrrrrrr  f  rr                 rrrrrrrrrrrrrr0",
			"0rr              rrrrrrrr f    rrrrrrrrrr     rr     hl          rrrrrrrrrrrrrr0",
			"0rr     f  f     rr        hl          rr     rr     mn f        rr          rr0",
			"0rr   f          rr f      mn     f    rr     rr                 rr    hl    rr0",
			"0rr          rrrrrrrrrrrr       rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr    mn    rr0",
			"0rr        f rrrrrrrrrrrr     f rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr          rr        rr       rr     rr           hl f     rr     f        rr0",
			"0rr          rr        rrrrrrrrrrr     rr           mn       rrrrrrrrr   hl  rr0",
			"0rrrrrrrrrrrrrr        rrrrrrrrrrr     rrrrrrrrrr            rrrrrrrrr   mn  rr0",
			"0rrrrrrrrrrrrrr     f        f  rr     rrrrrrrrrr      rrrrrrrr     rr       rr0",
			"0rr       f       rrrrrrrrrrrrrrrr    f        rr      rrrrrrrr   f rr       rr0",
			"0rr               rrrrrrrrrrrrrrrr         hl  rr    f rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr                   f   mn  rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr       hl             f    rr      rr                    rr0",
			"0rr          f    rr       mn  f    hl   rrrrrrrrrrrrrrrr     f       hl     rr0",
			"0rr    hl     rrrrrrrrrrr           mn   rrrrrrrrrrrrrrrr             mn     rr0",
			"0rr    mn     rrrrrrrrrrr                rr                                  rr0",
			"0rr           rr       rr      rrrrrrrrrrrrrrrrr       f    rrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr    rr      rrrrrrrrrrrrrrrrr            rrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr    rrrrrrrrrr             rrrrrrrrrrrrrrrr               rr0",
			"0rr            f rr    rrrrrrrrrr             rrrrrrrrrrrrrrrr         f     rr0",
			"0rr    f         rrrrrrrr      rrrrrrrrrr  f  rr                 rrrrrrrrrrrrrr0",
			"0rr              rrrrrrrr f    rrrrrrrrrr     rr     hl          rrrrrrrrrrrrrr0",
			"0rr     f  f     rr                    rr     rr     mn f        rr        f rr0",
			"0rr   f          rr f             f    rr     rr                 rr    hl    rr0",
			"0rr          rrrrrrrrrrrr       rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr    mn    rr0",
			"0rr   hl   f rrrrrrrrrrrr     f rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr   mn     rr        rr       rr     rr   f         f      rr     f        rr0",
			"0rr          rr        rrrrrrrrrrr     rr                    rrrrrrrrrr  hl  rr0",
			"0rrrrrrrrrrrrrr        rrrrrrrrrrr     rrrrrrrrrr   f        rrrrrrrrrr  mn  rr0",
			"0rrrrrrrrrrrrrr     f        f  rr     rrrrrrrrrr      rrrrrrrr     rr       rr0",
			"0rr       f       rrrrrrrrrrrrrrrr    f        rr      rrrrrrrr   f rr       rr0",
			"0rr               rrrrrrrrrrrrrrrr    hl       rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr             f    mn       rr   f  rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr       hl             f    rr      rr    rr       rr     rr0",
			"0rr          f    rr       mn  f       f       rr      rr             hl     rr0",
			"0rr   f           rr                           rr      rr             mn     rr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
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

	


	const int getH()
	{
		return Height;
	}

	const int getW()
	{
		return Weight;
	}
};









