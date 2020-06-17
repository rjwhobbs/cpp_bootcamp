#include <string>
#include <iostream>
#include <sstream>
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
	std::stringstream logDate;
	char buff[10];
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

	logDate << '[' << year;
	month < 10 ? logDate << '0' << month : logDate << month;
	day < 10 ? logDate << '0' << day : logDate << day;
	hour < 10 ? logDate << "_0" << hour : logDate << '_' << hour;
	min < 10 ? logDate << '0' << hour : logDate << min;
	sec < 10 ? logDate << '0' << sec << "] ": logDate << sec << "] ";

	return logDate.str();
}