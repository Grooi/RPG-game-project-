#ifndef NPC_H
#define NPC_H
#include <SFML/Graphics.hpp>
#include "Enity.h"
#include "Skill.h"

class NPC : public Enity {
public:
	NPC();
	NPC(int, int);
	~NPC();
	sf::Vector2f* getSize();
	Skill getSkill();

	void Action(sf::Clock*);
	int MoveCheck();
private:
	Skill skill;
};
#endif