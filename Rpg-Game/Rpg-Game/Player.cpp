#include <iostream>
#include "Player.h"

Player::Player() {
	position = sf::Vector2f(23,23);
	hp = 100;
	mp = 100;
	setCollisionBlock(&size);
}

void Player::setCollisionBlock(const sf::Vector2f* size) {
	texture.loadFromFile("image\\player.png");
	collisionBlock1.setSize(*size);
	PlayerPicture.setTexture(texture);
	PlayerPicture.setPosition(position);

	collisionBlock1.setTextureRect(sf::IntRect(0, 0, size->x, size->y));
	collisionBlock1.setTexture(&texture);
	collisionBlock1.setOutlineThickness(0.0f);
	collisionBlock1.setOutlineColor(sf::Color::Blue);
	collisionBlock1.setFillColor(sf::Color::Blue);
	collisionBlock1.setPosition(position);

	face = sf::Vector2f(position.x, position.y - 1);
}

void Player::setPosition(const sf::Vector2f position) {
	this->position = position;
	PlayerPicture.setPosition(this->position);
	collisionBlock1.setPosition(this->position);
}

void Player::setOrigin(int a,int b) {
	collisionBlock1.setOrigin(a, b);
}

void Player::setHp(const double* input) {
	hp += *input;
}

void Player::setMp(const double* input) {
	mp += *input;
}

sf::Sprite Player::getSprite() {
	return PlayerPicture;
}

sf::RectangleShape Player::getCollisionBlock1() {
	return collisionBlock1;
}

sf::Vector2f* Player::getPosition() {
	return &position;
}

double* Player::getSpeed() {
	return &speed;
}

void Player::Action(ObjectSignSheet& Paper) {
	sf::Vector2f ActionPosition = position;
	bool door = false;
	int index = 0;
	switch (MoveCheck()) {
	case 0:
		face = sf::Vector2f(position.x - (size.x), position.y);
		ActionPosition.x -= speed;
		setPosition(ActionPosition);
		break;
	case 1:
		face = sf::Vector2f(position.x, position.y - (size.y));
		ActionPosition.y -= speed;
		setPosition(ActionPosition);
		break;
	case 2:
		face = sf::Vector2f(position.x + (size.x), position.y);
		ActionPosition.x += speed;
		setPosition(ActionPosition);
		break;
	case 3:
		face = sf::Vector2f(position.x, position.y + (size.y));
		ActionPosition.y += speed;
		setPosition(ActionPosition);
		break;
	case 4:
		for (int i = 0; i < Paper.doorObject.size(); i++) {//door
			if (sf::FloatRect(face, size).intersects(Paper.doorObject[i].getCollisionBlock().getGlobalBounds())) {
				if (Paper.doorObject[i].getLock() != true) {
					door = true;
					index = i;
					break;
				}
			}
		}
		for (int i = 0; i < Paper.RectangleShapeMap.size() && door == true; i++) {
			if (Paper.RectangleShapeMap[i].getPosition() == Paper.doorObject[index].getPosition()) {
				Paper.doorObject[index].setState();
				Paper.doorObject[index].getState() == false ? Paper.RectangleShapeMap[i].setSize(Paper.doorObject[index].getSize())
				:Paper.RectangleShapeMap[i].setSize(sf::Vector2f(0, 0));
				break;
			}
		}//door

		break;
	default:
		break;
	}
}

int Player::MoveCheck(){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		return 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		return 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		return 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		return 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && clock.getElapsedTime() > sf::Time(sf::seconds(0.5f))) {
		clock.restart();
		return 4;
	}
	return 5;
}