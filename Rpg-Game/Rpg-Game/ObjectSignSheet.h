#ifndef OBJECTSIGNSHEET_H
#define OBJECTSIGNSHEET_H
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include "Wall.h"
#include "door.h"
#include "NPC.h"

class ObjectSignSheet {
public:
	ObjectSignSheet(int*, int*, int*);
	void sign(double, std::string);
	void setNpcSpace(int*, int*, int*, double);
	void setWallObject(int*, int*, int*, double);
	void setDoorObject(int*, int*, int*, double);

	void mapUpdata(std::string);

	std::map<int, std::string> getSheet();

	std::vector<sf::RectangleShape> RectangleShapeMap;
	std::vector<std::vector<int>> MapData;
	std::vector<wall> wallObject;
	std::vector<door> doorObject;
	std::vector<NPC> NpcSpace;

private:
	int length, width;
	std::map<int, std::string> PictureSheet;
	std::map<int, std::string> Sheet;
};
#endif