#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>
#include "Enity.h"
class wall : public Enity{
public:
	wall();
	void setWall(sf::Vector2f, std::string);
private:
	
};
#endif