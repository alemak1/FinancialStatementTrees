
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include "Account.h"

using namespace std;



int main(){
	Account* plant = new Account("Manufacturing Facility X111");

	try{ 
		plant->increaseContraAccount(50);
	}catch(logic_error le){
		cout << le.what() << endl;
	}

	plant->debitBalance(500);
	cout << *plant << endl;


	Account* accumulated_depreciation = new Account("Accumulated Depreciation");
	Account* building = new Account("Building", accumulated_depreciation);
	building->debitBalance(100);
	assert(static_cast<int>(*building) == 100);
	assert(building->getNetBalance() == 100);

	building->increaseContraAccount(50);
	assert(building->getOriginalBalance() == 100);
	assert(building->getNetBalance() == 50);
	assert(static_cast<int>(*building) == 50);

	cout << "The net value of the building account is: " << *building << endl;
	cout << "The net value of the building account is: " << static_cast<int>(*building) << endl;
	cout << *building << endl;




	return 0;
}