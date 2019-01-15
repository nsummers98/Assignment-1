#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	Player p1(100);

	while (p1.get_balance() > 0)
	{
		Hand playerHand;
		Hand dealerHand;
		cout << "You have $" << p1.get_balance() << ". Enter bet: ";

		int bet;
		cin >> bet;

		cout << "Your cards:" << endl;
		cout << "	" << /*Accessor Function*/ "        (" << /*Accessor Function*/ ")." << endl;
		cout << "Your total is " << playerHand.get_value() << ". Do you want another card? (y/n) ";
		cout << "Dealer's cards: " << endl;
		cout << "	" << /*Accessor Function*/ "        (" << /*Accessor Function*/ ")." << endl;
		cout << "The dealer's total is " << dealerHand.get_value() << "." << endl;
	}
	

	return 0;
}