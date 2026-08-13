#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount - deposit)
              << ";deposit:" << deposit
              << ";amount:" << _amount
              << ";nb_deposits:" << _totalNbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex
                  << ";p_amount:" << _amount
                  << ";withdrawal:refused"
                  << std::endl;
        return false;
    }

    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;

    std::cout << "index:" << _accountIndex
              << ";p_amount:" << (_amount + withdrawal)
              << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _totalNbWithdrawals
              << std::endl;

    return true;
}

int Account::checkAmount() const
{
    return _amount;
}

void Account::displayStatus() const
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";status" << std::endl;
}

void Account::_displayTimestamp()
{
    std::cout << "[19920104_091532] ";
}

