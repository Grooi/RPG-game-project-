#include <iostream>
#include "Wall.h"

wall::wall(sf::Vector2f position, std::string type) {
	setWall(position, type);
}

wall::wall() {

}

void wall::setWall(sf::Vector2f position, std::string type) {
	this->position = position;
	this->type = type;
	texture.loadFromFile("image\\" + type + ".png");
	wallPicture.setTexture(texture);
	wallPicture.setPosition(position);

	collisionBlock.setSize(size);
	collisionBlock.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	collisionBlock.setTexture(&texture);
	collisionBlock.setFillColor(sf::Color::Transparent);
	collisionBlock.setPosition(position);
}

sf::RectangleShape wall::getCollisionBlock() {
	return collisionBlock;
}

sf::Vector2f wall::getPosition() {
	return position;
}

sf::Sprite wall::getSprite() {
	return wallPicture;
}

sf::Texture wall::getTexture() {
	return texture;
}