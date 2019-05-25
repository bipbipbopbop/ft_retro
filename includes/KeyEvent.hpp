#ifndef KEYEVENT_HPP
# define KEYEVENT_HPP

# include <ncurses.h>

enum KeyEvent
{
	keyDown = KEY_DOWN,
	keyUp = KEY_UP,
	keyLeft = KEY_LEFT,
	keyRight = KEY_RIGHT,
	keySpace = ' '
	//ECHAP
};

#endif // KEYEVENT_HPP