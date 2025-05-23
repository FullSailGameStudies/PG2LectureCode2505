#pragma once
#include "Weapon.h"
class Knife : public Weapon
{
public:
	Knife(int length, int range, int damage) :
		Weapon(range, damage), length_(length)
	{ }
	void showMe() override;

private:
	int length_;
};

