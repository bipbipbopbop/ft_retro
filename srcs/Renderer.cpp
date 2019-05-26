#include <string>
#include "Renderer.hpp"
#include "ft_retro.hpp"

Renderer::Renderer()
	: _column(FT_COLUMNS), _line(FT_LINES), _window(initscr())
{
	noecho();
	curs_set(false);
	nodelay(stdscr, true);
	keypad(stdscr, true);
}

Renderer::Renderer(Renderer const &src)
{
	// SHOULD NOT BE USED
	*this = src;
}

Renderer::~Renderer()
{
	delwin(this->_window);
	endwin();
}

Renderer  &Renderer::operator=(Renderer const &rhs)
{
	// SHOULD NOT BE USED
	this->_column = rhs._column;
	this->_line = rhs._line;
	delwin(this->_window);
	this->_window = rhs._window;

	return *this;
}

KeyEvent	Renderer::retrieveEvent() const
{
	KeyEvent	key = (KeyEvent)getch();
	(void)key;
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
	case ' ':
	//
	//	case ECHAP
	}*/

	return key;

}

void	Renderer::replaceEntity(AEntity *entity)
{
	std::string	entityChar(1, entity->getForm());

	mvwprintw(this->_window, (int)entity->getYPos(), (int)entity->getXPos(), entityChar.c_str());
}
//TODO :placeEntity pour entity avec plusieurs char


void	Renderer::render() const
{
	//clearok(this->_window, true);//it do not work ?
	refresh();
}

unsigned int		Renderer::getLineNb() const
{
	return this->_line;
}

unsigned int		Renderer::getColumnNb() const
{
	return this->_column;
}
