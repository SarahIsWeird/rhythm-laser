#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

namespace eventhandler {
	int registerCleanupFunction(void (*function)(void), const char *s);

	int pushEvent(sf::Event::EventType event);

	int handleEvents(sf::RenderWindow *window);

	void close(sf::RenderWindow *window);
}

#endif