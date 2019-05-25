#ifndef RETROENGINE_HPP
# define RETROENGINE_HPP

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

	KeyEvent	retrieveKeyEvent();
	void		renderFrame();
	void		updateEntities();
	void		addEntity(AEntity *entity);

private:
	Renderer		_renderer;
	EntityList		_entityList;
	Player			_player;
};


#endif // RETROENGINE_HPP