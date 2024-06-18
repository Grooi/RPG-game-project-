#ifndef SKILL_H
#define SKILL_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>

struct WeakPage{
	int weakCD = 0;
	int weakTime = 0;
};
class Skill{
public:
	Skill(double);
	Skill();
	void setSkill(double);

	WeakPage* weakinfo();

	int* HealCD();

	//void setFuncPtr();

	//double (*func[10])();

private:
	bool AttackCheck = false;
	bool healCheck = false;
	bool weakCheck = false;
	int healCD = 0;
	WeakPage weakPage;
};


#endif