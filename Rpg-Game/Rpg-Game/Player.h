#ifndef PLYER_H
#define PLYER_H
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Enity.h"
#include "ObjectSignSheet.h"

class Player : public Object, public Enity {
public:
	Player();
	void Action(ObjectSignSheet&);
	int MoveCheck();
	sf::RectangleShape collisionBlockFace;
private:
	sf::Clock clock;
};
#endif