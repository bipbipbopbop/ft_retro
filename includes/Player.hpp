#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "ASpaceShip.hpp"

class Player : public ASpaceShip
{
public:
	Player();
	Player(Player const &src);
	virtual ~Player();

	Player		&operator=(Player const &rhs);

	void		moveVertical(int y);
	void		moveHorizontal(int x);
};

#endif // ASPACESHIP_HPP
