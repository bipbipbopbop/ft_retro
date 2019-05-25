#include "RetroEngine.hpp"


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


KeyEvent	RetroEngine::retrieveKeyEvent()
{
	return this->_renderer.handleEvent();
}

void		RetroEngine::renderFrame()
{
	for (EntityList::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
	{
		this->_renderer.replaceEntity(*it);
	}
	this->_renderer.render();
}

void		RetroEngine::updateEntities()
{
	// update position (move left or right, depending on _direction)
	for (EntityList::iterator it = this->_entityList.begin(); it != this->_entityList.end(); ++it)
	{
		Coord	newCoord = (*it)->move();

		if (newCoord.x < 0 || newCoord.x > (int)this->_renderer.getColumnNb()
			|| newCoord.y < 0 || newCoord.y > (int)this->_renderer.getLineNb())
		{
			delete this->_entityList.pop(it);
		}
	}

	// is their any colision ?
	for (size_t i = 0; i < this->_entityList.size(); ++i)
	{
		AEntity *tmp;
		(void)tmp;
//		if ((tmp = this->_entityList[i]->checkCollision(i)) != NULL)
//			this->_entityList[i]->handleCollision(tmp);
	}

	// pop new entities

}

void		RetroEngine::addEntity(AEntity *entity)
{
	this->_entityList.push(entity);
}
