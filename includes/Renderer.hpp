#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <ncurses.h>
# include "AEntity.hpp"

class Renderer
{
public:

	enum KeyEvent
	{
		keyDown = KEY_DOWN,
		keyUp = KEY_UP,
		keyLeft = KEY_LEFT,
		keyRight = KEY_RIGHT
		//ECHAP
	};

	Renderer();
	~Renderer();

	KeyEvent	handleEvent() const;
	void		render() const;
	void	placeEntity(AEntity *entity);
	//TODO :placeEntity pour entity avec plusieurs char




private:
	Renderer(Renderer const &src);
	Renderer  &operator=(Renderer const &rhs);

	unsigned int		_column;
	unsigned int		_line;
	unsigned int		_cursorX;
	unsigned int		_cursorY;
	WINDOW				*_window;
};

#endif // RENDERER_HPP