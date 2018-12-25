#include <logic/events/eventhandler.hpp>

namespace eventhandler {
	std::vector<void (*)(void)> functions;

	int registerCleanupFunction(void (*function)(void)) {
		functions.push_back(function);
	}

	int handleEvents(sf::RenderWindow *window) {
		sf::Event event;

		while ((*window).pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				close(window);
		}
	}

	void close(sf::RenderWindow *window) {
		for (auto it = functions.begin(); it != functions.end(); it++) {
			(*it)();
		}

		(*window).close();
	}
}