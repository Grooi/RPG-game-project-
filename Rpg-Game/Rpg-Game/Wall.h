#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>
class wall {
public:
	wall(sf::Vector2f, std::string);
	wall();
	void setWall(sf::Vector2f, std::string);
	sf::RectangleShape getCollisionBlock();
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	sf::Texture getTexture();
	std::string type;
private:
	sf::Texture texture;
	sf::Sprite wallPicture;
	sf::RectangleShape collisionBlock;
	sf::Vector2f size = sf::Vector2f(16, 16);
	sf::Vector2f position;
};
#endif