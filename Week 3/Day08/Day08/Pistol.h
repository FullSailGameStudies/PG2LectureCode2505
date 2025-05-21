#pragma once
#include "Weapon.h"
#include <iostream>
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity)
		: Weapon(range, damage), rounds_(rounds), magCapacity_(magCapacity)
	{
		std::cout << mRange;
	}

	virtual int calcDamage()
	{
		return Weapon::calcDamage();
	}

	Pistol operator+(const Pistol& other)
	{
		Pistol newPistol(
			std::max(mRange,other.mRange),
			std::max(mDamage, other.mDamage),
			rounds_ + other.rounds_,
			std::max(magCapacity_, other.magCapacity_)
		);
		return newPistol;

	}

	int Rounds() const { return rounds_; }
	void Rounds(int newRounds)
	{
		if (newRounds >= 0 && newRounds <= magCapacity_)
			rounds_ = newRounds;
	}
	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int newMagCap)
	{
		if (newMagCap > 0 && newMagCap <= 12)
			magCapacity_ = newMagCap;
	}


private:
	int rounds_, magCapacity_;
public:

};

