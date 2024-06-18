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

template<typename T>
void draw(sf::RenderWindow&, std::vector<T> &);
template<typename T>
void draw(sf::RenderWindow&, std::vector<T>&, std::string);

int main() {
	//�Ыص���
	
	sf::RenderWindow windows(sf::VideoMode(length * size, width * size), "Rpg-Game");
	windows.setSize(sf::Vector2u(750, 500));
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
		LogicJudge::MapChange(Paper, player, windows);
		
		//ø�s
		sprite.loadPicture(Paper.getSheet()[0]);//�̩��h�Ϥ��C�p�K�h:�p�ߤ��n�Q�л\
		for (int d_y = 0; d_y < length; d_y++) {
			for (int d_x = 0; d_x < width; d_x++) {
				sprite.setLocal_imagePosition(d_y, d_x, size);
				windows.draw(sprite.getSprite());
			}
		}
		draw(windows,Paper.wallObject);//ø�s���
		draw(windows, Paper.StairsObject);//ø�s���
		draw(windows, Paper.doorObject,"door");//ø�s��
		draw(windows, Paper.NpcSpace);//ø�sNPC

		windows.draw(player.getSprite());
		windows.draw(player.collisionBlockFace);//����(�D�C�������)
		player.collisionBlockFace.setPosition(*player.getFace());//����(�D�C�������)
		windows.display();
		if (Paper.getNowMap() == "house2.txt") {
			bool winCheck = true;
			for (int i = 0; i < Paper.NpcSpace.size(); i++) {
				if (Paper.NpcSpace[i].getEnityInfo()->hp > 0) winCheck = false;
				break;
			}
			if (winCheck == true) {
				std::cout << "You Win" << std::endl;
				std::cout << "thank you for playing" << std::endl;
				sf::sleep(sf::Time(sf::seconds(5)));
				exit(0);
			}
		}
	}
}

template<typename T>
void draw(sf::RenderWindow& windows, std::vector<T> &data) {
	for (int i = 0; i < data.size(); i++) {
		windows.draw(data[i].getSprite());
	}
}
template<typename T>
void draw(sf::RenderWindow& windows, std::vector<T>& data, std::string type) {
	for (int i = 0; i < data.size(); i++) {
		if (!data[i].getState()) {
			windows.draw(data[i].getSprite());
		}
	}
}