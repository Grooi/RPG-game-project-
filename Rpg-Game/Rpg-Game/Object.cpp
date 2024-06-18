#include <iostream>
#include "Object.h"

Object::Object() {

}

void Object::setCollisionBlock(const sf::Vector2f* size) {
	texture.loadFromFile("image\\" + type + ".png");
	
	Picture.setTexture(texture);
	Picture.setPosition(position);

	collisionBlock.setSize(*size);
	collisionBlock.setTextureRect(sf::IntRect(0, 0, size->x, size->y));
	collisionBlock.setTexture(&texture);
	collisionBlock.setFillColor(sf::Color::Blue);
	collisionBlock.setPosition(position);

	face = sf::Vector2f(position);
}

void Object::setPosition(const sf::Vector2f position) {
	face -= this->position - position;
	this->position = position;
	Picture.setPosition(this->position);
	collisionBlock.setPosition(this->position);
}

void Object::setOrigin(int a, int b) {
	collisionBlock.setOrigin(a, b);
}

sf::Sprite Object::getSprite() {
	return Picture;
}

sf::RectangleShape* Object::getCollisionBlock() {
	return &collisionBlock;
}

sf::Vector2f* Object::getPosition() {
	return &position;
}

std::string Object::getType() {
	return type;
}

sf::Vector2f* Object::getFace() {
	return &face;
}

void Object::deleteEnity() {
	delete this;
}