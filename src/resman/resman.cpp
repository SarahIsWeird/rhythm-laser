#include <resman/resman.hpp>

namespace resman {
	std::map<std::string, sf::Image*> imageMap;
	std::map<std::string, sf::Texture*> textureMap;
	std::map<std::string, sf::Sprite*> spriteMap;

	bool isLoaded = false;

	int initialize(void) {
		eventhandler::registerCleanupFunction(unloadResources);

		loadImage("ship");
		loadImage("lasergun");
		loadImage("playfield");
		loadImage("background");

		loadImage("laser_straight");
		loadImage("laser_sideways");
		loadImage("laser_sideways_right");

		loadTextures();
		loadSprites();
	}

	int loadImage(std::string name) {
		sf::Image *image = new sf::Image;
		(*image).loadFromFile("resources/images/" + name + ".png");
		imageMap.emplace(name, image);
	}

	/* Scans through all images and creates textures for them.
	 * Unlike loadImage(), it does not need to be supplied with names, as it gets them automatically.
	 * This is the first fully automated step in the resource loading! Wooo!
	 */
	int loadTextures(void) {
		for (auto it = imageMap.begin(); it != imageMap.end(); it++) {
			sf::Texture *texture = new sf::Texture;

			(*texture).loadFromImage(*getImage((*it).first));
			textureMap.emplace((*it).first, texture);
		}
	}

	int loadSprites(void) {
		for (auto it = textureMap.begin(); it != textureMap.end(); it++) {
			sf::Sprite *sprite = new sf::Sprite;

			(*sprite).setTexture(*(*it).second);
			spriteMap.emplace((*it).first, sprite);
		}
	}

	sf::Image *getImage(std::string name) {
		return imageMap.find(name)->second;
	}

	sf::Texture *getTexture(std::string name) {
		return textureMap.find(name)->second;
	}

	sf::Sprite *getSprite(std::string name) {
		return spriteMap.find(name)->second;
	}

	void unloadResources(void) {
		for (auto it = imageMap.begin(); it != imageMap.end(); it++) {
			delete (*it).second;
		}

		imageMap.clear();

		for (auto it = textureMap.begin(); it != textureMap.end(); it++) {
			delete (*it).second;
		}

		textureMap.clear();

		for (auto it = spriteMap.begin(); it != spriteMap.end(); it++) {
			delete (*it).second;
		}

		spriteMap.clear();
	}
}