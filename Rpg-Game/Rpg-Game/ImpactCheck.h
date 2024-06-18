#ifndef IMPACTCHECK_H
#define IMPACTCHECK_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "NPC.h"

class ImpackChecker {
public:
	static sf::Vector2f ImpackCheck_StaticObject(std::vector<sf::RectangleShape>&, sf::RectangleShape, int*, double*);
	static sf::Vector2f ImpackCheck_Enity(std::vector<NPC>&, Player, int*);
private:

};
#endif