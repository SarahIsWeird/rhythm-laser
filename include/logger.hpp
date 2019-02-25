#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

#include <direct.h>

namespace Logger {
	int initLogger();

	int log(std::string text);

	void endLog();
};

#endif