#include <iostream>
#include "MapDataLoader.h"

void MapDataLoder::setArray(std::vector<std::vector<int>>& A, const int* width, const int* length) {
	std::vector<int> arr(*width, 0);
	for (int y = 0; y < *length; y++) {
		for (int x = 0; x < *width; x++) {
			A.push_back(arr);
		}
	}
}

void MapDataLoder::loadMapData(std::vector<std::vector<int>>& A, const int* width, const int* length, std::string type) {
	std::stringstream ss;
	std::string str = "Map\\", cache, name;
	str.append(type);
	int line = 0, x = 0, y = 0;
	std::ifstream mapLoader;
	mapLoader.open(str);
	if (!mapLoader.is_open()) {
		std::cout << "Map_loader failed" << std::endl;
	}
	for (int y = 0; y < *length; y++) {
		std::getline(mapLoader, cache);
		ss << cache;
		for (int x = 0; x < *width; x++) {
			ss >> A[y][x];
		}
		ss.clear();
	}
	mapLoader.close();
}

void MapDataLoder::loadRectangleShapeMap(ObjectSignSheet& Paper, const int* width, const int* length, const int* size) {
	Paper.RectangleShapeMap.resize(Paper.wallObject.size() + Paper.doorObject.size());
	int count = 0;
	for (int i = 0; i < Paper.wallObject.size(); i++) {
		Paper.RectangleShapeMap[i] = *Paper.wallObject[i].getCollisionBlock();
	}

	for (int i = Paper.wallObject.size(); i < Paper.RectangleShapeMap.size(); i++) {
		Paper.RectangleShapeMap[i] = *Paper.doorObject[count].getCollisionBlock();
		count++;
	}

}

void MapDataLoder::showMapData(const std::vector<std::vector<int>> A, const int* width, const int* length) {
	for (int i = 0; i < *length; i++) {
		for (int c = 0; c < *width; c++) {
			std::cout << A[i][c];
		}
		std::cout << std::endl;
	}
}

sf::Vector2f MapDataLoder::findPoint(const std::vector<std::vector<int>>& mapData, const int* width, const int* length, const int* size, int type) {
	sf::Vector2f position;
	for (int y = 0; y < *length; y++) {
		for (int x = 0; x < *width; x++) {
			if (mapData[y][x] == type) {
				position.x = x * (*size);
				position.y = y * (*size);
				return position;
			}
		}
	}
	return sf::Vector2f(0, 0);
}

int MapDataLoder::setDataSize(std::vector<std::vector<int>>& mapData, const int* width, const int* length, const int type) {
	int count = 0;
	for (int y = 0; y < *length; y++) {
		for (int x = 0; x < *width; x++) {
			if (mapData[y][x] == type) {
				count++;
			}
		}
	}
	return count;
}
