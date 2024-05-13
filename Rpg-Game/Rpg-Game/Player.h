#ifndef PLYER_H
#define PLYER_H
#include <SFML/Graphics.hpp>
#include "Enity.h"
#include "ObjectSignSheet.h"
#include "Skill.h"

class Player : public Enity{
public:
	Player();
	void Action(ObjectSignSheet&);
	Skill getSkill();
	int MoveCheck();
private:
	sf::Clock clock;
	sf::Vector2f face;
	Skill skill;
};
#endif