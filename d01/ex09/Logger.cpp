#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Logger.hpp"

Logger::Logger(std::string const filename)
: _filename(filename) {
	return ;
}

Logger::~Logger(void) {
	return ;
}

void Logger::log(const std::string &dest, const std::string &message) const {
	std::string logFuncsNames[] = {"console", "file"};
	void (Logger::*logMems[])(std::string const message) const = {
		&Logger::logToConsole,
		&Logger::logToFile};
	
	int i = 0;
	while (i < 2) {
		if (logFuncsNames[i] == dest) {
			(this->*logMems[i])(message);
			return ;
		}
		i++;
	}
}

void Logger::logToConsole(const std::string message) const {
	std::cout << this->makeLogEntry(message) << std::endl;
}

void Logger::logToFile(const std::string message) const {
	std::ofstream ofs(this->_filename, std::ofstream::app);

	if(ofs.fail()) {
		std::cerr << "Error opening/creating log file: " 
			<< this->_filename    
			<< "\nEnsure that the path is correct and that you have correct permissions." 
			<< std::endl;
		return ;
	}

	ofs << this->makeLogEntry(message);
	ofs << std::endl;
}

std::string Logger::makeLogEntry(const std::string message) const {
	std::stringstream logDate;
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

	logDate << message;

	return logDate.str();
}