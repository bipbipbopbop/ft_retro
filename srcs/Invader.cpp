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
