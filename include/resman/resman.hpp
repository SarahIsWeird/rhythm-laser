#ifndef RESMAN_H
#define RESMAN_H

#include <vector>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>

#include <logic/events/eventhandler.hpp>
#include <logger.hpp>

namespace resman {
	int initialize(void);

	int loadImage(std::string name);
	int loadTextures(void);
	int loadSprites(void);

	sf::Image *getImage(std::string name);
	sf::Texture *getTexture(std::string name);
	sf::Sprite *getSprite(std::string name);

	void unloadResources(void);
}

#endif