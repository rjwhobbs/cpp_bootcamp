#include <iostream>
#include <time.h>
#include "Acc.class.hpp"

Acc::Acc(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = Acc::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Acc::_totalAmount += initial_deposit;
	Acc::_nbAccounts += 1;

	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Acc::Acc(void) {
	this->_amount = 0;
	this->_accountIndex = Acc::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Acc::_nbAccounts += 1;

	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Acc::~Acc(void) {
	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;

	return ;
}

void Acc::makeDeposit(int deposit) {
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Acc::_totalAmount += deposit;
	Acc::_totalNbDeposits += 1;

	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Acc::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;

	if (withdrawal > this->checkAmount()) {
		Acc::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:refused" << std::endl;

		return false;

	} else if (withdrawal > 0) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Acc::_totalAmount -= withdrawal;
		Acc::_totalNbWithdrawals += 1;

		Acc::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << this->_amount << ';';
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		return true;
	}

	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "withdrawal:refused" << std::endl;

	return false;
}

int Acc::checkAmount(void) const {
	return this->_amount;
}

int Acc::getNbAccounts(void) {
	return Acc::_nbAccounts;
}

int Acc::getTotalAmount(void) {
	return Acc::_totalAmount;
}

void Acc::displayAccountsInfos(void) {
	int accounts = Acc::getNbAccounts();
	int total = Acc::getTotalAmount();

	Acc::_displayTimestamp();
	std::cout << "accounts:" << accounts << ';';
	std::cout << "total:" << total << std::endl;
}

void Acc::displayStatus(void) const {
	Acc::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << ';';
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Acc::_displayTimestamp(void) {
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

	std::cout << '[' << year;
	month < 10 ? std::cout << '0' << month : std::cout << month;
	day < 10 ? std::cout << '0' << day : std::cout << day;
	hour < 10 ? std::cout << "_0" << hour : std::cout << '_' << hour;
	min < 10 ? std::cout << '0' << hour : std::cout << min;
	sec < 10 ? std::cout << '0' << sec << "] ": std::cout << sec << "] ";
}

int Acc::_nbAccounts = 0;
int Acc::_totalAmount = 0;
int Acc::_totalNbDeposits = 0;
int Acc::_totalNbWithdrawals = 0;