#include "Player.hpp"

Player::Player()
	: ASpaceShip(100, 0, 5, '>', 12, false, 10, 0)
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
