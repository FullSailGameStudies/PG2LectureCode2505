#pragma once
#include "..\..\Day07\Day07\Card.h"
class BlackjackCard : public Card  //is-a relationship  BlackjackCard is-a Card
{
public:
	//need a ctor that calls the base ctor
	BlackjackCard(const std::string& face, CardSuit suit) 
		//member initialization list
		: Card(face,suit)
	{

	}

	//2) add a new definition in the derived
	int GetValue(const std::string& face)const override;
};

