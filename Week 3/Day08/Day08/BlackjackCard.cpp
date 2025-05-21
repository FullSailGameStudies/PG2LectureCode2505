#include "BlackjackCard.h"

int BlackjackCard::GetValue(const std::string& face)const
{
	//how we override:
	//  EXTEND the base: call the base method
	//  FULLY-override the base: do NOT call the base method

	//int value = Card::GetValue(face);//extending the base
	if (face == "J" || face == "Q" || face == "K")
		return 10;
	else if (face == "A")
		return 11;

	return std::stoi(face);
}