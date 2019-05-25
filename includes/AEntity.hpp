#ifndef AENTITY_HPP
# define AENTITY_HPP

class AEntity
{
public:
	AEntity();
	AEntity(unsigned int hp, unsigned int xPos, unsigned int yPos, char form, int color, bool direction);
	AEntity(AEntity const &src);
	virtual ~AEntity();

	AEntity  &operator=(AEntity const &rhs);

	virtual void	takeDamage(int damage);

	unsigned int	getXPos() const;
	unsigned int	getYPos() const;
	char			getForm() const;
	int				getColor() const;
	bool			getDirection() const;

private:
	void	_move(unsigned int x, unsigned int y);

	unsigned int	_hp;
	unsigned int	_xPos;
	unsigned int	_yPos;
	char			_form;
	int				_color;
	bool			_direction;//true == left, false == right
};

#endif // AENTITY_HPP