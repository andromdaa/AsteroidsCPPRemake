#include "Collidable.h"


Collidable::Collidable(Sizes size)
{
    Collidable::size = size;
    numPoints = (int)size;
    update();
}

unsigned int Collidable::getPointCount()
{
    return numPoints;
}

sf::Vector2f Collidable::getPoint(unsigned int index) const
{
    return sf::Vector2f();
}
