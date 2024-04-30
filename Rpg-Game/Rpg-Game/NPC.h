#ifndef NPC_H
#define NPC_H
#include <SFML/Graphics.hpp>

class NPC {
public:
	NPC(std::string, sf::Vector2f);
	NPC();
	sf::RectangleShape getCollisionBlock1();
	sf::Sprite getSprite();
	void setOrigin(int, int);
	void setCollisionBlock(const sf::Vector2f, std::string);
	void setPosition(const sf::Vector2f);
	void setHp(const double*);
	void setMp(const double*);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	double* getSpeed();

	void Action(sf::Clock*);
	int MoveCheck();
private:
	std::string name;
	sf::Texture texture;
	sf::Sprite PlayerPicture;
	sf::RectangleShape collisionBlock1;
	sf::Vector2f position;
	sf::Vector2f size = sf::Vector2f(16, 16);
	double speed = 8;
	double hp = 100;
	double mp = 100;
};
#endif