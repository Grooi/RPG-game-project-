#include <iostream>
#include "LogicJudge.h";
#include "Player.h"

Player::Player() {
	skill = Skill(1);
	type = "player";
	hp = 200;
	mp = 100;
	setCollisionBlock(&size);
}

void Player::Action(ObjectSignSheet& Paper) {
	sf::Vector2f ActionPosition = position;
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
					Paper.doorObject[i].setState();
					break;
				}
			}
		}//open and close door
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {//door
			if (sf::FloatRect(face, size).intersects(Paper.NpcSpace[i].getCollisionBlock().getGlobalBounds())) {
				LogicJudge::fight(Paper, *this ,i);
			}
		}//NPC FIGHT
		break;
	default:
		break;
	}
}

Skill Player::getSkill() {
	return skill;
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