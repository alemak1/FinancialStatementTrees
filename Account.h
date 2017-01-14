
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

using namespace std;

class Account{
private:
	string name;
	double balance = 0;
	Account* contraAccount = nullptr;
protected:
	ostream& printAccount(ostream& os, const Account& someAccount){
		os << "Account Name: " << name << ", " << "Current Balance: " << getNetBalance();
		return os;
	}
public:
	Account(){};
	Account(string accountName): name(accountName){};
	Account(string accountName, Account* someContraAccount): name(accountName){
		contraAccount = someContraAccount;
	}

	void debitBalance(double additional_amount){
		balance += additional_amount;
	}

	double getOriginalBalance() const{
		return balance;
	}

	double getNetBalance() const{
		if(contraAccount == nullptr){
			return getOriginalBalance();
		}

		return balance - contraAccount->getOriginalBalance();
	}

	void increaseContraAccount(double  additional_amount) throw(logic_error){
		if(contraAccount == nullptr){
			throw logic_error("Invalid operation: the current account does not have a contra account associated with it");
		}
		contraAccount->debitBalance(additional_amount);
	}

	operator int() const{
		return getNetBalance();
	}

	friend ostream& operator<<(ostream& os, Account& anAccount);

};

ostream& operator<<(ostream& os, Account& anAccount){
		return anAccount.printAccount(os, anAccount);
	};


#endif