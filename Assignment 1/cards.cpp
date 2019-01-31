#include "cards.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>


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


// Accessor: returns a string with the entire name of the card in Spanish
string Card::print_spanish_card() const
{
	string card = get_spanish_rank() + " de " + get_spanish_suit();
	return card;
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


// Accessor: returns a string with the entire name of the card in English
string Card::print_english_card() const
{
	string card = get_english_rank() + " of " + get_english_suit();
	return card;
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
	Card c;
	cards.push_back(c);
}


/*
Allows for access to the vector of cards stored in a Hand class
@param n represents the desired position in the hand of a desired card
@return the Card object at spot n of the vector
*/
Card Hand::get_card(int n) const
{
	return cards[n];
}


/*
Returns the value of the hand according to the rules of the card game
@return the value of the hand as a double
*/
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


// Returns the size of the vector of cards
int Hand::get_size() const
{
	return cards.size();
}

// Deals a new card by creating a new Card object and enlarging and inserting it into the vector
void Hand::deal_card()
{
	cout << "\nNew Card:" << endl;
	Card c;
	cards.push_back(c);
	int char_size = c.print_spanish_card().length() + c.print_english_card().length();
	cout << "	" << cards[cards.size() - 1].print_spanish_card() << setw(38 - char_size) << "(" << cards[cards.size() - 1].print_english_card() << ").\n\n";
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

/*
Accessor function to return the balance of the player
@return the balance of the player as an integer
*/
int Player::get_balance() const
{
	return money;
}

/*
Function prints game results to a text file called gamelog.txt
@param game represents the number of games played this session
@param bet represents the player's bet for this round
@param win represents the outcome of the win function to help determine the last game of the session
@param p represents the player's hand
@param d represents the dealer's hand
*/
void Player::print_to_doc(int game, int bet, int win, Hand p, Hand d) const
{

	ofstream fout;

	if (game == 1)
		fout.open("gamelog.txt");
	else if (game > 1)
		fout.open("gamelog.txt", fstream::in | fstream::out | fstream::app);

	fout << "-----------------------------------------------" << endl;
	fout << endl;
	fout << "Game number: " << game << "		Money left: $" << money << endl;
	fout << "Bet: " << bet << endl;
	fout << endl;
	fout << "Your cards:" << endl;
	fout << p;
	fout << "Your total: " << p.get_value() << "." << endl;
	fout << endl;
	fout << "Dealer's cards:" << endl;
	fout << d;
	fout << "Dealer's total is " << d.get_value() << "." << endl;
	fout << endl;

	if ((money - bet <= 0 && (win != 0 && win != 3)) || (money + bet >= 900 && (win != 1 && win != 2)))
	{
		fout << "-----------------------------------------------";
		fout.close();
	}
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

/*
Function overloads the stream output operators and acts as a print function
@param os represents the output stream
@param h represents any Hand object
@return an output stream of the entire vector of Cards within the Hand that can be used for file or console output
*/
ostream& operator<<(ostream& os, const Hand h)
{
	for (int i = 0; i < h.cards.size(); ++i)
	{
		int char_size = h.get_card(i).print_spanish_card().length() + h.get_card(i).print_english_card().length();
		os << "	" << h.get_card(i).print_spanish_card() << setw(38 - char_size) << "(" << h.get_card(i).print_english_card() << ").\n";
	}
	return os;
}