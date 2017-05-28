#include "Entity.hpp"


/////////////////////////////////[  constructor/destructor  ]////////////////////////////////////////

Entity::Entity(void) : _character = '8' ,this->_xLoc = getMax(), this->_yLoc = (rand(getMax()) % getmax());
{
    shoot(*this);

}

Entity::Entity(Entity const & src)
{
    *this = src;
    return;
}


Entity::~Entity(void)
{
    return;
}

Entity::Entity(int num) : this->_character = '8',     // saving the charactor
{
    this->_object = new Entity[num];

    for (int i = 0; i < num ; i++) { 
        // flips time function here !!!
        shoot(this->_object[i], rand(getmax(Y)));     //// get random X number of window size and send though a copy
    }
}
/////////////////////////////////[  overloaded operators  ]////////////////////////////////////////

Entity& Entity::operator=(Entity const & rhs)
{
    if (this != &rhs)
    {
		this->_xLoc = rhs._xLoc;
		this->_yLoc = rhs._yLoc;
		this->_object = rhs._object;
        this->_character = rhs._character;
    }

    return *this;
}

/////////////////////////////////[  member functions  ]////////////////////////////////////////

int             *Entity::getLocation() 
{
    int    i[2];
    i[0] = this->_yLoc;
    i[1] = this->_xLoc;

    return(i);
}

void			Entity::setLocation(int x ,int y)
{
    this->_xLoc = x;
    this->_yLoc = y;
}



void    Entity::shoot(Entity object, int location)
{

    if ((hitPlayer() == false) && (hitBullet() == false))
    {
        this->_xLoc--;
    }
    if (this->_xLoc == 0)
        setLocation(getMax(Y), location);                      // start loop again
}

bool        Entity::hitPlayer()
{
    int *pLoc = getLocation();
    if (((this->_xLoc == pLoc[0]) && (this->_yLoc == pLoc[1]))       // check for unit collision
    {
        delete this;
        return true
    }
    return false;
}

bool        Entity::hitBullet()
{
    int *pLoc = getLocation();//get player location!!!!
    if (((this->_xLoc == pLoc[0]) && (this->_yLoc == pLoc[1]))       // check for Bullet collision
    {
        delete this;
        return true
    }
    return false;
}
