#include <iostream>
#include "Acc.class.hpp"

Acc::Acc(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = Acc::_nbAccounts;
	this->_nbDeposits = 0;
	Acc::_nbAccounts += 1;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Acc::Acc(void) {
	this->_amount = 0;
	this->_accountIndex = Acc::_nbAccounts;
	this->_nbDeposits = 0;
	Acc::_nbAccounts += 1;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

void Acc::makeDeposit(int deposit) {
	int p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	Acc::_totalNbDeposits += 1;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << p_amount << ';';
	std::cout << "deposit:" << deposit << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

Acc::~Acc(void) {
	std::cout << "closed" << std::endl;

	return ;
}

int Acc::_nbAccounts = 0;
int Acc::_totalNbDeposits = 0;