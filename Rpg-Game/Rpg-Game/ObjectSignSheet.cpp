#include "ObjectSignSheet.h"
#include "MapDataLoader.h"

ObjectSignSheet::ObjectSignSheet(int* length, int* width, int* size) {
	Sheet[1] = "playerUp";
	Sheet[1.1] = "playerLeft";
	Sheet[1.2] = "playerRight";
	Sheet[1.3] = "playerDown";
	Sheet[3] = "NPC";
	Sheet[0] = "wooden_floor";
	Sheet[2] = "gray_wall";
	Sheet[4] = "wooden_door";
	Sheet[5] = "stairs";
	//���J�a�ϸ��
	MapDataLoder::setArray(MapData, length, width);
	MapDataLoder::loadMapData(MapData, length, width, "house.txt");

	setWallObject(length, width, size, 2);

	setDoorObject(length, width, size, 4);
	
	setNpcSpace(length, width, size, 3);

	std::cout << "Paper.created" << std::endl;
}

void ObjectSignSheet::setWallObject(int* length, int* width, int* size, double type) {
	wallObject.resize(wallObject.size() + MapDataLoder::setDataSize(MapData, width, length, type));
	for (int i = 0; i < wallObject.size(); i++) {
		wallObject[i].setWall(MapDataLoder::findPoint(MapData, width, length, size, type), Sheet[type]);
		MapData[wallObject[i].getPosition().y / (*size)][wallObject[i].getPosition().x / (*size)] = 0;
	}
}

void ObjectSignSheet::setDoorObject(int* length, int* width, int* size, double type) {
	doorObject.resize(doorObject.size() + MapDataLoder::setDataSize(MapData, width, length, type));
	for (int i = 0; i < doorObject.size(); i++) {
		doorObject[i].setDoor(MapDataLoder::findPoint(MapData, width, length, size, type), Sheet[type]);
		MapData[doorObject[i].getPosition().y / (*size)][doorObject[i].getPosition().x / (*size)] = 0;
	}
}

void  ObjectSignSheet::setNpcSpace(int* length, int* width, int* size, double type) {
	NpcSpace.resize(NpcSpace.size() + MapDataLoder::setDataSize(MapData, width, length, type));
	for (int i = 0; i < NpcSpace.size(); i++) {
		NpcSpace[i].setPosition(MapDataLoder::findPoint(MapData, width, length, size, 3));
		NpcSpace[i].setCollisionBlock(NpcSpace[i].getSize(), Sheet[type]);
		MapData[NpcSpace[i].getPosition().y / (*size)][NpcSpace[i].getPosition().x / (*size)] = 0;
	}
}

void ObjectSignSheet::sign(double key, std::string name){
	Sheet[key] = name;
}

std::map<int, std::string> ObjectSignSheet::getSheet() {
	return Sheet;
}