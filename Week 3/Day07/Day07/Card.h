#pragma once
#include <string>
#include "enums.h"

class Card
{
	//access modifiers control the visibility to outside code
//public: ALL code can see it/callit/changeit
public:

	//protected: my class (Card) and all descendent class
	//  can see it

	void Reveal();//declaration

	//getters/setters are about accessing FIELDS
	// the gatekeepers of the fields (control the access)
	//getters/setters CAN BE DEFINED in the header
	// 
	//getter (accessor)
	//  return the value of the field
	//	most of the time they are const methods
	//  the return type matches the type of the field
	//	most of the time there are NO parameters
	const std::string& GetFace() const
	{
		return face_;
	}

	CardSuit Suit() const
	{
		return suit_;
	}

	//setters (mutators)
	//  allow you to change the field (cannot be const)
	//  usually have 1 parameter that matches the type
	//		of the field
	//  usually return type is void
	void SetFace(const std::string& face)
	{
		if (not face.empty() && ValidFace(face))
		{
			face_ = face;
		}
	}

	void Suit(CardSuit suit)
	{
		if(suit >= CardSuit::Clubs && suit <= CardSuit::Diamonds)
			suit_ = suit;
	}
protected:

	//private: ONLY this class can see it
	//keep it secret, keep it hidden
private:
	bool ValidFace(const std::string& face)
	{
		return face == "2" || face == "3" || face == "4" ||
			face == "5" || face == "6" || face == "7" || face == "8" ||
			face == "9" || face == "10" || face == "J" || face == "Q" ||
			face == "K" || face == "A"
			;
	}

	//Fields: data members
	//  suit, value, face

	//  m_iValue, m_value, mValue, _Value, value_
	int value_;//class level
	std::string face_;
	CardSuit suit_;

	void Simple(int value)//could a variable in a different scope
	{
		int val = 5;//local variable
		value_ = value;
	}

};

