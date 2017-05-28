/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameObject.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/27 21:40:15 by kbamping          #+#    #+#             */
/*   Updated: 2017/05/28 01:27:43 by kbamping         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameObject.hpp"

GameObject::GameObject(void)
{
    return;
}

GameObject::GameObject(WINDOW * win)
{
    this->_character = '>';
    
	this->setWindow(win);
    // Get terminal size
	getmaxyx(this->_curwin, this->_yMax, this->_xMax);
    setLocation(((this->_yMax - 5) / 2), 2);
    // Listen to keypad
	keypad(this->_curwin, true);
}

GameObject::GameObject(GameObject const & src)
{
    *this = src;
    return;
}

GameObject& GameObject::operator=(GameObject const & rhs)
{
    if (this != &rhs)
    {
		this->_currLocation[0] = rhs._currLocation[0];
		this->_currLocation[1] = rhs._currLocation[1];
        this->_xMax = rhs._xMax;
		this->_yMax = rhs._yMax;
		this->_character = rhs._character;
    }

    return *this;
}

GameObject::~GameObject(void)
{
    return;
}

void	GameObject::mvup(void)
{
    int *loc = this->getLocation();

	mvwaddch(this->_curwin, loc[1], loc[0], ' ');
	loc[1]--;
	if (loc[1] < 1)
		loc[1] = this->_yMax - 2;
}

void	GameObject::mvdown(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
	this->_currLocation[1]++;
	if (this->_currLocation[1] > this->_yMax - 2)
		this->_currLocation[1] = 1;
}

void	GameObject::mvleft(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
	this->_currLocation[0]--;
	this->_currLocation[0]--;
	if (this->_currLocation[0] < 1)
		this->_currLocation[0] = 1;
}

void	GameObject::mvright(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], ' ');
    
	this->_currLocation[0]++;
	this->_currLocation[0]++;
	if (this->_currLocation[0] > this->_xMax - 2)
		this->_currLocation[0] = this->_xMax - 2;
}

int GameObject::getmv(void)
{
	int	choice = wgetch(this->_curwin);
	switch(choice)
	{
		case KEY_UP:
			mvup();
			break;
		case KEY_DOWN:
			mvdown();
			break;
		case KEY_LEFT:
			mvleft();
			break;
		case KEY_RIGHT:
			mvright();
			break;
		default:
			break;
	}
	return (choice);
}

void	GameObject::displayGameObject(void)
{
	mvwaddch(this->_curwin, this->_currLocation[1], this->_currLocation[0], this->_character);
}

int     *GameObject::getLocation(void) const
{
    return (this->_currLocation);
}

void    GameObject::setLocation(int xLoc, int yLoc)
{
    this->_currLocation[0] = xLoc;
    this->_currLocation[1] = yLoc;
}

int     GameObject::getMax(char c) const
{
    return ((c == 'x' ? this->_xMax : (c == 'y') ? this->_yMax : -1));
}

void    GameObject::setMax(char c, int val)
{
    if (c == 'x')
        this->_xMax = val;
    else if (c == 'y')
        this->_yMax = val;
}

WINDOW  *GameObject::getWindow() const
{
    return (this->_curwin);
}

void    GameObject::setWindow(WINDOW *win)
{
    this->_curwin = win;
}
    