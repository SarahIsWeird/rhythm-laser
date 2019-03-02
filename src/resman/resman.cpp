#include <resman/resman.hpp>

std::map<std::string, sf::Image*> imageMap;
std::map<std::string, sf::Texture*> textureMap;
std::map<std::string, sf::Sprite*> spriteMap;

bool isLoaded = false;

/**
 * Initializes the resource manager.
 */
int resman::initialize(void) {
	eventhandler::registerCleanupFunction(unloadResources, "EventHandler::unloadResources()");

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

/**
 * Loads an image into the resource map.
 */
int resman::loadImage(std::string name) {
	sf::Image *image = new sf::Image;
	(*image).loadFromFile("resources/images/" + name + ".png");
	imageMap.emplace(name, image);
	Logger::log("[ResMan] Image " + name + ".png loaded.");
}

/**
 * Scans through all images and creates textures for them.
 * Unlike loadImage(), it does not need to be supplied with names, as it gets them automatically.
 */
int resman::loadTextures(void) {
	for (auto it = imageMap.begin(); it != imageMap.end(); it++) {
		sf::Texture *texture = new sf::Texture;

		(*texture).loadFromImage(*getImage((*it).first)); // (*it).second is the image pointer
		textureMap.emplace((*it).first, texture); // (*it).first is the image name (=> the texture name)
	}
}

/**
 * Scans through all textures and creates the corresponding sprites for them.
 */
int resman::loadSprites(void) {
	for (auto it = textureMap.begin(); it != textureMap.end(); it++) {
		sf::Sprite *sprite = new sf::Sprite;

		(*sprite).setTexture(*(*it).second); // (*it).second is the texture pointer
		spriteMap.emplace((*it).first, sprite); // (*it).first is the texture name (=> the sprite name)
	}
}

/**
 * Searches through the image map and returns the image with the specified name.
 */
sf::Image *getImage(std::string name) {
	return imageMap.find(name)->second;
}

/**
 * Searches through the texture map and returns the texture with the specified name.
 */
sf::Texture *getTexture(std::string name) {
	return textureMap.find(name)->second;
}

/**
 * Searches through the sprite map and returns the sprite with the specified name.
 */
sf::Sprite *getSprite(std::string name) {
	return spriteMap.find(name)->second;
}

/**
 * Unloads all resources.
 */
void resman::unloadResources(void) {
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