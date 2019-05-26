#include "RetroEngine.hpp"
#include "TimeLapse.hpp"


RetroEngine::RetroEngine()
{}

RetroEngine::RetroEngine(RetroEngine const &src)
{
	// SHOULD NOT BE USED
	*this = src;
}

RetroEngine::~RetroEngine()
{}


RetroEngine  &RetroEngine::operator=(RetroEngine const &rhs)
{
	// SHOULD NOT BE USED
	this->_renderer = rhs._renderer;
	this->_player = rhs._player;
	this->_entityList = rhs._entityList;

	return *this;
}


KeyEvent	RetroEngine::retrieveKeyEvent() const
{
	return this->_renderer.retrieveEvent();
}

void		RetroEngine::handleKeyEvent(KeyEvent key)
{
	switch (key)
	{
		case noValue:
			break;
		case keyDown:
			this->_updatePlayerPos(FT_DOWN);
			break;
		case keyUp:
			this->_updatePlayerPos(FT_UP);
			break;
		case keySpace:
			this->_entityList.push(this->_player.shoot());
			break;
		case keyLeft:
			this->_updatePlayerPos(FT_LEFT);
			break;
		case keyRight:
			this->_updatePlayerPos(FT_RIGHT);
			break;
		default:;
	}
}

void		RetroEngine::renderFrame()
{
	clear();

	for (EntityList::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
	{
		this->_renderer.replaceEntity(*it);
	}
	this->_renderer.replaceEntity(&this->_player);
	this->_renderer.render();
}

void		RetroEngine::updateEntities()
{
	EntityList::iterator it = this->_entityList.begin();
	// update position (move left or right, depending on _direction)
	while (it != this->_entityList.end())
	{
		Coord	newCoord = (*it)->move();

		if (newCoord.x < 0 || newCoord.x > (int)this->_renderer.getColumnNb()
				|| newCoord.y < 0 || newCoord.y > (int)this->_renderer.getLineNb())
		{
			EntityList::iterator	tmp = it++;
			delete this->_entityList.pop(tmp);
			continue;
		}
		for (EntityList::iterator it2 = this->_entityList.begin(); it2 != this->_entityList.end(); ++it2)
		{
			//		if ((*it)->checkCollision(*it2))
			//			(*it)->handleCollision(*it2);
		}
		it++;
	}
	this->_makeShoot();

	this->_pushMeteorite();
	this->_pushInvader();

	// pop new entities

}

void		RetroEngine::_makeShoot()
{
	for (EntityList::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
	{
		AEntity *tmp = (*it)->shoot();
		if (tmp != NULL)
		{
			this->_entityList.push(tmp);
		}
	}

}

void		RetroEngine::_pushMeteorite()
{
	static TimeLapse timer;
	int y;

	y = rand() % 18 + 3;
	timer.update();

	if (timer.checkTime(FT_TIMELAPSE * 20.42))
	{
		this->_entityList.push(new Meteorite(this->_renderer.getColumnNb(), y));
	}
}

void		RetroEngine::_pushInvader()
{
	static TimeLapse timer;
	int y;

	y = rand() % 18 + 3;
	timer.update();

	if (timer.checkTime(FT_TIMELAPSE * 47.73))
	{
		this->_entityList.push(new Invader(this->_renderer.getColumnNb(), y));
	}
}

void		RetroEngine::addEntity(AEntity *entity)
{
	this->_entityList.push(entity);
}

void		RetroEngine::_updatePlayerPos(int direction)
{
	int		currentY = this->_player.getYPos();
	int		currentX = this->_player.getXPos();


	if (FT_UP == direction && (currentY - 1) > 0)
	{
		this->_player.moveVertical(currentY - 1);
	}
	if (FT_DOWN == direction && (currentY + 1) < FT_LINES)
	{
		this->_player.moveVertical(currentY + 1);
	}
	if (FT_LEFT == direction && (currentX - 1) >= 0)
	{
		this->_player.moveHorizontal(currentX - 1);
	}
	if (FT_RIGHT == direction && (currentX + 1) < FT_COLUMNS)
	{
		this->_player.moveHorizontal(currentX + 1);
	}
}
