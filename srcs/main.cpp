#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "RetroEngine.hpp"
#include "TimeLapse.hpp"

#define FRAMRATE 40


int		main(void)
{
	
	RetroEngine	ft_retro;
	TimeLapse	timer;

	Renderer r;

	Rocket rocket(10, 10, true);
	Meteorite meteorite(4, 4);
	Invader invader(7, 0);


	int sleepingTime = 1000000 / FRAMRATE;
	//ft_retro.addEntity(new Rocket(rocket));
	//ft_retro.addEntity(new Meteorite(meteorite));
	//ft_retro.addEntity(new Invader(invader));

	timer.start();
	while (true)
	{
		clear();
		KeyEvent	key = ft_retro.retrieveKeyEvent();
		ft_retro.handleKeyEvent(key);
		ft_retro.updateEntities();
		ft_retro.renderFrame();
		usleep(sleepingTime);
	}

	//int test = 1;

	//while (true)
	//{
	//	clear();
	//	if (test == 1)
	//		r.replaceEntity(&rocket);
	//	if (test == 2)
	//		r.replaceEntity(&meteorite);

	//	test = 2;
	//	refresh();
	//	usleep(1000000);
	//	
	//}
	//endwin();

	return 0;
}
