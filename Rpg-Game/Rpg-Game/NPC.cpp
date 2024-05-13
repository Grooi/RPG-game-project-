#include <iostream>
#include "NPC.h"

NPC::NPC() {
	skill = Skill(2);
	type = "NPC";
	hp = 100;
	mp = 100;
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

Skill NPC::getSkill() {
	return skill;
}

void NPC::Action(sf::Clock* clock) {
	
}

int NPC::MoveCheck() {
	return 0;
}