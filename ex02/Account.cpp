#include <iostream>
#include <iomanip>
#include <sstream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void){}

Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

Account::~Account(void)
{
#ifdef __linux__
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
#else
	std::string			s;
	std::ostringstream	oss;
	static std::string	des_arr[8];

	Account::_nbAccounts--;
	oss << this->_accountIndex << std::flush;
	s = oss.str();
	des_arr[Account::_nbAccounts] = "index:" + s + ";";
	oss.str("");
	oss << this->_amount << std::flush;
	s = oss.str();
	des_arr[Account::_nbAccounts] += "amount:" + s + ";" + "closed";
	oss.str("");
	if (Account::_nbAccounts == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			Account::_displayTimestamp();
			std::cout << des_arr[i] << std::endl;;
		}
	}
#endif
}

int Account::getNbAccounts(void)
{ return Account::_nbAccounts; }

int Account::getTotalAmount(void)
{ return Account::_totalAmount; }

int Account::getNbDeposits(void)
{ return Account::_totalNbDeposits; }

int Account::getNbWithdrawals(void)
{ return Account::_totalNbWithdrawals; }

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";";
	std::cout << "total:" << Account::getTotalAmount() << ";";
	std::cout << "deposits:" << Account::getNbDeposits() << ";";
	std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] ";
}

void Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << ++this->_nbDeposits << std::endl;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" <<  this->_amount << ";";
	if (this->_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;
}

int Account::checkAmount(void) const
{ return this->_amount; }
