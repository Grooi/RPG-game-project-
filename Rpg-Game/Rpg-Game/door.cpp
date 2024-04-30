#include <iostream>
#include "door.h"

door::door(sf::Vector2f position, std::string type) {
	setDoor(position, type);
}

door::door() {

}

void door::setDoor(sf::Vector2f position, std::string type) {
	this->position = position;
	this->type = type;
	texture.loadFromFile("image\\" + type + ".png");
	doorPicture.setTexture(texture);
	doorPicture.setPosition(position);

	collisionBlock.setSize(size);
	collisionBlock.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	collisionBlock.setTexture(&texture);
	collisionBlock.setFillColor(sf::Color::Blue);
	collisionBlock.setPosition(position);

	state = false;
	lock = false;
}

void door::updataState() {
	
}

void door::setState() {
	state = !state;
}

bool door::getState() {
	return state;
}

void door::LockDoor() {
	lock = true;
}

void door::UnlockDoor() {
	lock = false;
}

bool door::getLock() {
	return lock;
}

sf::Vector2f door::getSize() {
	return size;
}

sf::RectangleShape door::getCollisionBlock() {
	return collisionBlock;
}

sf::Vector2f door::getPosition() {
	return position;
}

sf::Sprite door::getSprite() {
	return doorPicture;
}

sf::Texture door::getTexture() {
	return texture;
}
