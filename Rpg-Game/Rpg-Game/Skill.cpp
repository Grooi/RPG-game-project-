#include <iostream>
#include "Skill.h"

Skill::Skill(double type) {
	setFuncPtr();
	setSkill(type);
}
Skill::Skill() {
	
}
void Skill::setSkill(double type) {
	if (type == 1) {
		healCheck = true;
		AttackCheck = true;
	}
	if (type == 2) {
		healCheck = true;
		AttackCheck = true;
	}
}

double Skill::Attack() {
	return -10;
}

double Skill::heal() {
	return 15;
}

int* Skill::getHealCD() {
	return &healCD;
}

void Skill::setFuncPtr() {
	func[0] = &Attack;
	func[1] = &heal;
}
