// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Pistol.h"
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


//non-static data members: object level data (ex: year)
//static data members: class level data (shared across all objects)
class Car
{
public:
	Car(int year)//ctor
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	// static methods DO NOT have a 'this' parameter
	//   static methods can ONLY access other static members
	static void reporting()
	{
		//this->vehicleInfo();
		//std::cout << "Model Year: " << mModelYear << "\n";
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods have a "hidden" parameter
	//  Car* this
	//non-static methods can access BOTH non-static and static members
	void vehicleInfo() 
	{
		std::cout << "Model Year: " << mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;


int* Print(int i)//created on the stack
{
	int n = 10;//created on the stack
	std::cout << i << "\t" << n << "\n";
	return &n;
}//i and n are REMOVED from the stack when the method finishes

int* CreateHeapMemory()
{
	// every time you use 'new', you must have a corresponding
	// 'delete'
	// IF you do not, you have a memory leak!!!
	int* nPtr = new int(5);
	return nPtr;
}

int main()
{
	//while (true)
	//{
	//	int* numberPtr = CreateHeapMemory();
	//	delete numberPtr;
	//}

	int* ptr = Print(10);
	//* on the RIGHT side means DEREFERENCE
	std::cout << *ptr << "\n";


	int num = 5;
	//& on the LEFT side means reference
	// int& numRef = 
	//& on the RIGHT side means address-of
	//int* numPtr = &num
	std::cout << &num << "\n";
	//num stores 5
	//numPtr stores the memory address to num
	int* numPtr = &num;

	Car gsRide(2010);
	Car* gPtr = new Car(2010);
	gPtr->vehicleInfo();
	delete gPtr;
	{
		//when a unique_ptr goes out of scope, it will delete the memory
		std::unique_ptr<Car> carPtr = std::make_unique<Car>(2010);
		(*carPtr).vehicleInfo();
		carPtr->vehicleInfo();
	}//the memory is automatically cleaned up

	int otherN = 5;
	float fNum = otherN;//IMPLICIT cast
	otherN = (int)fNum;//EXPLICIT cast
	Pistol bang(50, 100, 10, 5);
	Weapon wpn = bang;//what happens??
	//copy the weapon parts of bang to wpn
	//they are separate objects
	Weapon* wpnPtr = &bang;//what happens??
	//UPCAST. cast from a DERIVED type to a BASE type
	//stores the memory location of bang into wpnPtr

	std::vector<std::unique_ptr<Weapon>> dorasBackpack;
	dorasBackpack.push_back(std::make_unique<Pistol>(1000,1000,1,1));
	dorasBackpack.push_back(std::make_unique<Knife>(3,6,15));

	std::cout << "\nDora's Backpack\n";
	for (auto& wpnItem : dorasBackpack)
	{
		wpnItem->showMe();
		std::cout << "\n";
	}
	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
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

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}