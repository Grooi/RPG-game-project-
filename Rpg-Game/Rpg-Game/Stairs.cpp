#include <iostream>
#include "Stairs.h"

Stairs::Stairs() {
	type = "stairs";
	setCollisionBlock(&size);
}