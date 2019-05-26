#include "Bomb.hpp"


Bomb::Bomb(unsigned int xPos, unsigned int yPos, bool direction)
	: AEntity(80, xPos, yPos, 'o', 11, direction, 20, 1)
{}

Bomb::Bomb(Bomb const &src)
{
	*this = src;
}

Bomb::~Bomb()
{}


Bomb  &Bomb::operator=(Bomb const &rhs)
{
	this->AEntity::operator=(rhs);
	return *this;
}

Coord 	Bomb::move()
{
	Coord	result = { this->getXPos(), this->getYPos() };
	if (this->_count++ % 5 == 0)
		result.y++;
	this->_move(result);
	return result;
}
