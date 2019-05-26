#include "Player.hpp"

Player::Player()
	: ASpaceShip(100, 0, 5, '>', 12, false, 10, 1)
{}

Player::Player(Player const &src)
	: ASpaceShip(src)
{
	*this = src;
}

Player::~Player()
{}

Player  &Player::operator=(Player const &rhs)
{
	this->ASpaceShip::operator=(rhs);
	return *this;
}

void		Player::moveVertical(int y)
{
	Coord		newCoord = { this->getXPos(), y };

	this->_move(newCoord);
}

void		Player::moveHorizontal(int x)
{
	Coord		newCoord = { x, this->getYPos() };

	this->_move(newCoord);
}
