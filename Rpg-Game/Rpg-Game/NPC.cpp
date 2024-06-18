#include <iostream>
#include "NPC.h"

NPC::NPC() {
	skill = Skill(2);
	type = "NPC";
	name = "NPC";
	info.hp = 100;
	info.mp = 100;
	info.ATK = 10;
	info.Defense = 1;
	info.speed = 8;
	setOriginEnityInfo();
	setCollisionBlock(&size);
}

NPC::NPC(int a, int b) {
	
}

NPC::~NPC() {
	std::cout << "Delete " << type << " success " << std::endl;
}

sf::Vector2f* NPC::getSize() {
	return &size;
}

void NPC::Action(sf::Clock* clock) {
	sf::Vector2f ActionPosition = position;
	
	
}

int NPC::MoveCheck() {
	return 0;
}