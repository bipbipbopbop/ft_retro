#ifndef AENTITY_HPP
# define AENTITY_HPP

# include "IEntity.hpp"

class AEntity : public IEntity
{
public:
	AEntity();
	AEntity(unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction, unsigned int attackDamage, unsigned int speed);
	AEntity(AEntity const &src);
	virtual ~AEntity();

	AEntity  &operator=(AEntity const &rhs);

	virtual Coord	move();
	virtual void	takeDamage(int damage);

	unsigned int	getXPos() const;
	unsigned int	getYPos() const;
	char			getForm() const;
	int				getColor() const;
	bool			getDirection() const;

private:
	virtual void	_move(Coord &newCoord);//implementation defined movement

	unsigned int	_hp;
	unsigned int	_xPos;
	unsigned int	_yPos;
	char			_form;
	int				_color;
	bool			_direction;//true == left, false == right
	unsigned int	_attackDamage;
	unsigned int	_speed;
};

#endif // AENTITY_HPP
