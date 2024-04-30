#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <map>
#include "Local_image.h"
#include "MapDataLoader.h"
#include "ObjectSignSheet.h"
#include "Player.h"
#include "NPC.h"
#include "Wall.h"
#include "ImpactCheck.h";
//型別定義資源
#include "CustomizeType.h"


int main() {
	//創建視窗
	int width = 25, length = 25, size = 16;
	sf::RenderWindow windows(sf::VideoMode(length * size, width * size), "Rpg-Game");
	windows.setFramerateLimit(20);
	windows.setVerticalSyncEnabled(true);
	//創建資料儲存空間
	ObjectSignSheet Paper(&length, &width, &size);//資料表單
	//創建圖片
	Local_image sprite("white");
	//創建Player
	Player player;
	{
		player.setPosition(MapDataLoder::findPoint(Paper.MapData, &width, &length, &size, 1));
		Paper.MapData[player.getPosition()->y / size][player.getPosition()->x / size] = 0;
		
	}//尋找一開始玩家的位置
	//計時器
	sf::Clock clock;
	sf::Time delayTime = (sf::seconds(0.01f));
	//輸入事件
	sf::Event event;
	bool FirstCheck = true;//檢測是否是第一次載入
	//載入牆壁物件
	MapDataLoder::loadRectangleShapeMap(Paper, &width, &length, &size);
	/*
	for (int y = 0; y < length; y++) {//查看RectangleShapeMap內容
		for (int x = 0; x < width; x++) {
			std::cout << "[ x:" << Paper.RectangleShapeMap[y][x].getPosition().x/16 ;
			std::cout << " y:" << Paper.RectangleShapeMap[y][x].getPosition().y/16 << "]" << std::endl;
		}
		std::cout << std::endl;
	}
	*/
	//遊戲循環
	while (windows.isOpen()) {
		windows.clear();
		while (windows.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {//關閉視窗
				windows.close();
				std::cout << "Closed" << std::endl;
			}
		}
		//事件處理
		player.Action(Paper);
		player.setPosition(ImpackChecker::ImpackCheck_StaticObject(Paper.RectangleShapeMap, player.getCollisionBlock1(), &size, player.getSpeed()));
		player.setPosition(ImpackChecker::ImpackCheck_Enity(Paper.NpcSpace, player, &size));
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {
			Paper.NpcSpace[i].setPosition(ImpackChecker::ImpackCheck_StaticObject(Paper.RectangleShapeMap, Paper.NpcSpace[i].getCollisionBlock1(), &size, Paper.NpcSpace[i].getSpeed()));
		}

		//更新資料
		//MapDataLoder::loadRectangleShapeMap(Paper.RectangleShapeMap, player.getCollisionBlock1(), &width, &length, &size);
		//繪製
		sprite.loadPicture(Paper.getSheet()[0]);//最底層圖片。小貼士:小心不要被覆蓋
		for (int d_y = 0; d_y < length; d_y++) {
			for (int d_x = 0; d_x < width; d_x++) {
				sprite.setLocal_imagePosition(d_y, d_x, size);
				windows.draw(sprite.getSprite());
			}
		}
		for(int i = 0; i < Paper.wallObject.size(); i++) {//繪製牆壁
			windows.draw(Paper.wallObject[i].getSprite());
		}
		for (int i = 0; i < Paper.doorObject.size(); i++) {//繪製門
			if (!Paper.doorObject[i].getState()) {
				windows.draw(Paper.doorObject[i].getSprite());
			}
		}
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {//繪製NPC
			windows.draw(Paper.NpcSpace[i].getSprite());
		}
		
		windows.draw(player.getSprite());
		//windows.draw(player.getCollisionBlock1());//測試(非遊玩時顯示)
		windows.display();
	}
}