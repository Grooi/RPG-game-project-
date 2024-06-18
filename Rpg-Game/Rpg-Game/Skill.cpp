#include <iostream>
#include "Skill.h"

Skill::Skill(double type) {
	//setFuncPtr();
	setSkill(type);
}
Skill::Skill() {
	
}
void Skill::setSkill(double type) {
	if (type == 1) {
		healCheck = true;
		AttackCheck = true;
		weakCheck = true;
	}
	if (type == 2) {
		healCheck = true;
		AttackCheck = true;
		weakCheck = false;
	}
}

int* Skill::HealCD() {
	return &healCD;
}

WeakPage* Skill::weakinfo() {
	return &weakPage;
}

/*
void Skill::setFuncPtr() {
	func[0] = &Attack;
	func[1] = &heal;
}
*/