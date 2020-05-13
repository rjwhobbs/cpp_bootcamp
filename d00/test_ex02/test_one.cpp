#include <iostream>
#include <vector>
#include "Acc.class.hpp"

int main(void) {

	typedef std::vector<Acc::t> 	accounts_t;
	int const 							amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	accounts_t 							accounts(amounts, amounts + (sizeof(amounts) / sizeof(amounts[0])));

	return 0;
}