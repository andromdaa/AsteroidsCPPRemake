#include "Player.h"

Player::Player(float radius, int WIN_WIDTH, int WIN_HEIGHT)
{
	playerRadius = radius;
	playerObj = sf::CircleShape(playerRadius, 3);
	Player::setOrigin();
	Player::setPositionCenter(WIN_WIDTH, WIN_HEIGHT);
}

void Player::setOrigin()
{
	playerObj.setOrigin(playerRadius, playerRadius);
}

void Player::rotate(float angle)
{
	 playerObj.rotate(angle);
	 rotation = playerObj.getRotation();
}

void Player::move(float x, float y)
{
	playerObj.move(x, y);
	playerPos = playerObj.getPosition();
}

void Player::setPositionCenter(int width, int height)
{
	playerObj.setPosition(width / 2, height / 2);
	playerPos = playerObj.getPosition();
}

sf::Vector2f Player::getPoint() {
	return playerObj.getTransform().transformPoint(playerObj.getPoint(0));
}