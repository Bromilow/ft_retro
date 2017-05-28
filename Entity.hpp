
#ifndef _Entity_HPP_
#define _Entity_HPP_

#include <curses.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Player.hpp"
#include <ctime>

class Entity : Public Base
{
	public:

Entity(void);
Entity(int num);
Entity(Entity const & src);
Entity(WINDOW * win, int _yMax);
Entity& operator=(Entity const & rhs);
~Entity(void);

int				*getLoc();                        //    entity location
void			setLoc(int x, int y);

void    		shoot(Entity object, int location);          
bool         	hitPlayer();
bool         	hitBullet();

	private:

int		_xMax;
int		_xLoc;
int		_yLoc;
Entity  *_object;
int     _amount;
char	_character;
int		*location;
};

#endif
