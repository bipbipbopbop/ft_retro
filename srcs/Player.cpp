#include "Player.hpp"

Player::Player()
	: ASpaceShip(100, 0, 12, '>', 12, false, 100, 1), _score(0)
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

int			Player::getScore()
{
	return this->_score;
}

void		Player::setScore(int i)
{
	this->_score += i;
}
