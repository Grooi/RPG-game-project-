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
	//�Ыص���
	
	sf::RenderWindow windows(sf::VideoMode(length * size, width * size), "Rpg-Game");
	windows.setFramerateLimit(20);
	windows.setVerticalSyncEnabled(true);
	system("mode con cols=50 lines=25");
	//�Ыظ���x�s�Ŷ�
	ObjectSignSheet Paper(&length, &width, &size);//��ƪ��
	//�ЫعϤ�
	Local_image sprite("white");
	//�Ы�Player
	Player player;
	{
		player.setPosition(MapDataLoder::findPoint(Paper.MapData, &width, &length, &size, 1));
		Paper.MapData[player.getPosition()->y / size][player.getPosition()->x / size] = 0;
		
	}//�M��@�}�l���a����m
	//�p�ɾ�
	sf::Clock clock;
	sf::Time delayTime = (sf::seconds(0.01f));
	//��J�ƥ�
	sf::Event event;
	bool FirstCheck = true;//�˴��O�_�O�Ĥ@�����J
	//���J�������
	//MapDataLoder::loadRectangleShapeMap(Paper, &width, &length, &size);

	//�C���`��
	while (windows.isOpen()) {
		windows.clear();
		while (windows.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {//��������
				windows.close();
				std::cout << "Closed" << std::endl;
			}
		}
		//�ƥ�B�z
		player.Action(Paper);
		LogicJudge::ImpackCheck(Paper, player);
		LogicJudge::MapChange(Paper, player, "house2", windows);
		
		//��s���
		

		//ø�s
		sprite.loadPicture(Paper.getSheet()[0]);//�̩��h�Ϥ��C�p�K�h:�p�ߤ��n�Q�л\
		for (int d_y = 0; d_y < length; d_y++) {
			for (int d_x = 0; d_x < width; d_x++) {
				sprite.setLocal_imagePosition(d_y, d_x, size);
				windows.draw(sprite.getSprite());
			}
		}
		for(int i = 0; i < Paper.wallObject.size(); i++) {//ø�s���
			windows.draw(Paper.wallObject[i].getSprite());
		}
		for (int i = 0; i < Paper.StairsObject.size(); i++) {//ø�s���
			windows.draw(Paper.StairsObject[i].getSprite());
		}
		for (int i = 0; i < Paper.doorObject.size(); i++) {//ø�s��
			if (!Paper.doorObject[i].getState()) {
				windows.draw(Paper.doorObject[i].getSprite());
			}
		}
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {//ø�sNPC
			windows.draw(Paper.NpcSpace[i].getSprite());
		}
		
		//Paper.mapUpdata("house2.txt", size);
		windows.draw(player.getSprite());
		windows.draw(player.collisionBlockFace);//����(�D�C�������)
		player.collisionBlockFace.setPosition(*player.getFace());
		windows.display();
	}
}