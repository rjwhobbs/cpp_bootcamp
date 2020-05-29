#include <iostream>
#include <time.h>
#include <string>
#include "Account.class.hpp"

Account::Account(int initial_deposit) {

	std::string errorMsg;

	if (initial_deposit < 0 ||
			Account::_totalAmount + initial_deposit < 0
		) {
		initial_deposit = 0;
		errorMsg = "error:Initial deposit refused.";
	} 

	this->_amount = initial_deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	
	if (errorMsg.empty()) {
		std::cout << "created" << std::endl; 
	} else {
		std::cout << "created;" << errorMsg << std::endl; 
	}

	return ;
}

Account::Account(void) {
	this->_amount = 0;
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Account::~Account(void) {
	Account::_nbAccounts -= 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "closed" << std::endl;

	return ;
}

void Account::makeDeposit(int deposit) {

	std::string errorMsg;

	if (deposit < 1) {
		deposit = 0;
		errorMsg = "refused";
	}

	int p_amount = this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;

	errorMsg.empty()? this->_nbDeposits += 1: this->_nbDeposits += 0;
	errorMsg.empty()? Account::_totalNbDeposits += 1: Account::_totalNbDeposits += 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';

	if (errorMsg.empty()) {
		std::cout << "deposit:" << deposit << ';';
	} else {
		std::cout << "deposit:" << errorMsg << ';';
	}

	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = this->_amount;

	if (withdrawal > this->checkAmount()) {
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:refused" << std::endl;

		return false;

	} else if (withdrawal > 0) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals += 1;

		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ';';
		std::cout << "p_amount:" << p_amount << ';';
		std::cout << "withdrawal:" << withdrawal << ';';
		std::cout << "amount:" << this->_amount << ';';
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		return true;
	}

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "withdrawal:refused" << std::endl;

	return false;
}

int Account::checkAmount(void) const {
	return this->_amount;
}

int Account::getNbAccounts(void) {
	return Account::_nbAccounts;
}

int Account::getNbDeposits(void) {
	return Account::_totalNbDeposits;
}

int Account::getTotalAmount(void) {
	return Account::_totalAmount;
}

int Account::getNbWithdrawals(void) {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	int accounts = Account::getNbAccounts();
	int total = Account::getTotalAmount();
	int deposits = Account::getNbDeposits();
	int withdrawals = Account::getNbWithdrawals();

	Account::_displayTimestamp();
	std::cout << "accounts:" << accounts << ';';
	std::cout << "total:" << total << ';';
	std::cout << "deposits:" << deposits << ';';
	std::cout << "withdrawals:" << withdrawals << std::endl;
}

void Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "deposits:" << this->_nbDeposits << ';';
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
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

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;