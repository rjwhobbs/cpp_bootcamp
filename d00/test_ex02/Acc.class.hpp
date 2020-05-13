#ifndef ACC_CLASS_HPP
#define ACC_CLASS_HPP

class Acc {
	public:

		typedef Acc t;

		Acc(int initial_deposit);
		~Acc(void);

	private:

		static int	_nbAccounts;

		int _accountIndex;
		int _amount;

		Acc(void);
};

#endif