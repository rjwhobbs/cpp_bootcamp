#include <string>
#include <iostream>
#include "Logger.hpp"

Logger::Logger(std::string const filename)
: _filename(filename) {
	return ;
}

Logger::~Logger(void) {
	return ;
}

void Logger::logToConsole(const std::string message) const {
	std::cout << this->makeLogEntry("word") << std::endl;
}

std::string Logger::makeLogEntry(const std::string message) const {
	std::string logDate;
	time_t rawtime;
	struct tm *timeinfo;
	int year, month, day, hour, min, sec; 

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	year = timeinfo->tm_year + 1900;
	month = timeinfo->tm_mon + 1;
	day = timeinfo->tm_mday;
	hour = timeinfo->tm_hour;
	min = timeinfo->tm_min;
	sec = timeinfo->tm_sec;

	logDate = '[' + std::to_string(year);
	month < 10 ? logDate += ('0' +  std::to_string(month)) : 
		logDate += std::to_string(month);
	day < 10 ? logDate += ('0' + std::to_string(day)) : 
		logDate += std::to_string(day);
	hour < 10 ? logDate += ("_0" + std::to_string(hour)) : 
		logDate += ('_' + std::to_string(hour));
	min < 10 ? logDate += ('0' + std::to_string(min)) : 
		logDate += std::to_string(min);
	sec < 10 ? logDate += ('0' + std::to_string(sec) +  "] ") : 
		logDate += (std::to_string(sec) + "] ");

	return logDate;
}