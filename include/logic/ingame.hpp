#ifndef INGAME_HPP
#define INGAME_HPP

#include <SFML/Graphics.hpp>

#include <logic/events/eventhandler.hpp>
#include <logic/laser.hpp>

namespace ingame {
	void tick(void);

	sf::Vector2f getShipCoords(void);
	
	int changeShipPos(uint8_t newPos);
	int changeShipPos(sf::Keyboard::Key key);

	Laser *getLaser(uint8_t pos);
}

#endif