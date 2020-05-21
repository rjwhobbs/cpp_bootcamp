#ifndef ACC_CLASS_HPP
#define ACC_CLASS_HPP

class Acc {
	public:

		typedef Acc t;

		Acc(int initial_deposit);
		~Acc(void);

		void makeDeposit(int deposit);
		void displayStatus(void) const; 

	private:

		static int	_nbAccounts;
		static int	_totalNbDeposits;

		int _accountIndex;
		int _amount;
		int	_nbDeposits;

		Acc(void);
};

#endif