#ifndef DOOR_H
#define DOOR_H
#include <SFML/Graphics.hpp>
#include "Local_image.h"

class door {
public:
	door(sf::Vector2f, std::string);
	door();
	void setDoor(sf::Vector2f, std::string);
	sf::RectangleShape getCollisionBlock();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	sf::Texture getTexture();
	void updataState();
	void setState();
	bool getState();
	void LockDoor();
	void UnlockDoor();
	bool getLock();
	sf::Vector2f getSize();
	std::string type;
private:
	bool state = false;
	bool lock = false;
	sf::Texture texture;
	sf::Sprite doorPicture;
	sf::RectangleShape collisionBlock;
	const sf::Vector2f size = sf::Vector2f(16, 16);
	sf::Vector2f position;
};
#endif