#include <iostream>
#include "NPC.h"

NPC::NPC(std::string name, sf::Vector2f position) {
	this->position = position;
	hp = 100;
	mp = 100;
	setCollisionBlock(size, name);
}

NPC::NPC() {
	
}

void NPC::setCollisionBlock(const sf::Vector2f size, std::string name) {
	this->name = name;
	texture.loadFromFile("image\\" + name + ".png");
	collisionBlock1.setSize(size);
	PlayerPicture.setTexture(texture);
	PlayerPicture.setPosition(position);

	collisionBlock1.setTextureRect(sf::IntRect(0, 0, size.x, size.y));
	collisionBlock1.setTexture(&texture);
	collisionBlock1.setOutlineThickness(0.0f);
	collisionBlock1.setOutlineColor(sf::Color::Blue);
	collisionBlock1.setFillColor(sf::Color::Transparent);
	collisionBlock1.setPosition(position);
}

void NPC::setPosition(const sf::Vector2f position) {
	this->position = position;
	PlayerPicture.setPosition(this->position);
	collisionBlock1.setPosition(this->position);
}

void NPC::setOrigin(int a, int b) {
	collisionBlock1.setOrigin(a, b);
}

void NPC::setHp(const double* input) {
	hp += *input;
}

void NPC::setMp(const double* input) {
	mp += *input;
}

sf::Sprite NPC::getSprite() {
	return PlayerPicture;
}

sf::RectangleShape NPC::getCollisionBlock1() {
	return collisionBlock1;
}

sf::Vector2f NPC::getPosition() {
	return position;
}

sf::Vector2f NPC::getSize() {
	return size;
}

double* NPC::getSpeed() {
	return &speed;
}

void NPC::Action(sf::Clock* clock) {
	
}

int NPC::MoveCheck() {
	return 0;
}