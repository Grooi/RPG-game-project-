#include <iostream>
#include <random>
#include <time.h>
#include "LogicJudge.h";

void LogicJudge::ImpackCheck(ObjectSignSheet &Paper, Player &player) {
	//////////////////////////////////////////DoorImpact
	for (int i = 0; i < Paper.doorObject.size(); i++) {
		if (Paper.doorObject[i].getCollisionBlock().getGlobalBounds().intersects//for Player
		(player.getCollisionBlock().getGlobalBounds()) && Paper.doorObject[i].getState() == false) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.doorObject[i].getPosition()));
		}
		for (int j = 0; j < Paper.NpcSpace.size(); j++) {//for NPC
			if (Paper.doorObject[i].getCollisionBlock().getGlobalBounds().intersects
			(Paper.NpcSpace[j].getCollisionBlock().getGlobalBounds())) {
			}
		}
	}
	//////////////////////////////////////////WallImpact
	for (int i = 0; i < Paper.wallObject.size(); i++) {
		if (Paper.wallObject[i].getCollisionBlock().getGlobalBounds().intersects//for Player
		(player.getCollisionBlock().getGlobalBounds())) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.wallObject[i].getPosition()));
		}
		for (int j = 0; j < Paper.NpcSpace.size(); j++) {//for NPC
			if (Paper.wallObject[i].getCollisionBlock().getGlobalBounds().intersects
			(Paper.NpcSpace[j].getCollisionBlock().getGlobalBounds())) {
			}
		}
	}
	//////////////////////////////////////////NPCImpact
	for (int i = 0; i < Paper.NpcSpace.size(); i++) {
		if (Paper.NpcSpace[i].getCollisionBlock().getGlobalBounds().intersects
		(player.getCollisionBlock().getGlobalBounds())) {
			player.setPosition(*(player.getPosition()) + *(player.getPosition()) - *(Paper.NpcSpace[i].getPosition()));
		}
	}


}

void LogicJudge::fight(ObjectSignSheet& Paper, Player& player, int index) {
	NPC* Enemy = &Paper.NpcSpace[index];
	int chioce, count = 0;
	srand(time(0));

	while (*Enemy->getHP() > 0 && *player.getHP() > 0) {
		
		count++;
		std::cout << "Round " << count << std::endl;

		for (int i = 0; i < *player.getHP() / 10; i++) std::cout << "*";
		std::cout << "Hp:" << *player.getHP() << std::endl;
		for (int i = 0; i < *player.getMP() / 10; i++) std::cout << "*";
		std::cout << "Mp:" << *player.getMP() << std::endl;

		std::cin >> chioce;//玩家回合

		system("cls");//清除cmd

		chioce %= 2;
		handle(player, *Enemy, player.getSkill().func, chioce);

		chioce = rand() % 2;//敵人回合
		handle(*Enemy, player, player.getSkill().func, chioce);

	}
	if (*Enemy->getHP() <= 0) {
		Paper.NpcSpace[index] = NPC(1,1);
	}
	
}

void LogicJudge::handle(Enity& A, Enity& B, double (*func[10])(), int chioce) {
	double hp, mp;
	hp = func[chioce]();
	if (chioce == 0) {
		std::cout << A.getType() << " use Attack: " << std::endl;
		B.setHp(&hp);
	}
	if (chioce == 1 && *A.getMP() >= 10) {
		std::cout << A.getType() << " use heal: " << std::endl;
		mp = -10;
		A.setHp(&hp);
		A.setMp(&mp);
	}
}