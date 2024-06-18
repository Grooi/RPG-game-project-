#include <iostream>
#include "door.h"

door::door() {
	type = "wooden_door";
	setCollisionBlock(&size);
	state = false;
	lock = false;
}

void door::setState() {
	state = !state;
}

bool door::getState() const {
	return state;
}

void door::LockAndUnlockDoor() {
	lock = !lock;
}

bool door::getLock() {
	return lock;
}

sf::Vector2f* door::getSize() {
	return &size;
}
