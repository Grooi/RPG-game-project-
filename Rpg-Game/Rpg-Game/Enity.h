#ifndef ENITY_H
#define ENITY_H
#include <SFML/Graphics.hpp>

class Enity {
public:
	Enity();
	sf::RectangleShape getCollisionBlock();
	sf::Sprite getSprite();
	void setOrigin(int, int);
	void setCollisionBlock(const sf::Vector2f*);
	void setPosition(const sf::Vector2f);
	void setHp(const double*);
	void setMp(const double*);
	sf::Vector2f* getPosition();
	double* getSpeed();
	double* getHP();
	double* getMP();
	std::string getType();
	void deleteEnity();
protected:
	std::string type;
	sf::RectangleShape collisionBlock;
	sf::Vector2f size = sf::Vector2f(16, 16);
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite Picture;
	double speed = 8;
	double hp = 100;
	double mp = 100;
};
#endif