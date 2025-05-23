﻿// Day06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <Console.h>
#include <Input.h>


enum class Weapon
{
	Sword, Axe, Spear, Mace
};

void PrintGrades(const std::map<std::string, double>& grades)
{
	Console::WriteLine("\nPG2 2505", ConsoleColor::Green);
	for (auto& [studentName, studentGrade] : grades)
	{
		std::cout << std::left << std::setw(10) << studentName << " ";
		std::cout << std::right << std::setw(8) << studentGrade << "\n";
	}
}

int main()
{

	/*
		╔═══════════════════╗
		║ map<TKey, TValue> ║
		╚═══════════════════╝

		[  Removing a key and its value from a map  ]

		erase(iterator) -- returns an iterator that points to the first item AFTER the ones that were removed OR end() if no element exist
		erase(key) -- returns the # of items removed

	*/
	std::map<Weapon, int> backpack;
	auto inserted = backpack.insert(std::make_pair(Weapon::Sword, 5));
	backpack[Weapon::Axe] = 3;

	size_t numberRemoved = backpack.erase(Weapon::Sword);
	if (numberRemoved > 0)
		std::cout << "The Swords were removed.\n";
	else
		std::cout << "Sword was not found in the map.\n";

	std::map<Weapon, int>::iterator found = backpack.find(Weapon::Axe);
	if (found != backpack.end())
	{
		backpack.erase(found);
		std::cout << "The Axes were removed.\n";
	}
	else
		std::cout << "Axe was not found in the map.\n";





	/*
		CHALLENGE 1:

					print the students and grades below
						use std::setw and std::left and std::right to format the output
					ask for the name of the student to drop from the grades map
						use std::getline to get the user's input
					remove the student from the map
					print message indicating what happened
					if not found print an error message
					else print the map again and print that the student was removed
	*/
	srand((unsigned int)time(NULL));
	std::map<std::string, double> grades;
	grades["Bruce"] = rand() % 101;
	grades["Dick"] = rand() % 101;
	grades["Diana"] = rand() % 101;
	grades["Alfred"] = rand() % 101;
	grades["Clark"] = rand() % 101;
	grades["Arthur"] = rand() % 101;
	grades["Barry"] = rand() % 101;

	do
	{
		PrintGrades(grades);
		std::string student = Input::GetString("Student to drop? ");
		if (student.empty()) break;
		auto isFound = grades.find(student);
		if (isFound == grades.end())
			std::cout << student << " was not in the course this month.\n";
		else
		{
			std::cout << student << " had a grade of " << isFound->second << ". Dropping...";
			grades.erase(isFound);
			std::cout << "DONE!\n";
		}

	} while (true);
}