#ifndef SONGLOADER_HPP
#define SONGLOADER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include <logic/events/eventhandler.hpp>

namespace songloader {
	class Song {
		private:
			std::string artist;
			std::string title;
			uint32_t length;

			sf::Image backgroundImage;

		public:
			Song(std::string path);

			std::string getArtist(void);
			std::string getTitle(void);
			uint32_t getLength(void);
	};

	class SongChart {
		private:
			std::vector<Song> songs;
			sf::Image menuImage;

		public:
			SongChart(std::string path);

			std::vector<Song> getSongs(void);
			sf::Image getMenuImage(void);
	};
}

#endif