#ifndef RETROENGINE_HPP
# define RETROENGINE_HPP

#include "ft_retro.h"
#include "Renderer.hpp"
#include "Meteorite.hpp"
#include "Player.hpp"
#include "Rocket.hpp"
#include "Invader.hpp"
#include "EntityList.hpp"

class RetroEngine
{
public:
	RetroEngine();
	RetroEngine(RetroEngine const &src);
	~RetroEngine();

	RetroEngine  &operator=(RetroEngine const &rhs);

	KeyEvent	retrieveKeyEvent() const;
	void		handleKeyEvent(KeyEvent key);

	void		renderFrame();
	void		updateEntities();
	void		addEntity(AEntity *entity);

private:
	void		_updatePlayerPos(int x);

	Renderer		_renderer;
	EntityList		_entityList;
	Player			_player;
};


#endif // RETROENGINE_HPP
