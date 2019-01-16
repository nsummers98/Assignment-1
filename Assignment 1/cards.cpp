#include "cards.h"
#include <cstdlib>
#include <iostream>

/*
You might or might not need these two extra libraries
#include <iomanip>
#include <algorithm>
*/


/* *************************************************
Card class
************************************************* */

/*
Default constructor for the Card class.
It could give repeated cards. This is OK.
Most variations of Blackjack are played with
several decks of cards at the same time.
*/
Card::Card() {
	int r = 1 + rand() % 4;
	switch (r) {
	case 1: suit = OROS; break;
	case 2: suit = COPAS; break;
	case 3: suit = ESPADAS; break;
	case 4: suit = BASTOS; break;
	default: break;
	}

	r = 1 + rand() % 10;
	switch (r) {
	case  1: rank = AS; break;
	case  2: rank = DOS; break;
	case  3: rank = TRES; break;
	case  4: rank = CUATRO; break;
	case  5: rank = CINCO; break;
	case  6: rank = SEIS; break;
	case  7: rank = SIETE; break;
	case  8: rank = SOTA; break;
	case  9: rank = CABALLO; break;
	case 10: rank = REY; break;
	default: break;
	}
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const {
	string suitName;
	switch (suit) {
	case OROS:
		suitName = "oros";
		break;
	case COPAS:
		suitName = "copas";
		break;
	case ESPADAS:
		suitName = "espadas";
		break;
	case BASTOS:
		suitName = "bastos";
		break;
	default: break;
	}
	return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const {
	string rankName;
	switch (rank) {
	case AS:
		rankName = "As";
		break;
	case DOS:
		rankName = "Dos";
		break;
	case TRES:
		rankName = "Tres";
		break;
	case CUATRO:
		rankName = "Cuatro";
		break;
	case CINCO:
		rankName = "Cinco";
		break;
	case SEIS:
		rankName = "Seis";
		break;
	case SIETE:
		rankName = "Siete";
		break;
	case SOTA:
		rankName = "Sota";
		break;
	case CABALLO:
		rankName = "Caballo";
		break;
	case REY:
		rankName = "Rey";
		break;
	default: break;
	}
	return rankName;
}



// Accessor: returns a string with the suit of the card in English
string Card::get_english_suit() const {
	string englishSuit;

	switch (suit)
	{
	case OROS:
		englishSuit = "coins";
		break;
	case COPAS:
		englishSuit = "cups";
		break;
	case ESPADAS:
		englishSuit = "spades";
		break;
	case BASTOS:
		englishSuit = "clubs";
		break;
	default: break;
	}

	return englishSuit;
}

// Accessor: returns a string with the rank of the card in English
string Card::get_english_rank() const {
	string englishRank;

	switch (rank) {
	case AS:
		englishRank = "Ace";
		break;
	case DOS:
		englishRank = "Two";
		break;
	case TRES:
		englishRank = "Three";
		break;
	case CUATRO:
		englishRank = "Four";
		break;
	case CINCO:
		englishRank = "Five";
		break;
	case SEIS:
		englishRank = "Six";
		break;
	case SIETE:
		englishRank = "Seven";
		break;
	case SOTA:
		englishRank = "Jack";
		break;
	case CABALLO:
		englishRank = "Knight";
		break;
	case REY:
		englishRank = "King";
		break;
	default: break;
	}

	return englishRank;
}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
	return static_cast<int>(rank) + 1;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
	return rank < card2.rank;
}



/* *************************************************
Hand class
************************************************* */

/*
Default constructor for a Hand object
Creates a vector of Cards of size 1
*/
Hand::Hand()
{
	vector<Card> cards[1];
}

Card Hand::get_card(int n) const
{
	return cards[n];
}


double Hand::get_value() const
{
	double val = 0;

	for (int i = 0; i < cards.size(); ++i)
	{
		double rank = cards[i].get_rank();
		if (rank < 8)
			val += rank;
		else val += 0.5;
	}

	return val;
}


/* *************************************************
Player class
************************************************* */

/*
Constructor for the Player class.
@param m represents the player's new balance
*/
Player::Player(int m)
{
	money = m;
}

int Player::get_balance() const
{
	return money;
}

/*
Function sees if Player has enough money to make bet
@param m represents the amount the player wants to bet
*/
int Player::bet(int m)
{
	if (m > money)
	{
		cout << "Insufficient Funds" << endl;
		return 0;
	}
	else return m;
}

/*
Function adds bet amount to Player's balance
@param m represents the bet amount to be added to the balance
@return the amount of the bet in order to determine overall game progress
*/
int Player::win(int m)
{
	money += m;
	return m;
}

/*
Function subtracts bet amount from Player's balance
@param m represents the bet amount to be subtracted from the balance
@return the amount of the bet in order to determine overall game progress
*/
int Player::lose(int m)
{
	money -= m;
	return m;
}