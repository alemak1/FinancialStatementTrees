
#include <iostream>
#include <string>
#include <stdexcept>
#include <cassert>

#include "AccountWithContra.h"

using namespace std;


int main(){
	AccountWithContra building1("Building","Accumulated Depreciation YR1");
	building1.addContraAccount("Accumulated Depreciation YR2");
	building1.addContraAccount("Accumulated Depreciation YR3");

	building1.increaseBalance(100);
	assert(building1.getOriginalBalance() == 100);

	try{
		building1.increaseContraBalance("Accumulated Depreciation YR1", 50);
		building1.increaseContraBalance("Accumulated Depreciation YR2", 20);
		building1.increaseContraBalance("Accumulated Depreciation YR3", 10);
		assert(building1.getNetBalance() == 20);
	}catch(logic_error le){
		cout << le.what() << endl;
	}

	return 0;
}