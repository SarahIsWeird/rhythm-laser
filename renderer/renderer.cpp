#include <renderer/renderer.hpp>

namespace renderer {
	uint64_t mode = 1;

	bool inMode(MODE_FLAG flag) {
		return (mode & flag) == mode;
	}

	uint32_t getGlobalMode(void) {
		return (uint32_t)(mode & 0xffffffff);
	}

	/* Switches the current global mode to the specified renderer::MODE_FLAG.
	* If the renderer::MODE_FLAG is bigger than UINT32_MAX, aka it specifies a local mode,
	* the function returns a non-zero value other than -1.
	* If the specified flag is already set, the function always returns -1.
	* On success, the function returns 0.
	*/
	int switchGlobalMode(MODE_FLAG flag) {
		if (flag > UINT32_MAX) // Bigger than UINT32_MAX
			return 1;

		if (flag == getGlobalMode()) // Global mode is already set
			return -1;
		
		uint64_t newMode = flag;
		uint32_t localMode = (uint32_t)(mode >> 32);
		newMode |= localMode;
		mode = newMode;

		return 0;
	}

	/* The main rendering function. Calls all sub-rendering functions, including window.clear(); and window.display();.
	*/
	int render(sf::RenderWindow *window) {
		uint32_t globalMode = getGlobalMode();
		int result = 0;

		(*window).clear();

		switch (globalMode) {
			case 1:
				result = renderMainMenu(window);
				break;
			case 2:
				result = renderGame(window);
				break;
		}

		(*window).display();

		return result;
	}

	int renderMainMenu(sf::RenderWindow *window) {
		return 0;
	}

	int renderGame(sf::RenderWindow *window) {
		(*window).draw(*resman::getSprite("background"));

		sf::Sprite *playfield = resman::getSprite("playfield");
		(*playfield).setPosition(266, 0);
		(*window).draw(*playfield);

		sf::Sprite *player = resman::getSprite("ship");
		(*player).setPosition(ingame::getShipCoords());
		(*window).draw(*player);

		return 0;
	}
}