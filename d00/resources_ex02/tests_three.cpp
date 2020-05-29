#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include "Account.class.hpp"
using namespace std;

int main(void) {
	typedef std::vector<Account::t> accounts_t;

	// Why is this causing the destructor to be called twice, once before
  // the last function call and once after?
	// [20200529_070751] index:0;amount:10;created
	// [20200529_070751] index:0;amount:10;closed
	// [20200529_070751] accounts:0;total:10;deposits:0;withdrawals:0
	// [20200529_070751] index:0;amount:10;closed

	accounts_t accounts(1, 10);
	Account::displayAccountsInfos();

	return 0;
}