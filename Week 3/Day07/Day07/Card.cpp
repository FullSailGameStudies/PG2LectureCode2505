#include "Card.h"
#include <iostream>

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
