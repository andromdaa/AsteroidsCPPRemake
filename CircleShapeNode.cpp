#include "CircleShapeNode.h"




CircleShapeNode::CircleShapeNode()
{
}

CircleShapeNode::CircleShapeNode(sf::CircleShape shape)
{
	node = &shape;
	next = nullptr;
	prev = nullptr;
}

void CircleShapeNode::deleteNode()
{
	if (next == nullptr) {
		delete(this);
		return;
	}

	this->prev->next = this->next;
	this->next->prev = this->prev;
	delete(this);

	return;

}

CircleShapeNode* CircleShapeNode::addNode(CircleShapeNode newNode)
{
	next = newNode.next;
	prev = newNode.prev;
	node = newNode.node;
	return this;
}

