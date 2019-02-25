#ifndef INGAME_HPP
#define INGAME_HPP

#include <SFML/Graphics.hpp>

#include <logic/events/eventhandler.hpp>
#include <logic/laser.hpp>

namespace ingame {
	void tick(void);

	sf::Vector2f getShipCoords(void);
	
	void changeShipPos(uint8_t newPos);
	void changeShipPos(sf::Keyboard::Key key);

	Laser *getLaser(uint8_t pos);
}

#endif