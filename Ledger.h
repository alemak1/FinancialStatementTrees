/**

As the basic building block for the data model, the ledger allows for financial statements(balance sheets, income statements, cash flow statements, etc.)
to be represented in the model layer as multi-array tree structures.  

Each instance of ledger stores an array of ledgers (if the ledger contains subaccounts).  If the ledger does not contain any 
subaccounts, then it is a leaf account and therefore has a balance; if the ledger is not a leaf account, then it contains one or more
pointers to other ledgers (e.g. an Long-Term Assets ledger contains pointers to a Property ledger, a Plant ledger, and an Equipment ledger,
which can in turn store pointers to other ledgers.  )

TODO:
	User can look up any account node (such as PPE(property,plant, and equipment) and find the net amount for that node).
	Users can query a ledger instance for the number of accounts in a given node.
	User can query ledger objects for all the accounts in at a particular level in the tree structure (level-order traverse)
	Each ledger has a nested account class, which in turn can be used
	Each debit and credit is subjected to built-in constraints that ensure that the accounting equation is maintained at all times.
	
	Transaction objects can be created by way of a factory method on the Transaction class.
	The function call operator for a ledger is overloaded so as to accept arguments of Transaction type; each transaction object
	can be passed into the ledger to update the internal state of the ledger.
	Create a custom iterator for transaction collection.
	Overload the conversion, arithmetical, and relational operators for the transaction objects, use a static property to represent
		the sorting key that will be used, implementation of the overloaded operators and conversion operator will change based on the sorting key

	Outputs:
		Files for statistical summaries and reports
		MySQL statements for use with MySQL clients
		JSON data for use with potential Restful APIs

**/

#ifndef LEDGER_H
#define LEDGER_H

#include "BinaryAccount.h"

using namespace std;

class Ledger{
private:
	Ledger** rootAccount;
public:
	
};

#endif