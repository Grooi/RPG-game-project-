#include <iostream>
#include "Wall.h"

wall::wall() {
	type = "gray_wall";
	setCollisionBlock(&size);
}