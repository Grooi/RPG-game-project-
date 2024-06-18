#include <iostream>
#include "ImpactCheck.h";


sf::Vector2f ImpackChecker::ImpackCheck_StaticObject(std::vector<sf::RectangleShape>& A, sf::RectangleShape CollisionBlock, int* size, double* speed ) {
	sf::Vector2f point = CollisionBlock.getPosition();
	
	for (int i = 0; i < A.size(); i++) {
		if (A[i].getGlobalBounds().intersects(CollisionBlock.getGlobalBounds())) {
			return point += (point - A[i].getPosition());
		}
	}
	return point;
}

sf::Vector2f ImpackChecker::ImpackCheck_Enity(std::vector<NPC>& A, Player player, int* size) {

	for (int y = 0; y < A.size(); y++) {
		for (int x = 0; x < A.size(); x++) {
			if (A[y].getCollisionBlock1().getGlobalBounds().intersects(A[x].getCollisionBlock1().getGlobalBounds())) {
				sf::Vector2f a = A[y].getPosition(), b = A[x].getPosition();
				A[y].setPosition(A[y].getPosition() + (a - b));
				A[x].setPosition(A[x].getPosition() + (b - a));
			}
			if (A[y].getCollisionBlock1().getGlobalBounds().intersects(player.getCollisionBlock1().getGlobalBounds())) {
				sf::Vector2f a = A[y].getPosition() - *player.getPosition(), b = *player.getPosition() - A[y].getPosition();
				if (*A[y].getSpeed() >= *player.getSpeed()) {
					return *player.getPosition() + b;
				}
				else if(*A[y].getSpeed() < *player.getSpeed()){
					A[y].setPosition(A[y].getPosition() + a);
					return *player.getPosition() + b;
				}
			}
		}
	}
	return *player.getPosition();
}