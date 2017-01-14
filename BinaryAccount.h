
#ifndef _BINARY_ACCOUNT_H
#define _BINARY_ACCOUNT_H

#include <stdexcept>
#include <string>

using namespace std;


class BinaryAccount{
private:
	int accountID = 0;
	string accountName = string("");
	double* balance = nullptr;
	BinaryAccount* leftPtr = nullptr;
	BinaryAccount* rightPtr = nullptr;
protected:
	void check(BinaryAccount* someAccount) throw(logic_error){
		if(!someAccount->isLeaf()){
			throw logic_error("Operation failed: operation can only be performed for a leaf account");
		}
	}

	BinaryAccount* copyBinaryAccount(BinaryAccount* anotherBinaryAccount){

		if(anotherBinaryAccount != nullptr){
			BinaryAccount* newBinaryAccount = new BinaryAccount();
			
			newBinaryAccount->balance = anotherBinaryAccount->balance;
			newBinaryAccount->accountID = anotherBinaryAccount->accountID;
			newBinaryAccount->accountName = anotherBinaryAccount->accountName;

			if(anotherBinaryAccount->isLeaf()){
				
				newBinaryAccount->setLeftPtr(nullptr);
				newBinaryAccount->setRightPtr(nullptr);
			}else{
				newBinaryAccount->setLeftPtr(copyBinaryAccount(anotherBinaryAccount->getLeftPtr()));
				newBinaryAccount->setRightPtr(copyBinaryAccount(anotherBinaryAccount->getRightPtr()));
			}


			return newBinaryAccount;
		}

		return nullptr;
	}


	void destroyBinaryAccount(BinaryAccount* anotherBinaryAccount){

		if( anotherBinaryAccount != nullptr){
			delete balance;
			balance = nullptr;

			destroyBinaryAccount(anotherBinaryAccount->getLeftPtr());
			delete leftPtr;
			leftPtr = nullptr;

			destroyBinaryAccount(anotherBinaryAccount->getRightPtr());
			delete rightPtr;
			rightPtr = nullptr;
		}


	}


	BinaryAccount& copyToCurrent(BinaryAccount* anotherBinaryAccount){
		*this = *copyBinaryAccount(anotherBinaryAccount);
		return *this;
	}


	

	void setLeftPtr(BinaryAccount* newLeftPtr){
		leftPtr = newLeftPtr;
	}

	void setRightPtr(BinaryAccount* newRightPtr){
		rightPtr = newRightPtr;
	}

	
public:
	double* getAccountBalanceProperty(){
		return balance;
	}

	BinaryAccount* getLeftPtr(){
		return leftPtr;
	}

	BinaryAccount* getRightPtr(){
		return rightPtr;
	}

	BinaryAccount(){
		balance = new double(0);
	};

	BinaryAccount(double new_balance){
		balance = new double(new_balance);
	};

	//Copy constructor
	BinaryAccount(BinaryAccount* anotherBinaryAccount, bool isShallowCopy){
		if(!isShallowCopy){
			copyToCurrent(anotherBinaryAccount);
		}else{
			rightPtr = anotherBinaryAccount->getRightPtr();
			leftPtr = anotherBinaryAccount->getLeftPtr();
			accountName = anotherBinaryAccount->getAccountName();
			accountID = anotherBinaryAccount->getAccountID();
			balance = anotherBinaryAccount->getAccountBalanceProperty();

		}

	}

	virtual ~BinaryAccount(){
		destroyBinaryAccount(this);
	}

	void clear(){
		destroyBinaryAccount(this);
	}



	//Assignment operator
	BinaryAccount& operator=(BinaryAccount* anotherBinaryAccount){
		destroyBinaryAccount(this);	
		return copyToCurrent(anotherBinaryAccount);
	}


	BinaryAccount(BinaryAccount* ptr1, BinaryAccount* ptr2 = nullptr){
		leftPtr = ptr1;
		rightPtr = ptr2;
	}

	BinaryAccount(double new_balance, string acct_name, int acct_id = 0){
		balance = new double(new_balance);
		accountName = acct_name;
		accountID = acct_id;
	};

	


	void setAccountName(const string& acct_name){
		accountName = acct_name;
	}

	void setAccountID(const int acct_id){
		accountID = acct_id;
	}

	const string& getAccountName() const{
		return this->accountName;
	}

	const int& getAccountID() const{
		return this->accountID;
	}

	

	bool isLeaf() const{
		return leftPtr == nullptr && rightPtr == nullptr;
	}

	bool nodeIsComplete() const{
		return (leftPtr != nullptr && rightPtr != nullptr);
	}


	void setBalance(const double& new_balance){
		check(this);

		*balance = new_balance;
	};

	const double& getBalance() const{
		double* sum = new double(0);

		if(isLeaf()){
			*sum += *balance;
		}else{
			if(leftPtr !=  nullptr){
				*sum +=  leftPtr->getBalance();
			}

			if(rightPtr != nullptr){
				*sum += rightPtr->getBalance();
			}
		}

		return *sum;
	}

	void increaseBalance(const double increase_amount){
		check(this);
		*balance += increase_amount;
	};

	void decreaseBalance(const double decrease_amount){
		check(this);
		*balance -= decrease_amount;
	}

	void addSubAccount(BinaryAccount* newAccount) throw(logic_error){
		// if(nodeIsComplete()){
		// 	throw logic_error("Operation failed: this node cannot accept additional binary accounts");
		// }

		if(leftPtr == nullptr && rightPtr == nullptr){
			leftPtr = newAccount;
			delete balance;
			balance = nullptr;
		}else{


			if(leftPtr != nullptr && rightPtr == nullptr){
				assert(balance == nullptr);
				rightPtr = newAccount;
			}

			if(leftPtr == nullptr && rightPtr != nullptr){
				assert(balance == nullptr);
				leftPtr = newAccount;
			}

		}
	}
};






#endif