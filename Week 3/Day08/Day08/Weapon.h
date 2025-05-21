#pragma once
class Weapon
{
protected:
	int mRange;
	int mDamage;//non-static data members

public:
	Weapon(int range, int damage);

	void showMe();
	//pure virtual
	virtual int calcDamage() = 0;

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

