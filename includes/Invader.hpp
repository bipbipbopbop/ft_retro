#ifndef INVADER_HPP
# define INVADER_HPP

# include "ASpaceShip.hpp"

class Invader : public ASpaceShip
{
public:
	Invader(unsigned int xPos, unsigned int yPos);
	Invader(Invader const &src);
	virtual ~Invader();

	Invader  &operator=(Invader const &rhs);
};

#endif // ASPACESHIP_HPP
