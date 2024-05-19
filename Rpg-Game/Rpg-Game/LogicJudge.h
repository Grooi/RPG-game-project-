#ifndef LOGICJUDGE_H
#define LOGICJUDGE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "ObjectSignSheet.h"
#include "Enity.h"
#include "Skill.h"
#include "Player.h"
#include "NPC.h"

class LogicJudge {
public:
	static void ImpackCheck(ObjectSignSheet &,Player &);
	static void fight(ObjectSignSheet&, Player&, int);
	static void MapChange(ObjectSignSheet&, Player&, std::string, sf::RenderWindow& windows);
	//static void handle(Enity&, Enity&, double (*func[10])(), int);
private:

};
#endif