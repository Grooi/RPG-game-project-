#include <iostream>
#include "Enity.h"

Enity::Enity() {

}

void Enity::setEnityInfo(const EnityInfo* newData) {
	info = *newData;
}

const EnityInfo* Enity::getEnityInfo(){
	return &info;
}

void Enity::setOriginEnityInfo() {
	Origin_info = info;
}

const EnityInfo* Enity::getOriginEnityInfo() {
	return &Origin_info;
}

Skill* Enity::getSkill() {
	return &skill;
}

std::string* Enity::getName() {
	return &name;
}