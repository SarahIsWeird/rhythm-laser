#include <logic/events/eventhandler.hpp>
#include <logic/ingame.hpp>

namespace eventhandler {
	std::vector<void (*)(void)> functions;
	std::vector<sf::Event::EventType> localQueue;

	int registerCleanupFunction(void (*function)(void)) {
		functions.push_back(function);

		return 0;
	}

	int pushEvent(sf::Event::EventType eventType) {
		localQueue.push_back(eventType);

		return 0;
	}

	int handleEvents(sf::RenderWindow *window) {
		sf::Event event;

		for (auto it = localQueue.begin(); it != localQueue.end(); it++) {
			if ((*it) == sf::Event::Closed)
				close(window);
		}

		localQueue.clear();

		while ((*window).pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					close(window);
					break;
				case sf::Event::KeyPressed:
					ingame::changeShipPos(event.key.code);
					break;
			}
		}

		return 0;
	}

	void close(sf::RenderWindow *window) {
		for (auto it = functions.begin(); it != functions.end(); it++) {
			(*it)();
		}

		(*window).close();
	}
}