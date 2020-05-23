#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <time.h>  
#include "Acc.class.hpp"

int main(void) {

	typedef std::vector<Acc::t> accounts_t;
	int const 									amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	size_t const								amounts_size(sizeof(amounts) / sizeof(amounts[0]));
	accounts_t									accounts(amounts, amounts + amounts_size);
	accounts_t::iterator				acc_begin(accounts.begin());
	accounts_t::iterator				acc_end(accounts.end());
	time_t											rawtime;
	struct tm 									*timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::cout <<  timeinfo->tm_year << ":" << timeinfo->tm_mon << ":"<< timeinfo->tm_mday << ":" << timeinfo->tm_hour << ":" << timeinfo->tm_min << std::endl;

	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Acc::displayStatus));

	(*acc_begin).makeDeposit(5);

	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Acc::displayStatus));

	(*acc_begin).makeWithdrawal(300);
	(*(acc_begin + 1)).makeWithdrawal(10);

	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Acc::displayStatus));

	return 0;
}