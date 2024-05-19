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
#include "LogicJudge.h";
#include "Object.h"

static int width = 25, length = 25, size = 16;

int main() {
	//創建視窗
	
	sf::RenderWindow windows(sf::VideoMode(length * size, width * size), "Rpg-Game");
	windows.setFramerateLimit(20);
	windows.setVerticalSyncEnabled(true);
	system("mode con cols=50 lines=25");
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
	//MapDataLoder::loadRectangleShapeMap(Paper, &width, &length, &size);

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
		LogicJudge::ImpackCheck(Paper, player);
		LogicJudge::MapChange(Paper, player, "house2", windows);
		
		//更新資料
		

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
		for (int i = 0; i < Paper.StairsObject.size(); i++) {//繪製牆壁
			windows.draw(Paper.StairsObject[i].getSprite());
		}
		for (int i = 0; i < Paper.doorObject.size(); i++) {//繪製門
			if (!Paper.doorObject[i].getState()) {
				windows.draw(Paper.doorObject[i].getSprite());
			}
		}
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {//繪製NPC
			windows.draw(Paper.NpcSpace[i].getSprite());
		}
		
		//Paper.mapUpdata("house2.txt", size);
		windows.draw(player.getSprite());
		windows.draw(player.collisionBlockFace);//測試(非遊玩時顯示)
		player.collisionBlockFace.setPosition(*player.getFace());
		windows.display();
	}
}