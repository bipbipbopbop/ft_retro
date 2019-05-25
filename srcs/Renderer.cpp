#include "Renderer.hpp"


	Renderer::Renderer()
		: _column(120), _line(40), _window(initscr())
	{
		noecho();
		keypad(this->_window, true);
	}

	Renderer::Renderer(Renderer const &src)
	{
		*this = src;
	}
	
	Renderer::~Renderer()
	{
		delwin(this->_window);
		endwin();
	}

	Renderer  &Renderer::operator=(Renderer const &rhs)
	{// SHOULD NOT BE USED
		this->_column = rhs._column;
		this->_line = rhs._line;
		delwin(this->_window);
		this->_window = rhs._window;

		return *this;
	}

	Renderer::KeyEvent	Renderer::handleEvent() const
	{
		Renderer::KeyEvent	key = (KeyEvent)getch();


		std::cout << "you type the key: " << (int)key << std::endl;
/*		switch (character)
		{
			case KEY_DOWN:
//			y++;
			case KEY_UP:
//			y--;
			case KEY_LEFT:
//			x--;
			case KEY_RIGHT:
//			x++;
//			case ECHAP
		}*/

		return key;

	}

/*	void	Renderer::placeEntity(AEntity *entity)
	{
		std::string	entityChar(entity->getChar());

		mvprintw(entity->getX(), entity->getY(), entityChar.c_str());
	}*/
	//TODO :placeEntity pour entity avec plusieurs char


	void	Renderer::render() const
	{
		refresh();
	}
