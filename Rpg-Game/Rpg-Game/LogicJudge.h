#ifndef LOGICJUDGE_H
#define LOGICJUDGE_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "ObjectSignSheet.h"
#include "Enity.h"
#include "Player.h"
#include "NPC.h"//
#include "Skill.h"//

class LogicJudge {
public:
	static void ImpackCheck(ObjectSignSheet &,Player &);
	static void fight(ObjectSignSheet&, Player&, int);
	static void handle(Enity&, Enity&, double (*func[10])(), int);
private:

};
#endif