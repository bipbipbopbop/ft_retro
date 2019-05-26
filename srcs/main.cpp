#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "RetroEngine.hpp"
#include "TimeLapse.hpp"


int		main(void)
{
	RetroEngine	ft_retro;
	bool		isEntitiesUpdated = false;
	bool		isKeyRetrieve = false;
	KeyEvent	key;
	TimeLapse	timer;

	Rocket rocket(10, 10, true);
	Meteorite meteorite(4, 4);
	Invader invader(7, 0);
	//ft_retro.addEntity(new Rocket(rocket));
	//ft_retro.addEntity(new Meteorite(meteorite));
	//ft_retro.addEntity(new Invader(invader));

	timer.start();
	while (true)
	{
		if (!isEntitiesUpdated)
		{
			ft_retro.updateEntities();
			isEntitiesUpdated = true;
		}

		//getEvent for player
		if (!isKeyRetrieve)
		{
			key = ft_retro.retrieveKeyEvent();
			if (key == keyUp || key == keyDown || key == keyLeft || key == keyRight || key == keySpace)
				isKeyRetrieve = true;
		}
		else
			flushinp();

		//is it time to refresh ?
		timer.update();
		if (timer.checkTime(FT_TIMELAPSE))
		{
			//update player position (so only the last presed key is tooken),
			//display all entities and render frame
			ft_retro.handleKeyEvent(key);
			ft_retro.renderFrame();
			isEntitiesUpdated = false;
			isKeyRetrieve = false;
		}
	}

	return 0;
}