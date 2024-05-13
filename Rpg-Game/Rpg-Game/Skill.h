#ifndef SKILL_H
#define SKILL_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class Skill{
public:
	Skill(double);
	Skill();
	void setSkill(double);

	static double Attack();

	static double heal();
	
	int* getHealCD();
	void setFuncPtr();

	double (*func[10])();

private:
	bool AttackCheck = false;
	bool healCheck = false;
	int healCD = 0;
};


#endif