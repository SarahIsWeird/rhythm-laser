#include <logic/songloader.hpp>

namespace songloader {
	Song::Song(std::string path) {
		
	}

	SongChart::SongChart(std::string path) {
		std::string file_cont;
		std::ifstream file_obj(path, std::ios::in | std::ios::binary | std::ios::ate);

		if (!file_obj.is_open()) {
			std::cout << "Couldn't open the file!" << std::endl;
			eventhandler::pushEvent(sf::Event::Closed);
		}

		std::streampos file_len = file_obj.tellg();
		file_obj.seekg(std::ios::beg);

		char *file = new char[file_len];
		file_obj.read(file, file_len);
		file_obj.close();

		if (file[0] != 0x72 || file[1] != 0x6c || file[2] != 0x69) {
			std::cout << "Not a valid song index file!" << std::endl;
			eventhandler::pushEvent(sf::Event::Closed);
		}
	}
}