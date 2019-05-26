#include "Invader.hpp"

Invader::Invader(unsigned int xPos, unsigned int yPos)
	: ASpaceShip(10, xPos, yPos, '#', 14, true, 30, 0)
{}

Invader::Invader(Invader const &src)
	: ASpaceShip(src)
{
	*this = src;
}

Invader::~Invader()
{}

Invader  &Invader::operator=(Invader const &rhs)
{
	this->ASpaceShip::operator=(rhs);
	return *this;
}

void	Invader::_move(Coord &newCoord)
{
	unsigned int direction_vertical = rand() % 2;

	if (direction_vertical && newCoord.y < FT_LINES)
	{
		newCoord.y += 1;
	}
	if (!direction_vertical && newCoord.y > 0)
		newCoord.y -= 1;
	AEntity::_move(newCoord);
}
