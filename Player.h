#pragma once

#pragma warning(push, 0)
#include <SFML/Graphics.hpp>
#pragma warning(pop)

class Player {
public:
	Player(float radius, int WIN_WIDTH, int WIN_HEIGHT);
	sf::CircleShape playerObj;
	sf::Vector2f playerPos = playerObj.getPosition();
	float playerRadius;
	float rotation;
	sf::Vector2f getPoint();
	sf::Vector2f move();
	void rotate(float angle);
	void move(float x, float y);
	

private:
	void setOrigin();
	void setPositionCenter(int width, int height);
};