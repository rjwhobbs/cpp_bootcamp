#include <iostream>
#include "Acc.class.hpp"

Acc::Acc(int initial_deposit) {
	this->_amount = initial_deposit;
	this->_accountIndex = Acc::_nbAccounts;
	Acc::_nbAccounts += 1;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Acc::Acc(void) {
	this->_amount = 0;
	this->_accountIndex = Acc::_nbAccounts;
	Acc::_nbAccounts += 1;

	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "amount:" << this->_amount << ';';
	std::cout << "created" << std::endl;

	return ;
}

Acc::~Acc(void) {
	std::cout << "closed" << std::endl;

	return ;
}

int Acc::_nbAccounts = 0;