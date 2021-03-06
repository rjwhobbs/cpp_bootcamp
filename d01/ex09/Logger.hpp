#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <string>

class Logger {
	public:
		Logger(std::string const filename);
		~Logger(void);

		void log(std::string const& dest, std::string const& message) const;

	private:
		void logToConsole(std::string const message) const;
		void logToFile(std::string const message) const;
		std::string makeLogEntry(std::string const message) const;

		std::string const _filename;
};

#endif