#ifndef NPC_H
#define NPC_H
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Enity.h"
#include "Skill.h"

class NPC : public Object , public Enity {
public:
	NPC();
	NPC(int, int);
	~NPC();
	sf::Vector2f* getSize();
	void Action(sf::Clock*);
	int MoveCheck();
private:
};
#endif