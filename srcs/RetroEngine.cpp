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
		if (!(*it)->isBoss())
			this->_renderer.replaceEntity(*it);
		else
		{
			Boss	*boss = dynamic_cast<Boss *>((*it));
			for (EntityList::iterator bossIt = boss->begin(); bossIt != boss->end(); ++bossIt)
				this->_renderer.replaceEntity(*bossIt);
		}
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
		EntityList::iterator it2 = this->_entityList.begin();
		while (it2 != this->_entityList.end())
		{
			if ((*it) != (*it2))
			{
				if ((*it)->getXPos() == (*it2)->getXPos() && (*it)->getYPos() == (*it2)->getYPos())
				{
					(*it)->takeDamage((*it2)->getAttackDamage());
					(*it2)->takeDamage((*it)->getAttackDamage());
					this->_player.setScore(this->_player.getAttackDamage());
					this->_renderer.putScoreObject((*it)->getXPos(), (*it)->getYPos() - 1, 20);
				}

				if ((*it2)->getHp() == 0)
				{
					EntityList::iterator tmp = it2++;
					delete this->_entityList.pop(tmp);
					continue;
				}
			}
			it2++;
		}
		if (this->_player.getXPos() == (*it)->getXPos() && this->_player.getYPos() == (*it)->getYPos())
		{
			this->_player.takeDamage((*it)->getAttackDamage());
			this->_player.setScore(-(*it)->getAttackDamage());
			(*it)->takeDamage(this->_player.getAttackDamage());
			this->_renderer.putScoreObject(this->_player.getXPos(), this->_player.getYPos() - 1, -(*it)->getAttackDamage());
		}
		if ((*it)->getHp() == 0)
		{
			EntityList::iterator tmp = it++;
			delete this->_entityList.pop(tmp);
			continue;
		}
		it++;
	}
	this->_makeShoot();
	this->_pushMeteorite();
	if (rand() % 2)
		this->_pushInvader();
	else
		this->_pushBomber();
	this->_putHp();
	this->_putScore();
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

void		RetroEngine::_putHp()
{
	std::string str;

	str = "HP= " + std::to_string(this->_player.getHp());
	this->_renderer.putString(0, FT_LINES, str);
}

void		RetroEngine::_putScore()
{
	std::string str;

	str = "Score= " + std::to_string(this->_player.getScore());
	this->_renderer.putString(10, FT_LINES, str);
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
	static TimeLapse invaderTimer;
	static TimeLapse bossTimer;
	static double	bossDelay = 60.;
	int y = rand() % 18 + 3;

	invaderTimer.update();
	bossTimer.update();

	if (bossTimer.checkTime(bossDelay))
	{
		this->_entityList.push(new Boss(1000, FT_COLUMNS, FT_LINES / 2));
		if (bossDelay > 10.)
			bossDelay -= 5.;
	}
	else if (invaderTimer.checkTime(FT_TIMELAPSE * 47.73))
		this->_entityList.push(new Invader(this->_renderer.getColumnNb(), y));
}

void		RetroEngine::_pushBomber()
{
	static TimeLapse timer;
	int y;

	y = rand() % 5;
	timer.update();

	if (timer.checkTime(FT_TIMELAPSE * 47.73))
	{
		this->_entityList.push(new Bomber(this->_renderer.getColumnNb(), y));
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
