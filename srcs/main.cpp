#include <iostream>
#include "RetroEngine.hpp"

int		main(void)
{
	RetroEngine	ft_retro;

	Rocket rocket(10, 10, true);
	Meteorite meteorite(4, 4);
	Invader invader(7, 0);
	ft_retro.addEntity(new Rocket(rocket));
	ft_retro.addEntity(new Meteorite(meteorite));
	ft_retro.addEntity(new Invader(invader));

	while (true)
	{
		//getEvent for player
		KeyEvent	key = ft_retro.retrieveKeyEvent();
		(void)key;
//		...

		//TODO: update only once before rendering
		ft_retro.updateEntities();

		//is it time to refresh ?
		if (true)
		{
			//reset timer

			//display all entities and render frame
			ft_retro.renderFrame();
		}
	}

	return 0;
}
