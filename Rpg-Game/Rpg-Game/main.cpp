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
//���O�w�q�귽
#include "CustomizeType.h"


int main() {
	//�Ыص���
	int width = 25, length = 25, size = 16;
	sf::RenderWindow windows(sf::VideoMode(length * size, width * size), "Rpg-Game");
	windows.setFramerateLimit(20);
	windows.setVerticalSyncEnabled(true);
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
	MapDataLoder::loadRectangleShapeMap(Paper, &width, &length, &size);
	/*
	for (int y = 0; y < length; y++) {//�d��RectangleShapeMap���e
		for (int x = 0; x < width; x++) {
			std::cout << "[ x:" << Paper.RectangleShapeMap[y][x].getPosition().x/16 ;
			std::cout << " y:" << Paper.RectangleShapeMap[y][x].getPosition().y/16 << "]" << std::endl;
		}
		std::cout << std::endl;
	}
	*/
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
		player.setPosition(ImpackChecker::ImpackCheck_StaticObject(Paper.RectangleShapeMap, player.getCollisionBlock1(), &size, player.getSpeed()));
		player.setPosition(ImpackChecker::ImpackCheck_Enity(Paper.NpcSpace, player, &size));
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {
			Paper.NpcSpace[i].setPosition(ImpackChecker::ImpackCheck_StaticObject(Paper.RectangleShapeMap, Paper.NpcSpace[i].getCollisionBlock1(), &size, Paper.NpcSpace[i].getSpeed()));
		}

		//��s���
		//MapDataLoder::loadRectangleShapeMap(Paper.RectangleShapeMap, player.getCollisionBlock1(), &width, &length, &size);
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
		for (int i = 0; i < Paper.doorObject.size(); i++) {//ø�s��
			if (!Paper.doorObject[i].getState()) {
				windows.draw(Paper.doorObject[i].getSprite());
			}
		}
		for (int i = 0; i < Paper.NpcSpace.size(); i++) {//ø�sNPC
			windows.draw(Paper.NpcSpace[i].getSprite());
		}
		
		windows.draw(player.getSprite());
		//windows.draw(player.getCollisionBlock1());//����(�D�C�������)
		windows.display();
	}
}