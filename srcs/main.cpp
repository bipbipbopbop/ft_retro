#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "RetroEngine.hpp"
#include "TimeLapse.hpp"


int		main(void)
{
	RetroEngine	ft_retro;
	KeyEvent	key;
	TimeLapse	frameTimer;
	bool		isEntitiesUpdated = false;
	bool		isKeyRetrieve = false;

	frameTimer.start();
	while (true)
	{
		// Update entities pos, do actions, etc
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

		frameTimer.update();
		if (frameTimer.checkTime(FT_TIMELAPSE))
		{
			//update player position (so only the last presed key is tooken),
			//display all entities and render frame
			ft_retro.handleKeyEvent(key);
			ft_retro.renderFrame();
			mvwprintw(stdscr, FT_LINES, 30, ("Time= " + std::to_string((int)frameTimer.getTotalTime()) + "s").c_str());
			isEntitiesUpdated = false;
			isKeyRetrieve = false;
		}
	}

	return 0;
}
