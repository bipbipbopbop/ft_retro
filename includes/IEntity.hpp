#ifndef IENTITY_HPP
# define IENTITY_HPP

# include "Coord.hpp"

class IEntity
{
public:
	virtual ~IEntity() {}

	virtual Coord	move() = 0;//return true if the entity is still in the screen
	virtual void	takeDamage(int damage) = 0;
};

#endif // IENTITY_HPP