#ifndef BOMBER_HPP
# define BOMBER_HPP

# include "ASpaceShip.hpp"
# include "Bomb.hpp"

class Bomber : public ASpaceShip
{
public:
	Bomber(unsigned int xPos, unsigned int yPos);
	Bomber(Bomber const &src);
	virtual ~Bomber();

	Bomber				&operator=(Bomber const &rhs);
	virtual Coord		move();
	virtual AEntity		*shoot();

protected:
	virtual void	_move(Coord &newCoord);//implementation defined movement

private:
	int				_randShoot;
};

#endif // ASPACESHIP_HPP
