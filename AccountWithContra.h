

#ifndef ACCOUNT_WITH_CONTRA_H
#define ACCOUNT_WITH_CONTRA_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>
#include <algorithm>
#include <numeric>

using namespace std;

class AccountWithContra{
private:
	string name;
	double balance = 0;

public:
	AccountWithContra(string account_name): name(account_name){};
	AccountWithContra(string account_name, string contra_account_name): name(account_name){
		addContraAccount(contra_account_name);
	};

	void increaseBalance(double additional_amount){
		balance += additional_amount;
	}

	void increaseContraBalance(const string& account_name, double additional_amount) throw(logic_error){
		AccountWithContra::ContraAccount* account = nullptr;
		account = AccountWithContra::ContraAccount::getContraAccount(account_name);

		if(account == nullptr){
			throw logic_error("Operation failed: contra account with name " + account_name + " could not be found");
		}

		account->increaseBalance(additional_amount);
	}

	double getOriginalBalance() const{
		return balance;
	}

	double getNetBalance() const{
		return balance - AccountWithContra::ContraAccount::getSumOfContraAccountBalances();
	}

	

	class ContraAccount{
	private:
		const static int MAX_NUMBER_OF_CONTRA_ACCOUNTS = 10;
		string name;
		double balance = 0;
	public:
		static int numberOfContraAccounts;
		static ContraAccount* contraAccounts;

		ContraAccount(){};
		ContraAccount(string account_name): name(account_name){
			contraAccounts[numberOfContraAccounts] = *this;
			numberOfContraAccounts++;
		};

		void increaseBalance(double additional_amount){
			balance += additional_amount;
		}

		const double& getOriginalBalance() const{
			return this->balance;
		}

		const string& getName() const{
			return this->name;
		}

		static ContraAccount* getContraAccount(string name) throw(logic_error){

			ContraAccount* newAccount = nullptr;

			for(unsigned i = 0; i < numberOfContraAccounts; i++){
				if(contraAccounts[i].getName() == name){
					newAccount = contraAccounts + i;
				}
			}

			if(newAccount == nullptr){
				throw logic_error("Operation Failed: account with name specified could not be found");
			}

			return newAccount;
		}

		static double getSumOfContraAccountBalances(){

			double sum = 0;

			for(unsigned i = 0; i < numberOfContraAccounts; i++){
				sum += static_cast<double>(contraAccounts[i]);
			}

			return sum;
			};

		ContraAccount& operator=(const ContraAccount& rhs){
			name = rhs.name;
			balance = rhs.balance;
			return *this;
		}

		operator double() const{
			return getOriginalBalance();
		}

	};

	void addContraAccount(string account_name){
		AccountWithContra::ContraAccount newContraAccount(account_name);
	}




};

int AccountWithContra::ContraAccount::numberOfContraAccounts = 0;

AccountWithContra::ContraAccount* AccountWithContra::ContraAccount::contraAccounts = new AccountWithContra::ContraAccount[AccountWithContra::ContraAccount::MAX_NUMBER_OF_CONTRA_ACCOUNTS];



#endif