#include "Card.h"
#include <iostream>


//use the member initialization list to initialize the fields
Card::Card(const std::string& face, CardSuit suit) :
	//member initialization list
	face_(face),
	suit_(suit),
	value_(GetValue(face))
{
	//face_ = face;
	//suit_ = suit;
}

void Card::Reveal()
{
	//this method can access the fields of the class
	std::cout << face_ << " ";
	switch (suit_)
	{
	case Clubs:
		std::cout << "Clubs";
		break;
	case Spades:
		std::cout << "Spades";
		break;
	case Hearts:
		std::cout << "Hearts";
		break;
	case Diamonds:
		std::cout << "Diamonds";
		break;
	default:
		break;
	}
}
