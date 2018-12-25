#include <logic/ingame.hpp>

namespace ingame {
	uint8_t currentPos;

	int tick(void) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			currentPos = 0;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			currentPos = 1;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
			currentPos = 2;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
			currentPos = 3;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
			currentPos = 4;
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
			currentPos = 5;
		}
	}

	sf::Vector2f getShipCoords(void) {
		return sf::Vector2f(800 / 3 + currentPos * (800 / 18) + 9, 545);
	}

	int changeShipPos(uint8_t newPos) {
		currentPos = newPos;
	}
}