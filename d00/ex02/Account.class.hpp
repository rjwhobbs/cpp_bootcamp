// ************************************************************************** //
//                                                                            //
//                Account.class.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //
class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); // links to _nbAccounts
	static int	getTotalAmount( void ); // links to _totalAmount;
	static int	getNbDeposits( void ); // _totalNbDeposits;
	static int	getNbWithdrawals( void ); // _totalNbWithdrawals;
	static void	displayAccountsInfos( void ); // I'm guessing this displays all of the above

	Account( int initial_deposit );
	~Account( void );

	// looks like then that this function does all of the following:
	//  index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
	// ie, making the deposit and displaying the indivual amounts
	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	// I think this checks to see if the withdrawal can be made
	int		checkAmount( void ) const;
	//index:0;amount:42;deposits:0;withdrawals:0 from for each loop
	void	displayStatus( void ) const; 


private:

	// Link to displayAccountsInfos( void ), global class level amounts
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	// These seem to be for each individual account
	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// My boss is a dick                                                          //
// ************************************************************************** //
