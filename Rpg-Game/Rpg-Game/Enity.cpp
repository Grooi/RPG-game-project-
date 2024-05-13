#include <iostream>
#include "Enity.h"

Enity::Enity() {

}

void Enity::setCollisionBlock(const sf::Vector2f* size) {
	texture.loadFromFile("image\\" + type + ".png");
	
	Picture.setTexture(texture);
	Picture.setPosition(position);

	collisionBlock.setSize(*size);
	collisionBlock.setTextureRect(sf::IntRect(0, 0, size->x, size->y));
	collisionBlock.setTexture(&texture);
	collisionBlock.setFillColor(sf::Color::Blue);
	collisionBlock.setPosition(position);
}

void Enity::setPosition(const sf::Vector2f position) {
	this->position = position;
	Picture.setPosition(this->position);
	collisionBlock.setPosition(this->position);
}

void Enity::setOrigin(int a, int b) {
	collisionBlock.setOrigin(a, b);
}

void Enity::setHp(const double* input) {
	hp += *input;
}

void Enity::setMp(const double* input) {
	mp += *input;
}

sf::Sprite Enity::getSprite() {
	return Picture;
}

sf::RectangleShape Enity::getCollisionBlock() {
	return collisionBlock;
}

sf::Vector2f* Enity::getPosition() {
	return &position;
}

double* Enity::getSpeed() {
	return &speed;
}

double* Enity::getHP() {
	return &hp;
}
double* Enity::getMP() {
	return &mp;
}

std::string Enity::getType() {
	return type;
}

void Enity::deleteEnity() {
	delete this;
}