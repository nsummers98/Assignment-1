#include <string>
#include <vector>
#include <fstream>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

enum suit_t { OROS, COPAS, ESPADAS, BASTOS };

/*
The values for this type start at 0 and increase by one
afterwards until they get to SIETE.
The rank reported by the function Card::get_rank() below is
the value listed here plus one.
E.g:
The rank of AS is reported as    static_cast<int>(AS) + 1   = 0 + 1 =  1
The rank of SOTA is reported as  static_cast<int>(SOTA) + 1 = 9 + 1 = 10
*/
enum rank_t { AS, DOS, TRES, CUATRO, CINCO, SEIS, SIETE, SOTA = 9, CABALLO = 10, REY = 11 };

class Card {
public:
	// Constructor assigns random rank & suit to card.
	Card();

	// Accessors 
	string get_spanish_suit() const;
	string get_spanish_rank() const;
	string print_spanish_card() const;

	string get_english_suit() const;
	string get_english_rank() const;
	string print_english_card() const;

	// Converts card rank to number.
	// The possible returns are: 1, 2, 3, 4, 5, 6, 7, 10, 11 and 12
	int get_rank() const;

	// Compare rank of two cards. E.g: Eight<Jack is true.
	// Assume Ace is always 1. 
	// Useful if you want to sort the cards.
	bool operator < (Card card2) const;

private:
	suit_t suit;
	rank_t rank;
};


class Hand {
public:
	// Constructor
	Hand();

	// Accessors
	Card get_card(int n) const;
	double get_value() const;
	int get_size() const;

	// Mutator
	void deal_card();

	// Operator Overloading
	friend ostream& operator<<(ostream& os, const Hand h);

private:
	vector<Card> cards;
	double handTotal;
};


class Player {
public:
	// Constructor
	Player(int m);

	// Accessors
	int get_balance() const;
	void print_to_doc(int game, int bet, int win, Hand p, Hand d) const;

	// Mutators
	int bet(int m);
	int win(int m);
	int lose(int m);

private:
	int money;
};

#endif