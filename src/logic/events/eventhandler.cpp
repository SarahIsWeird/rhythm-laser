#include <logic/events/eventhandler.hpp>
#include <logic/ingame.hpp>

std::vector<void (*)(void)> functions;
std::vector<sf::Event::EventType> localQueue;

/**
 * Registers a function called on exit.
 */
int eventhandler::registerCleanupFunction(void (*function)(void), const char *s) {
	Logger::write("[EventHandler] Registered cleanup function");
	Logger::write(s);
	Logger::write(".\n");

	functions.push_back(function);

	return 0;
}

/**
 * Pushes an event onto the event queue.
 */
int eventhandler::pushEvent(sf::Event::EventType eventType) {
	localQueue.push_back(eventType);

	return 0;
}

/**
 * Called every tick to handle queued events.
 */
int eventhandler::handleEvents(sf::RenderWindow *window) {
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

/**
 * A shortcut for pushing a sf::Event::Closed event onto the event queue.
 */
void eventhandler::close(sf::RenderWindow *window) {
	for (auto it = functions.begin(); it != functions.end(); it++) {
		(*it)();
	}

	(*window).close();
}