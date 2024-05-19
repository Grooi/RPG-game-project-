#ifndef DOOR_H
#define DOOR_H
#include <SFML/Graphics.hpp>
#include "Local_image.h"
#include "Object.h"

class door : public Object{
public:
	door();
	void setState();
	bool getState() const;
	void LockAndUnlockDoor();
	bool getLock();

	sf::Vector2f* getSize();
private:
	bool state = false;
	bool lock = false;
};
#endif