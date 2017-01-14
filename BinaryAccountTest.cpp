
#include <iostream>
#include <cassert>
#include <stdexcept>

#include "BinaryAccount.h"

using namespace std;

int main(){

	BinaryAccount* accountA1 = new BinaryAccount(10.12);
	BinaryAccount* accountB1 = new BinaryAccount(22.12);
	BinaryAccount* accountC1 = new BinaryAccount(accountA1, accountB1);
	assert(accountC1->getBalance() == 32.24);

	BinaryAccount* accountD1 = new BinaryAccount(accountC1, false);
	assert(accountD1->getBalance() == 32.24);

	BinaryAccount* accountE1 = new BinaryAccount(accountC1, true);
	assert(accountE1->getBalance() == 32.24);


	accountC1->clear();

	assert(accountC1->isLeaf());
	assert(accountC1->getAccountBalanceProperty() == nullptr);
	assert(accountC1->getLeftPtr() == nullptr);
	assert(accountC1->getRightPtr() == nullptr);



	/*BASIC FUNCTIONALITY TESTS */

	//Tests of Contructors
	/**
	BinaryAccount* accountA = new BinaryAccount(10.12);
	BinaryAccount* accountB = new BinaryAccount(22.12);
	BinaryAccount* accountC = new BinaryAccount(accountA, accountB);

	assert(accountA->getBalance() == 10.12);
	assert(accountB->getBalance() == 22.12);
	assert(accountC->getBalance() == 32.24);

	BinaryAccount* accountE = new BinaryAccount(25.34);
	BinaryAccount* accountF = new BinaryAccount(29.12);
	BinaryAccount* accountG = new BinaryAccount(accountE, accountF);

	BinaryAccount* accountH = new BinaryAccount(accountG, accountC);

	BinaryAccount* accountI = new BinaryAccount(accountE);
	BinaryAccount* accountJ = new BinaryAccount(accountF);
	try{
		//accountC->setBalance(34.44);
		//accountC->increaseBalance(9.88);
		//accountC->decreaseBalance(2.33);
	}catch(logic_error le){
		cout << le.what() << endl;
	}

	cout << "The balance of accountC is: " << accountC->getBalance() << endl;
	cout << "The balance of accountG is: " << accountG->getBalance() << endl;
	cout << "The balance of accountH is: " << accountH->getBalance() << endl;
	cout << "The balance of accountI is: " << accountI->getBalance() << endl;
	cout << "The balance of accountJ is: " << accountJ->getBalance() << endl;


	BinaryAccount* accountD = new BinaryAccount();
	cout << "The balance for accountD (before adding a subAccount is: " << accountD->getBalance() << endl;

	//Tets for addSubAccountMethod
	accountD->addSubAccount(new BinaryAccount(23.33));
	cout << "The balance for accountD (after adding a subAccont is: " << accountD->getBalance() << endl;

	accountD->addSubAccount(new BinaryAccount(4.44));
	cout << "The balance for accountD is: " << accountD->getBalance() << endl;
	**/

	return 0;
}