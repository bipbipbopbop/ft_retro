#include <iostream>

#include "Renderer.hpp"
#include "Meteorite.hpp"
#include "Player.hpp"
#include "Rocket.hpp"
#include "Invader.hpp"
//#include "Retro.hpp"
#include "ASpaceShip.hpp"
#include "EntityList.hpp"

/*
void    updateEntities(EntityNode *entityList, unsigned int nbEntities)
{
	// update position
	for (i = 0; i < nbEntities; ++i)
	{
		entityList[i].updateCoord();
	}

	// is their any colision ?
	for (i = 0; i < nbEntities; ++i)
	{
		AEntity *tmp;
		if ((tmp = entityList[i].checkCollision(i)) != NULL)
			entityList[i]->handleCollision(tmp);
	}
}*/

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

	//Renderer	r;
	EntityList		entityList;
//	EntityList		player;

	ASpaceShip		*ent1 = new ASpaceShip(10, 10, 10, '>', 13, false, 2, 1);
	ASpaceShip		*ent2 = new ASpaceShip(10, 1, 1, 'E', 13, false, 3, 1);

	std::cout << "List size: " << entityList.size();
	std::cout << " pushing 1 elem\n";

	entityList.push(ent1);
	std::cout << "List size: " << entityList.size();

	std::cout << " pushing 1 elem\n";

	entityList.push(ent2);
	std::cout << "List size: " << entityList.size();


	while (1)
	{
//		r.handleEvent();

//		updateEntities(entityList, nbEntities);
//		r.render();
	}

	for (int i = 0; i < 7; ++i)
	{
		ASpaceShip	*tmp = new ASpaceShip(9000, 10 + i, 10 - i, '0' + i, 13, false, 2, 1);
		entityList.push(tmp);
		std::cout << "add elem to list\n";
	}
	std::cout << "List size: " << entityList.size() << std::endl;
	std::cout << "now popping a spaceship with 13/7 coord:\n";
	AEntity	*tmp = entityList.pop(5);
	std::cout << "spaceship popped: " << tmp->getXPos() << ", " << tmp->getYPos() << std::endl;
	std::cout << "List size: " << entityList.size() << std::endl;

	return 0;
}
