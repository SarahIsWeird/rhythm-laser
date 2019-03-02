#include <renderer/renderer.hpp>

uint64_t mode = 1;

bool renderer::inMode(MODE_FLAG flag) {
	return (mode & flag) == mode;
}

uint32_t renderer::getGlobalMode(void) {
	return (uint32_t)(mode & 0xffffffff);
}

/**
 * Switches the current global mode to the specified renderer::MODE_FLAG.
 * If the renderer::MODE_FLAG is bigger than uint32_max, aka it specifies a local mode,
 * the function returns a non-zero value other than 1.
 * If the specified flag is already set, the function always returns 1.
 * On success, the function returns 0.
 */
int renderer::switchGlobalMode(MODE_FLAG flag) {
	if (flag > UINT32_MAX) // Bigger than UINT32_MAX
		return -1;

	if (flag == getGlobalMode()) // Global mode is already set
		return 1;
	
	uint64_t newMode = flag;
	uint32_t localMode = (uint32_t)(mode >> 32);
	newMode |= localMode;
	mode = newMode;

	return 0;
}

/**
 * The main rendering function. Calls all sub-rendering functions, including window.clear(); and window.display();.
 */
int renderer::render(sf::RenderWindow *window) {
	uint32_t globalMode = getGlobalMode();
	int result = 0;

	window->clear();

	switch (globalMode) {
		case 1:
			result = renderMainMenu(window);
			break;
		case 2:
			result = renderGame(window);
			break;
	}

	window->display();

	return result;
}

int renderer::renderMainMenu(sf::RenderWindow *window) {
	return 0;
}

int renderer::renderGame(sf::RenderWindow *window) {
	window->draw(*resman::getSprite("background"));

	sf::Sprite *playfield = resman::getSprite("playfield");
	playfield->setPosition(266, 0);
	window->draw(*playfield);

	sf::Sprite *player = resman::getSprite("ship");
	player->setPosition(ingame::getShipCoords());
	window->draw(*player);

	/*
	sf::Sprite *laser_straight = resman::getSprite("laser_straight");
	sf::Sprite *laser_sideways = resman::getSprite("laser_sideways");
	sf::Sprite *laser_sideways_right = resman::getSprite("laser_sideways_right");

	laser::tailSegment *seg;
	while (ingame::getLaser(0)->pollSegment(seg)) {
		Logger::log("[Renderer] Rendering Laser...");
		switch (seg->type) {
			case laser::laserType::normal:
				laser_straight->setPosition(800 / 3 + (800 / 18 * seg->pos), seg->height);
				window->draw(*laser_straight);
				break;
			case laser::laserType::wobble:
				switch (seg->offset) {
					case laser::segmentPosition::left:
						laser_sideways_right->setPosition(800 / 3 + (800 / 18 * seg->pos), seg->height);
						window->draw(*laser_sideways_right);
						break;
					case laser::segmentPosition::right:
						laser_sideways->setPosition(800 / 3 + (800 / 18 * seg->pos), seg->height);
						window->draw(*laser_sideways);
						break;
					case laser::segmentPosition::center:
						if (seg->dir == laser::wobbleDir::left) {
							laser_sideways->setPosition(800 / 3 + (800 / 18 * seg->pos), seg->height);
							window->draw(*laser_sideways);
							break;
						} else {
							laser_sideways_right->setPosition(800 / 3 + (800 / 18 * seg->pos), seg->height);
							window->draw(*laser_sideways_right);
							break;
						}
				}
		}
	}
	*/

	return 0;
}