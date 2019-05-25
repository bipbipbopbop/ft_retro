#include "ASpaceShip.hpp"


ASpaceShip::ASpaceShip(unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction, unsigned int attackDamage, unsigned int speed)
	: AEntity(hp, xPos, yPos, form, color, direction), _attackDamage(attackDamage), _speed(speed)
{}

ASpaceShip::ASpaceShip(ASpaceShip const &src)
{
	*this = src;
}

ASpaceShip::~ASpaceShip()
{}


ASpaceShip  &ASpaceShip::operator=(ASpaceShip const &rhs)
{
	this->AEntity::operator=(rhs);
	this->_attackDamage = rhs._attackDamage;
	this->_speed = rhs._speed;

	return *this;
}


/*void	ASpaceShip::Shoot()
{
	// create a projectile
	//
}*/