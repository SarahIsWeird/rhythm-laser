#include <logic/ingame.hpp>

uint8_t currentPos;

Laser laser0(0);

void ingame::tick(void) {
	
}

/**
 * Gets the current absolute coordinates of the ship.
 */
sf::Vector2f ingame::getShipCoords(void) {
	return sf::Vector2f(800 / 3 + currentPos * (800 / 18) + 9, 545);
}

/**
 * Changes the position of the ship via the number supplied. nowPos can be a value between 0 and 5.
 * Returns non-zero if the supplied position is invalid.
 * Returns 1 if the supplied position is already the ship's position.
 */
int ingame::changeShipPos(uint8_t newPos) {
	if (currentPos == newPos)
		return 1;
	
	if (currentPos > 5)
		return -1;

	currentPos = newPos;
}

/**
 * Changes the position of the ship via the key pressed.
 * key can be S, D, F, J, K or L.
 * Returns non-zero if the supplied key is invalid.
 * Returns 1 if the supplied position is already the ship's position.
 */
int ingame::changeShipPos(sf::Keyboard::Key key) {
	switch (key) {
		case sf::Keyboard::S:
			return changeShipPos(0);
		case sf::Keyboard::D:
			return changeShipPos(1);
		case sf::Keyboard::F:
			return changeShipPos(2);
		case sf::Keyboard::J:
			return changeShipPos(3);
		case sf::Keyboard::K:
			return changeShipPos(4);
		case sf::Keyboard::L:
			return changeShipPos(5);
		default:
			return -1;
	}
}

/**
 * Gets the laser object for the specified lane.
 * Returns (Laser*) NULL if an invalid lane is supplied.
 */
Laser *ingame::getLaser(uint8_t pos) {
	switch (pos) {
		case 0:
			return &laser0;
		default:
			return (Laser*) NULL;
	}
}