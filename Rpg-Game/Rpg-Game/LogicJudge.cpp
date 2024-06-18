#include <iostream>
#include <random>
#include <time.h>
#include "LogicJudge.h"

void handle(Enity& A, Enity& B, int chioce);
void TimeCheck(Enity& A, Enity& B, int& CD, std::string type);
void printEnityInfo(Enity& A);
void Attack(Enity& A, Enity& B);
void heal(Enity& A);
void Weak(Enity& A, Enity& B);

void LogicJudge::ImpackCheck(ObjectSignSheet &Paper, Player &player) {
	//////////////////////////////////////////DoorImpact
	for (int i = 0; i < Paper.doorObject.size(); i++) {
		if (Paper.doorObject[i].getCollisionBlock()->getGlobalBounds().intersects//for Player
		(player.getCollisionBlock()->getGlobalBounds()) && Paper.doorObject[i].getState() == false) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.doorObject[i].getPosition()));
		}
		for (int j = 0; j < Paper.NpcSpace.size(); j++) {//for NPC
			if (Paper.doorObject[i].getCollisionBlock()->getGlobalBounds().intersects
			(Paper.NpcSpace[j].getCollisionBlock()->getGlobalBounds())) {
			}
		}
	}
	//////////////////////////////////////////WallImpact
	for (int i = 0; i < Paper.wallObject.size(); i++) {
		if (Paper.wallObject[i].getCollisionBlock()->getGlobalBounds().intersects//for Player
		(player.getCollisionBlock()->getGlobalBounds())) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.wallObject[i].getPosition()));
		}
		for (int j = 0; j < Paper.NpcSpace.size(); j++) {//for NPC
			if (Paper.wallObject[i].getCollisionBlock()->getGlobalBounds().intersects
			(Paper.NpcSpace[j].getCollisionBlock()->getGlobalBounds())) {

			}
		}
	}

	//////////////////////////////////////////NPCImpact
	for (int i = 0; i < Paper.NpcSpace.size(); i++) {
		if (Paper.NpcSpace[i].getCollisionBlock()->getGlobalBounds().intersects
		(player.getCollisionBlock()->getGlobalBounds())) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.NpcSpace[i].getPosition()));
		}
	}
}

void LogicJudge::MapChange(ObjectSignSheet& Paper, Player& player, sf::RenderWindow& windows) {
	
	int MapCount = 0;
	Paper.getNowMap() == "house.txt" ? MapCount = 1 : MapCount = 0;
	for (int i = 0; i < Paper.StairsObject.size(); i++) {
		if (Paper.StairsObject[i].getCollisionBlock()->getGlobalBounds().intersects//for Player
		(player.getCollisionBlock()->getGlobalBounds())) {
			windows.setSize(sf::Vector2u(750,500));
			Paper.mapUpdata(Paper.getMapName()[0 + MapCount] + ".txt", *Paper.size);
			if (!Paper.StairsObject.empty()) {
				sf::Vector2f newPosition = *(Paper.StairsObject[i].getPosition());
				newPosition += (*player.getFace() - *player.getPosition());
				player.setPosition(newPosition);
			}
		}
	}
}

void LogicJudge::fight(ObjectSignSheet& Paper, Player& player, int index) {
	NPC* Enemy = &Paper.NpcSpace[index];
	int chioce = 0, count = 0;
	srand(time(0));
	int skillCount = 3;
	system("cls");
	while (Enemy->getEnityInfo()->hp > 0 && player.getEnityInfo()->hp > 0) {
		count++;
		std::cout << "Round " << count << std::endl;
		std::cout << "  " << std::endl;
		printEnityInfo(player);
		std::cout << "                     " << std::endl;
		printEnityInfo(*Enemy);
		std::cout << "--------------------" << std::endl;
		std::cout << "0:Attack 1:heal(5CD) 2:weak(5CD,3Time)" << std::endl;

		std::cin >> chioce;//���a�^�X

		system("cls");//�M��cmd

		chioce %= skillCount;
		handle(player, *Enemy, chioce);

		chioce = rand() % skillCount;//�ĤH�^�X
		std::cout << chioce << std::endl;
		handle(*Enemy, player, chioce);
	}
	if (Enemy->getEnityInfo()->hp <= 0) {
		system("cls");
		std::cout << "You win"<< std::endl;
		sf::Vector2f temp = sf::Vector2f(0, 0);
		Enemy->setCollisionBlock(&temp);
	} 
	if (player.getEnityInfo()->hp <= 0) {
		system("cls");
		std::cout << "You Lose" << std::endl;
		sf::Vector2f temp = sf::Vector2f(0, 0);
		Enemy->setCollisionBlock(&temp);
		exit(0);
	}
}

void handle(Enity& A, Enity& B, int chioce) {
	switch (chioce) {
	case 0:
		Attack(A, B);
		break;
	case 1:
		heal(A);
		break;
	case 2:
		Weak(A, B);
		break;
	default:
		std::cout << A.getName() << " do nothing" << std::endl;
	}
	TimeCheck(A, B, *(A.getSkill()->HealCD()), "heal");
	TimeCheck(A, B, A.getSkill()->weakinfo()->weakCD, "weak");
}

void TimeCheck(Enity& A, Enity& B, int& Time, std::string type) {
	if (Time > 0) {
		std::cout << *A.getName() << "_" << type << "CD: " << Time << std::endl;
		Time -= 1;
	}
	if (type == "weak") {
		EnityInfo newData = *B.getEnityInfo();
		if (Time > 0) {
			Time--;
			std::cout << *A.getName() << "_WeakTime: " << Time << std::endl;
		}
		else if(B.getOriginEnityInfo()->Defense!=B.getEnityInfo()->Defense){
			newData.Defense = B.getOriginEnityInfo()->Defense;
			B.setEnityInfo(&newData);
		}		
	}
}

void printEnityInfo(Enity& A) {
	std::cout << *A.getName() << std::endl;
	for (int i = 0; i < A.getOriginEnityInfo()->hp / 10; i++) i < (A.getEnityInfo()->hp / 10) ? std::cout << "=" : std::cout << "*";
	
	std::cout << "Hp:" << A.getEnityInfo()->hp << std::endl;

	for (int i = 0; i < A.getOriginEnityInfo()->mp / 10; i++) i < (A.getEnityInfo()->mp / 10) ? std::cout << "=" : std::cout << "*";
	std::cout << "Mp:" << A.getEnityInfo()->mp << std::endl;

	std::cout << *A.getName() << "_Defense: " << A.getEnityInfo()->Defense << std::endl;
}

void Attack(Enity& A, Enity& B) {
	EnityInfo newData_B = *(B.getEnityInfo());
	std::cout << *A.getName() << " use Attack " << std::endl;
	newData_B.hp = B.getEnityInfo()->hp - (A.getEnityInfo()->ATK) * (B.getEnityInfo()->Defense);
	B.setEnityInfo(&newData_B);
}

void heal(Enity& A) {
	EnityInfo newData = *(A.getEnityInfo());
	if (A.getEnityInfo()->mp >= 10 && *(A.getSkill()->HealCD()) <= 0) {
		std::cout << *A.getName() << " use heal " << std::endl;
		*(A.getSkill()->HealCD()) = 5;//HealCD���
		newData.mp = A.getEnityInfo()->mp - 10, newData.hp = A.getEnityInfo()->hp * 1.5;//����hp�Pmp
		if (newData.hp > A.getOriginEnityInfo()->hp) newData.hp = A.getOriginEnityInfo()->hp;//�ɤJ�ק�᪺hp�Pmp
		A.setEnityInfo(&newData);
	}
}

void Weak(Enity& A, Enity& B) {
	EnityInfo newData = *(B.getEnityInfo());
	if (A.getEnityInfo()->mp >= 10 && A.getSkill()->weakinfo()->weakCD <= 0) {
		std::cout << *A.getName() << " use Weak " << std::endl;
		newData.Defense = B.getEnityInfo()->Defense * 2;//���C��訾�m�O
		A.getSkill()->weakinfo()->weakCD = 5;;//WeakCD���
		A.getSkill()->weakinfo()->weakTime = 3;//WeakTime���
		B.setEnityInfo(&newData);//�ק��訾�m�O
	}
}
