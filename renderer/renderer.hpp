#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <stdint.h>

#include <SFML/Graphics.hpp>

#include <resman/resman.hpp>
#include <logic/ingame.hpp>

namespace renderer {
	enum MODE_FLAG {
		MAIN_MENU = 1,
		INGAME = 2,

		OPTIONS = 0x8000000000000000
	};

	bool inMode(MODE_FLAG flag);
	uint32_t getGlobalMode(void);

	int switchGlobalMode(MODE_FLAG flag);

	int render(sf::RenderWindow *window);

	int renderMainMenu(sf::RenderWindow *window);
	int renderGame(sf::RenderWindow *window);
}

#endif // RENDERER_HPP
