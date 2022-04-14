#pragma once
#include <SFML/Graphics.hpp>
class Collidable : public sf::Shape
{
public:
	enum class Sizes { UNKN = NULL, SM = 3, MED = 5, LRG = 7 };
	Sizes size = Sizes::UNKN;
	explicit Collidable(Sizes size);
	int numPoints = 0;
	virtual unsigned int getPointCount();
	virtual sf::Vector2f getPoint(unsigned int index) const;
private:
	sf::Vector2f m_radius;
};

