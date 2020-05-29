#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include "Account.class.hpp"
using namespace std;

int main(void) {
	//I are breaking your accounts 
	Account::t account_one(2147483647);
	Account::t account_two(1);
	// accounts:2;total:-2147483648;deposits:0;withdrawals:0
	// Account::t account_three(1000000000);
	Account::displayAccountsInfos();
	return 0;
}