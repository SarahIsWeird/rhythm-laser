#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

#include <direct.h>

#include <resman/resman.hpp>

namespace Logger {
	int initLogger();

	int write(std::string text);
	int log(std::string text);

	void endLog();
};

#endif