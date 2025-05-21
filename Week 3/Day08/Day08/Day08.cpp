// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "BlackjackCard.h"
#include "Pistol.h"
#include <vector>

//class A
//{
//public:
//	int x;
//protected:
//	int y;
//private:
//	int z;
//};
//
////modes of inheritance:
////  public:  the access modifiers don't change
////		x stays public, y stays protected, z stays private (inaccessible in B)
////  protected:
////		x becomes protected, y stays protected, z stays private (inaccessible in B)
////  private: (default if not specified)
////		x becomes private in B, y private in B, z stays private (inaccessible in B)
//class B : public A
//{
//
//};

int Add(int n1, int n2) 
{
	return 5;
}
//double Add(int n1, int n2)
//{
//	return 5;
//}
double Add(double n1, double n2)
{
	return 5;
}
int Add(int n1, int n2, int n3)
{
	return 7;
}

void Counter()
{
	static int i = 10;
	std::cout << i << " ";
	i++;
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		Counter();
	}
	//compile-time
	Add(5, 2);
	Add(5.2, 2.1);
	Add(5, 2, 1);
	/*
		╔═══════════════╗
		║  Inheritance  ║
		╚═══════════════╝

								╔═════════╗     ╔══════════╗
						 class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)



				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car

	*/

	Card c1("A", CardSuit::Spades);
	BlackjackCard jack("A", CardSuit::Spades);



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			add a new class, Pistol, that derives from Weapon.
			Pistol should have fields with getters/setters for rounds and magCapacity.
			Add a constructor that calls the base constructor

	*/
	//Weapon wpn(5, 10);
	Pistol pewpew(10,50,5,10);
	Pistol johnWickSpecial(100,500,30,INT_MAX);
	johnWickSpecial = johnWickSpecial + pewpew;
	
	std::vector<int> numbers;
	//numbers.size;



	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
		╔═════════════════════════════╗
		║  COMPILE-TIME Polymorphism  ║
		╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
		╔════════════════════════╗
		║  RUNTIME Polymorphism  ║
		╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/



}

