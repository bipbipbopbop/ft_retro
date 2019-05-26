#include "Meteorite.hpp"


Meteorite::Meteorite(unsigned int xPos, unsigned int yPos)
	: AEntity(10, xPos, yPos, 'x', 10, true, 10, 1)
{}

Meteorite::Meteorite(Meteorite const &src)
{
	*this = src;
}

Meteorite::~Meteorite()
{}


Meteorite  &Meteorite::operator=(Meteorite const &rhs)
{
	this->AEntity::operator=(rhs);
	return *this;
}

void	Meteorite::_move(Coord &newCoord)
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
