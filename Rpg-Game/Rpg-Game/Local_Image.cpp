#include <iostream>
#include "Local_image.h"

Local_image::Local_image(std::string fileName) {
	loadPicture(fileName);
}
Local_image::Local_image() {

}
void Local_image::loadPicture(std::string fileName) {
	std::string str = "image\\";
	str.append(fileName);
	str.append(".png");
	texture.loadFromFile(str);
	loadSprite(texture, sprite);
}

void Local_image::loadSprite(sf::Texture& texture, sf::Sprite& sprite) {
	sprite.setTexture(texture);
}

sf::Sprite Local_image::getSprite() {
	return sprite;
}

void Local_image::setLocal_imagePosition(double d_y, double d_x, double size) {
	sprite.setPosition(d_x * size, d_y * size);
}

void Local_image::setsetLocal_imageOrigin(int a, int b) {
	sprite.setOrigin(a, b);
}