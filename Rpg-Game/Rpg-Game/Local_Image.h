#ifndef LOCAL_IMAGE_H
#define LOCAL_IMAGE_H
#include <SFML/Graphics.hpp>
#include <string>
class Local_image {
public:
	Local_image(std::string);
	Local_image();
	void loadPicture(std::string fileName);
	void loadSprite(sf::Texture& texture, sf::Sprite& sprite);
	void setLocal_imagePosition(double, double, double);
	void setsetLocal_imageOrigin(int, int);
	sf::Sprite getSprite();
private:
	std::string fileName;
	sf::Texture texture;
	sf::Sprite sprite;

};
#endif