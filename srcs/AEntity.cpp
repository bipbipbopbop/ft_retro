#include "AEntity.hpp"


AEntity::AEntity()
{}

AEntity::AEntity(unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction)
	: _hp(hp), _xPos(xPos), _yPos(yPos), _form(form), _color(color), _direction(direction)
{}

AEntity::AEntity(AEntity const &src)
{
	*this = src;
}

AEntity::~AEntity()
{}


AEntity  &AEntity::operator=(AEntity const &rhs)
{
	this->_hp = rhs._hp;
	this->_xPos = rhs._xPos;
	this->_yPos = rhs._yPos;
	this->_form = rhs._form;
	this->_color = rhs._color;
	this->_direction = rhs._direction;

	return *this;
}


void	AEntity::takeDamage(int damage)
{
	this->_hp -= (damage > (int)this->_hp ? this->_hp : damage);
}


unsigned int	AEntity::getXPos() const
{
	return this->_xPos;
}

unsigned int	AEntity::getYPos() const
{
	return this->_yPos;
}

char			AEntity::getForm() const
{
	return this->_form;
}

int				AEntity::getColor() const
{
	return this->_color;
}

bool			AEntity::getDirection() const
{
	return this->_direction;
}


void	AEntity::_move(unsigned int x, unsigned int y)
{
	this->_xPos = x;
	this->_yPos = y;
}