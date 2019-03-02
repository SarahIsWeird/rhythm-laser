#include <logger.hpp>

std::string logFileName;

std::ofstream logFile;

int Logger::initLogger() {
	eventhandler::registerCleanupFunction(Logger::endLog, "Logger::endLog()");
	_mkdir("log");

	std::time_t time_now = std::time(0);
	std::tm *now = std::localtime(&time_now);

	std::stringstream tempStream;

	tempStream << "log/log_" << now->tm_year + 1900 << "-" << now->tm_mon + 1 << "-" << now->tm_mday << "-"
			<< now->tm_hour << "-" << now->tm_min << "-" << now->tm_sec << ".txt";

	logFileName = tempStream.str();

	logFile.open(logFileName, std::ios::out);
	return logFile.is_open();
}

int Logger::write(std::string text) {
	if (!logFile.is_open())
		return 1;
	
	logFile << text;
	return 0;
}

int Logger::log(std::string text) {
	if (!logFile.is_open())
		return 1;
	
	logFile << text << std::endl;

	return 0;
}

void Logger::endLog() {
	if (logFile.is_open())
		logFile.close();
}