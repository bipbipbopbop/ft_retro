#ifndef INVADER_HPP
# define INVADER_HPP

# include "ASpaceShip.hpp"

class Invader : public ASpaceShip
{
public:
	Invader(unsigned int xPos, unsigned int yPos);
	Invader(Invader const &src);
	virtual ~Invader();

	Invader				&operator=(Invader const &rhs);
	virtual Coord		move();
	virtual AEntity				*shoot();

protected:
	virtual void	_move(Coord &newCoord);//implementation defined movement

private:
	int				_randShoot;
};

#endif // ASPACESHIP_HPP
