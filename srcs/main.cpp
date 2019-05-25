#include <iostream>

#include "Renderer.hpp"
#include "Meteorite.hpp"
#include "Player.hpp"
#include "Rocket.hpp"
#include "Invader.hpp"

int		main(void)
{
//	std::cout << "hello world\n";
	Renderer	r;
//unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction, unsigned int attackDamage, unsigned int speed

	Rocket rocket(10, 10, true);
	Meteorite meteorite(4, 4);
	Player player;
	Invader invader(7, 0);
	r.placeEntity(&rocket);
	r.placeEntity(&meteorite);
	r.placeEntity(&player);
	r.placeEntity(&invader);
	while (1)
	{
//		r.handleEvent();
		r.render();
	}
	return 0;
}
