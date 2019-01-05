#ifndef INGAME_HPP
#define INGAME_HPP

#include <SFML/Graphics.hpp>

#include <logic/events/eventhandler.hpp>

namespace ingame {
	int tick(void);

	sf::Vector2f getShipCoords(void);
	
	int changeShipPos(uint8_t newPos);
}

#endif