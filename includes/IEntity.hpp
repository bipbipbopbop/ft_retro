#ifndef IENTITY_HPP
# define IENTITY_HPP

class IEntity
{
public:
	virtual ~IEntity();

	virtual void	move(int x, int y) = 0;
	virtual void	takeDamage(int damage) = 0;
};

#endif // IENTITY_HPP