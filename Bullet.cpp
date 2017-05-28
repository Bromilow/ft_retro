#include "Bullet.hpp"

/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

Bullet::Bullet(void) : this->_character = '-';
{
    shoot(*this);
}

Bullet::Bullet(Bullet const & src)
{
    *this = src;
    return;
}


Bullet::~Bullet(void)
{
    return;
}


/////////////////////////////////[  overloaded operators  ]////////////////////////////////////////

Bullet& Bullet::operator=(Bullet const & rhs)
{
    if (this != &rhs)
    {
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
        this->_character = rhs._character;
    }
    return *this;
}

/////////////////////////////////[  member functions  ]////////////////////////////////////////

void    Bullet::shoot(Bullet object)
{

    int *pLoc = getLocation();
    setLocation(pLoc[0], pLoc[1]);
    setLocation(pLoc[0] += 1, pLoc[1]);

}

int             *Bullet::getLoc() 
{
    int    i[2];
    i[0] = this->_yLoc;
    i[1] = this->_xLoc;

    return(i);
}

void			Bullet::setLoc(int x ,int y)
{
    this->_xLoc = x;
    this->_yLoc = y;
}
/*
bool        Bullet::hitObject();
{
    int **pLoc = getObjectsLocation();
    if (((this->xLoc == ) && (this->yloc == pLoc[1]))
    {
        return true;
    }
    return false;
}




getObjectsLocation
        ----- when we have a boss that can shoot back

bool           Bullet::hitPlayer();
{
    int *pLoc = getplayerlocation();                               // get the proper location
    if (((this->xLoc == pLoc[0]) && (this->yloc == pLoc[1]))       // check for unit collision
    {
        delete this;
        return true;
    }
    return false;
}
*/

