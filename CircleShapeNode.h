#pragma once
#include <SFML/Graphics.hpp>


class CircleShapeNode
{
public:
	CircleShapeNode();
	CircleShapeNode(sf::CircleShape shape);
	sf::CircleShape* node;
	CircleShapeNode* next = nullptr;
	CircleShapeNode* prev = nullptr;
	void deleteNode();
	CircleShapeNode* addNode(CircleShapeNode newNode);
};

