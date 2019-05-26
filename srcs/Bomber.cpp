#include "Bomber.hpp"

Bomber::Bomber(unsigned int xPos, unsigned int yPos)
	: ASpaceShip(10, xPos, yPos, '8', 14, true, 100, 1), _randShoot(rand())
{}

	Bomber::Bomber(Bomber const &src)
: ASpaceShip(src)
{
	*this = src;
}

Bomber::~Bomber()
{}

Bomber  &Bomber::operator=(Bomber const &rhs)
{
	this->_randShoot = rand();
	this->ASpaceShip::operator=(rhs);
	return *this;
}

Coord Bomber::move()
{
	Coord	result = { this->getXPos(), this->getYPos() };

	this->_move(result);

	return result;
}

void	Bomber::_move(Coord &newCoord)
{
	static int fram = 0;

	if (fram % 3 == 0)
	{
		newCoord.x += (this->getDirection() ? -1 : 1) * this->getSpeed();
		AEntity::_move(newCoord);
	}
	return;
}

AEntity *Bomber::shoot()
{
	if (this->_randShoot++ % FT_FRAMERATE == 0)
		return new Bomb(this->getXPos(), this->getYPos() + 1, this->getDirection());
	return NULL;
}
