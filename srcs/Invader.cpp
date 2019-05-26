#include "Invader.hpp"

Invader::Invader(unsigned int xPos, unsigned int yPos)
	: ASpaceShip(40, xPos, yPos, '#', 14, true, 100, 1), _randShoot(rand())
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
	this->_randShoot = rand();
	this->ASpaceShip::operator=(rhs);
	return *this;
}

Coord Invader::move()
{
	Coord	result = { this->getXPos(), this->getYPos() };

	this->_move(result);

	return result;
}

void	Invader::_move(Coord &newCoord)
{
	static int fram = 0;
	unsigned int direction_vertical = rand() % 2;

	if (fram % 3 == 0)
		newCoord.x += (this->getDirection() ? -1 : 1) * this->getSpeed();
		
	if (fram++ % 10 != 5)
	{
		AEntity::_move(newCoord);
		return;
	} else {
		if (direction_vertical && newCoord.y < FT_LINES)
		{
			newCoord.y += 1;
		}
		if (!direction_vertical && newCoord.y > 0)
			newCoord.y -= 1;
		AEntity::_move(newCoord);
	}
	return;
}

AEntity *Invader::shoot()
{
	if (this->_randShoot++ % FT_FRAMERATE == 0)
		return ASpaceShip::shoot();
	return NULL;
}
