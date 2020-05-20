#include <iostream>
#include <vector>
#include "Acc.class.hpp"

int main(void) {

	typedef std::vector<Acc::t> accounts_t;
	int const 									amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	size_t const								amounts_size(sizeof(amounts) / sizeof(amounts[0]));
	accounts_t									accounts(amounts, amounts + amounts_size);

	accounts[0].makeDeposit(5);
	accounts[0].makeDeposit(5);
	accounts[1].makeDeposit(765);

	return 0;
}