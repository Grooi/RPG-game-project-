#ifndef PLYER_H
#define PLYER_H
#include <SFML/Graphics.hpp>
#include "ObjectSignSheet.h"

class Player {
public:
	Player();
	sf::RectangleShape getCollisionBlock1();
	sf::Sprite getSprite();
	void setOrigin(int ,int );
	void setCollisionBlock(const sf::Vector2f*);
	void setPosition(const sf::Vector2f);
	void setHp(const double*);
	void setMp(const double*);
	sf::Vector2f* getPosition();
	double* getSpeed();

	void Action(ObjectSignSheet&);
	int MoveCheck();
private:
	sf::Clock clock;
	sf::Texture texture;
	sf::Sprite PlayerPicture;
	sf::RectangleShape collisionBlock1;
	sf::Vector2f position;
	sf::Vector2f size = sf::Vector2f(16, 16);
	sf::Vector2f face;
	double speed = 8;
	double hp = 100;
	double mp = 100;
};
#endif