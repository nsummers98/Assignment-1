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
void waitForInput();


// Non member functions implementations (if any)
int winner(Hand h1, Hand h2)
{
	if (h1.get_value() <= 7.5 && (h1.get_value() > h2.get_value() || h2.get_value() > 7.5)) // player wins
		return 0;
	if (h2.get_value() <= 7.5 && (h2.get_value() > h1.get_value() || h1.get_value() > 7.5)) // dealer wins
		return 1;
	if (h1.get_value() > 7.5 && h2.get_value() > 7.5) // both bust
		return 2;
	if (h1.get_value() == h2.get_value()) // tie
		return 3;
}

void waitForInput()
{
	do
	{
		cout << "\nPress enter key to continue . . .";
	} while (cin.get() != '\n');
	cin.ignore();
}



int main() {
	Player p1(100);
	int gamecount = 1;

	while (p1.get_balance() > 0 && p1.get_balance() < 900)
	{
		Hand playerHand;
		Hand dealerHand;

		if (gamecount > 1)
			cout << "\n";
		cout << "          Game " << gamecount << endl;

		int bet;
		do
		{
			cout << "You have $" << p1.get_balance() << ". Enter bet: ";
			cin >> bet;
		} while (p1.bet(bet) == 0);

		char res = 'y';
		while ((res == 'y' || res == 'Y') && playerHand.get_value() <= 7.5)
		{
			cout << "\nYour cards:" << endl;
			cout << playerHand.print_hand();
			cout << "Your total is " << playerHand.get_value() << ". Do you want another card? (y/n) ";
			cin >> res;
			if (res == 'y' || res == 'Y')
			{
				playerHand.deal_card();
				if (playerHand.get_value() > 7.5)
				{
					cout << "Bust!" << endl;
					cout << "Your total is " << playerHand.get_value() << endl;
					waitForInput();
					break;
				}
			}
		}

		int n = 0;
		while (dealerHand.get_value() <= 7.5)
		{
			if (n > 0 && dealerHand.get_value() < 5.5)
				dealerHand.deal_card();
			cout << "\nDealer's cards: " << endl;
			cout << dealerHand.print_hand();
			cout << "\nThe dealer's total is " << dealerHand.get_value() << "." << endl;
			++n;
			if (dealerHand.get_value() >= 5.5)
				break;
		}

		int win = winner(playerHand, dealerHand);
		cout << endl;
		if (win == 0)
		{
			cout << "You win $" << bet << ". Congratulations.\n" << endl;
			p1.win(bet);
		}
		else if (win == 1 || win == 2)
		{
			cout << "You lose $" << bet << ". Too bad.\n" << endl;
			p1.lose(bet);
		}
		else if (win == 3)
		{
			cout << "Round is a tie!\n" << endl;
		}

		++gamecount;
	}
	
	if (p1.get_balance() <= 0)
	{
		cout << "You're broke! GAME OVER!" << endl;
		cout << "Come back when you have more money." << endl;
	}
	else if (p1.get_balance() >= 900)
	{ 
		cout << "Congratulations! You ran the house!" << endl;
	}

	cout << "\nBye!" << endl;

 	return 0;
}