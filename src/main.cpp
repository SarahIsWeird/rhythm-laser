#include <SFML/Graphics.hpp>

#include <renderer/renderer.hpp>
#include <resman/resman.hpp>
#include <logic/events/eventhandler.hpp>

sf::RenderWindow mainWindow;

int main(int argc, char **argv) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Yeet.");

	window.setVerticalSyncEnabled(true);

	resman::initialize();

	renderer::switchGlobalMode(renderer::INGAME);

    while (window.isOpen()) {
		ingame::tick();

		eventhandler::handleEvents(&window);

		int render_result = renderer::render(&window);
		switch (render_result) {
			case 0:
				break;
			case 1:
				return 1;
		}
    }

    return 0;
}
