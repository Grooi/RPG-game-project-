#ifndef OBJECT_H
#define OBJECT_H
#include <SFML/Graphics.hpp>
#include "Skill.h"

class Object {
public:
	Object();
	sf::RectangleShape getCollisionBlock();
	sf::Sprite getSprite();
	void setOrigin(int, int);
	void setCollisionBlock(const sf::Vector2f*);
	void setPosition(const sf::Vector2f);
	sf::Vector2f* getPosition();
	std::string getType();
	sf::Vector2f* getFace();
	void deleteEnity();
protected:
	sf::Vector2f face;
	std::string type;
	sf::RectangleShape collisionBlock;
	sf::Vector2f size = sf::Vector2f(16, 16);
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite Picture;
};
#endif