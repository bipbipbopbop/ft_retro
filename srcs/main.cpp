#include <iostream>
//#include "Retro.hpp"
#include "ASpaceShip.hpp"

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


	while (false)
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