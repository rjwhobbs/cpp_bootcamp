#ifndef ACC_CLASS_HPP
#define ACC_CLASS_HPP

class Acc {
	public:

		typedef Acc t;

		Acc(int initial_deposit);
		~Acc(void);

		void makeDeposit(int deposit);
		bool makeWithdrawal(int withdrwal);
		int checkAmount(void) const;
		void displayStatus(void) const; 

	private:

		static int	_nbAccounts;
		static int	_totalNbDeposits;
		static int	_totalNbWithdrawals;

		static void _displayTimestamp(void);

		int _accountIndex;
		int _amount;
		int	_nbDeposits;
		int	_nbWithdrawals;

		Acc(void);
};

#endif