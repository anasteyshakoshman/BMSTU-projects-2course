#include "Include.h"


class Map
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	std::vector<std::string> TileMap;
public:
	Map(const sf::String file)
	{
		Texture.loadFromFile("images/" + file);
		Sprite.setTexture(Texture);
		TileMap = 
		{
			"01111111111111111111111111111111111111111111111111111111111111111111111111111110",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rr     h     s                rr       rr       s          rr      h   s    rr0",
			"0rr     rr             s       rr    s  rrrrrrrr       s    rr rrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr            rr       rrrrrrrr    h       rrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr    rrrrrrrrrr             rrrrrrrrrrrrrrrr      h        rr0",
			"0rr            s rr    rrsrrrrrrr       h     rrrrrrrrrrrrrrrr         s     rr0",
			"0rr    s         rrrrrrrr      rrrrrrrrrr  s  rr             h   rrrrrrrrrrrrrr0",
			"0rr              rrrrrrrr s    rrrrrrrrrr     rr     h           rrrrrrrrrrrrrr0",
			"0rr     s  s     rr                    rr     rr        s        rr          rr0",
			"0rr   s          rr s       h     s    rr     rr                 rr    h     rr0",
			"0rr          rrrrrrrrrrrr       rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr        s rrrrrrrrrrrr     s rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr  h       rr        rr       rr     rr             s      rr     s        rr0",
			"0rr          rr        rrrrrrrrrrr     rr        h           rrrrrrrrr       rr0",
			"0rrrrrrrrrrrrrr        rrrrrrrrrrr     rrrrrrrrrr   s        rrrrrrrrr    h  rr0",
			"0rrrrrrrrrrrrrr     s        s  rr     rrrrrrrrrr      rrrrrrrr     rr       rr0",
			"0rr       s       rrrrrrrrrrrrrrrr    s        rr      rrrrrrrr   s rr       rr0",
			"0rr   h           rrrrrrrrrrrrrrrr       h     rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr                   s       rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr        h             s    rr      rr             rr     rr0",
			"0rr     h    s    rr           s     h         rr      rr                    rr0",
			"0rr               rr                           rrrrrrrrrr              h     rr0",
			"0rr                                                rr                        rr0",
			"0rr     rr             s       rr    s  rrrrrrrr       s    rr rrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr            rr       rrrrrrrr    h       rrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrr    rrrrrrrrrr             rrrrrrrrrrrrrrrr      h        rr0",
			"0rr            s rr    rrsrrrrrrr       h     rrrrrrrrrrrrrrrr         s     rr0",
			"0rr    s         rrrrrrrr      rrrrrrrrrr  s  rr             h   rrrrrrrrrrrrrr0",
			"0rr              rrrrrrrr s    rrrrrrrrrr     rr     h           rrrrrrrrrrrrrr0",
			"0rr     s  s     rr                    rr     rr        s        rr          rr0",
			"0rr   s          rr s       h     s    rr     rr                 rr    h     rr0",
			"0rr          rrrrrrrrrrrr       rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr        s rrrrrrrrrrrr     s rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr          rr0",
			"0rr  h       rr        rr       rr     rr             s      rr     s        rr0",
			"0rr          rr        rrrrrrrrrrr     rr        h           rrrrrrrrr       rr0",
			"0rrrrrrrrrrrrrr        rrrrrrrrrrr     rrrrrrrrrr   s        rrrrrrrrr    h  rr0",
			"0rrrrrrrrrrrrrr     s        s  rr     rrrrrrrrrr      rrrrrrrr     rr       rr0",
			"0rr       s       rrrrrrrrrrrrrrrr    s        rr      rrrrrrrr   s rr       rr0",
			"0rr   h           rrrrrrrrrrrrrrrr       h     rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr                   s       rr      rr    rrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrr        h             s    rr      rr             rr     rr0",
			"0rr     h    s    rr           s     h         rr      rr                    rr0",
			"0rr               rr                           rrrrrrrrrr              h     rr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"0rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr0",
			"01111111111111111111111111111111111111111111111111111111111111111111111111111110",
		};
	}

	void draw(sf::RenderWindow & window)
	{
		for (int i = 0; i < 48; ++i)
		{
			for (int j = 0; j < 80; ++j)
			{
				switch (TileMap[i][j])
				{
					case '0':
					{
						Sprite.setTextureRect(sf::IntRect(10, 0, 8, 8));
						break;
					}
					case 'r':
					{
						Sprite.setTextureRect(sf::IntRect(100, 0, 8, 8)); 
						break;
					}
					case 's':
					{
						Sprite.setTextureRect(sf::IntRect(310, 150, 8, 8));
						break;
					}
					case 'h':
					{
						Sprite.setTextureRect(sf::IntRect(1185, 129, 8, 8));
						break;
					}
					case ' ':
					{
						Sprite.setTextureRect(sf::IntRect(550, 0, 8, 8));
						break;
					}
					case '1':
					{
						Sprite.setTextureRect(sf::IntRect(10, 0, 8, 8));
						break;
					}
				}
				Sprite.setPosition(j * 8, i * 8);
				window.draw(Sprite);
			}
		}
	}

	~Map()
	{
		TileMap.clear();
	}
};






