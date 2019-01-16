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
int winner(Hand h1, Hand h2);


// Non member functions implementations (if any)
int winner(Hand h1, Hand h2)
{
	if (h1.get_value() < 7.5 && (h1.get_value() > h2.get_value() || h2.get_value() > 7.5)) // player wins
		return 0;
	if (h2.get_value() < 7.5 && (h2.get_value() > h1.get_value() || h1.get_value() > 7.5)) // dealer wins
		return 1;
	if (h1.get_value() > 7.5 && h2.get_value() > 7.5) // both bust
		return 2;
	if (h1.get_value() == h2.get_value()) // tie
		return 3;
}



int main() {
	Player p1(100);

	while (p1.get_balance() > 0 || p1.get_balance() < 999)
	{
		Hand playerHand;
		Hand dealerHand;
		cout << "You have $" << p1.get_balance() << ". Enter bet: ";

		int bet;
		cin >> bet;
		if (p1.bet(bet) == 0)
			break;

		char res = 'y';
		while (res == 'y' || res == 'Y')
		{
			cout << "\nYour cards:" << endl;
			cout << playerHand.print_hand();
			cout << "Your total is " << playerHand.get_value() << ". Do you want another card? (y/n) ";
			cin >> res;
			if (res == 'y' || res == 'Y')
				playerHand.deal_card();
		}

		int n = 0;
		while (dealerHand.get_value() < 5.5)
		{
			if (n != 0)
				dealerHand.deal_card();
			cout << "\n\nDealer's cards: " << endl;
			cout << dealerHand.print_hand();
			++n;
		}
		cout << "The dealer's total is " << dealerHand.get_value() << "." << endl;

		switch(winner(playerHand, dealerHand))
		{
		case 0:
			cout << "You win $" << bet << ". Congratulations.\n" << endl;
			p1.win(bet);
		case 1:
			cout << "You lose $" << bet << ". Too bad.\n" << endl;
			p1.lose(bet);
		case 2:
			cout << "You lose $" << bet << ". Too bad.\n" << endl;
			p1.lose(bet);
		case 3:
			cout << "Round is a tie!\n" << endl;
		default:break;
		}

	}
	

	return 0;
}