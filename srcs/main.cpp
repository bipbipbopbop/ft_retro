#include <iostream>
#include "RetroEngine.hpp"
#include "TimeLapse.hpp"


int		main(void)
{
	RetroEngine	ft_retro;
	bool		isUpdated = false;
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
		//getEvent for player
		KeyEvent	key = ft_retro.retrieveKeyEvent();

		if (!isUpdated)
		{
			//ft_retro.updateEntities();
			isUpdated = true;
		}

		//is it time to refresh ?
		timer.update();
		if (timer.checkTime(TIME_LAPSE))
		{
			//update player position (so only the last presed key is tooken),
			//display all entities and render frame
			ft_retro.handleKeyEvent(key);
			ft_retro.renderFrame();
			isUpdated = false;
		}
	}

	return 0;
}
