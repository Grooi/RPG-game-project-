#ifndef ENITY_H
#define ENITY_H
#include <SFML/Graphics.hpp>
#include <string>
#include "Skill.h"

struct EnityInfo {
	double hp = 1;
	double mp = 1;
	double ATK = 1;
	double speed = 8;
	double Defense = 1;
};
class Enity {
public:
	Enity();
	void setEnityInfo(const EnityInfo*);
	const EnityInfo* getEnityInfo();
	void setOriginEnityInfo();
	const EnityInfo* getOriginEnityInfo();
	Skill* getSkill();
	std::string* getName();
protected:
	std::string name;
	EnityInfo info;
	EnityInfo Origin_info;
	Skill skill;
};
#endif