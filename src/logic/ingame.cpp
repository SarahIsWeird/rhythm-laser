#include <logic/ingame.hpp>

namespace ingame {
	uint8_t currentPos;

	Laser laser0(0);

	void tick(void) {
		
	}

	sf::Vector2f getShipCoords(void) {
		return sf::Vector2f(800 / 3 + currentPos * (800 / 18) + 9, 545);
	}

	void changeShipPos(uint8_t newPos) {
		if (currentPos == newPos)
			return;
		
		currentPos = newPos;
	}

	void changeShipPos(sf::Keyboard::Key key) {
		switch (key) {
			case sf::Keyboard::S:
				changeShipPos(0);
				break;
			case sf::Keyboard::D:
				changeShipPos(1);
				break;
			case sf::Keyboard::F:
				changeShipPos(2);
				break;
			case sf::Keyboard::J:
				changeShipPos(3);
				break;
			case sf::Keyboard::K:
				changeShipPos(4);
				break;
			case sf::Keyboard::L:
				changeShipPos(5);
				break;
		}
	}

	Laser *getLaser(uint8_t pos) {
		switch (pos) {
			case 0:
				return &laser0;
		}
	}
}