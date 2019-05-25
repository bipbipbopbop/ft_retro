#include <iostream>
#include "Renderer.hpp"
#include "ASpaceShip.hpp"

int		main(void)
{
//	std::cout << "hello world\n";
	Renderer	r;
//unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction, unsigned int attackDamage, unsigned int speed
	ASpaceShip		ent1(10, 10, 10, '>', 13, false, 2, 1);
	ASpaceShip		ent2(10, 1, 1, 'E', 13, false, 3, 1);

	r.placeEntity(&ent1);
	r.placeEntity(&ent2);
	while (1)
	{
//		r.handleEvent();
		r.render();
	}
	return 0;
}