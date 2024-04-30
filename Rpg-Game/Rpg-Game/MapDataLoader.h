#ifndef MAPDATALOADER_H
#define MAPDATALOADER_H
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Wall.h"
#include "ObjectSignSheet.h"

class MapDataLoder {
public:
	static sf::Vector2f findPoint(const std::vector<std::vector<int>>&, const int*, const int*, const int*, int);
	static void setArray(std::vector<std::vector<int>>& , const int*, const int*);
	static void loadMapData(std::vector<std::vector<int>>& , const int*, const int*, std::string);
	static void loadRectangleShapeMap(ObjectSignSheet&, const int*, const int*, const int*);
	static void showMapData(const std::vector<std::vector<int>>,const int* ,const int* );
	static int setDataSize(std::vector<std::vector<int>>&, const int*, const int*, const int);
};
#endif