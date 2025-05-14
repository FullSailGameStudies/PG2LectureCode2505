// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

int LinearSearch(const std::vector<int>& searchVector, int searchNumber)
{
    int foundIndex = -1;//NOT FOUND
    for (int i = 0; i < searchVector.size(); i++)
    {
        if (searchNumber == searchVector[i])
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    //N = size, O(N)
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int index = LinearSearch(numbers, searchNumber);
    if (index == -1)
        std::cout << searchNumber << " not found.\n";
    else
        std::cout << searchNumber << " found at index " << index << "\n";




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map



    // "eggs" 4.99
    std::map<std::string,float> menu;
    //To add to a map...
    //1) map[key] = value;
    menu["coffee"] = 1.99f;
    menu["sausage mcmuffin"] = 4.99f;
    menu["mcGriddle"] = 5.99f;
    menu["mcGriddle"] = 7.99f;//overwrites the old value

    //2) map.insert(pairObject)
    //stores data as a key-value pair object
    auto pairToInsert = std::make_pair<std::string, float>("mcGriddle", 3.99f);

    std::pair<std::map<std::string,float>::iterator,bool> insertedItem = 
        menu.insert(pairToInsert); //does NOT overwrite an existing value
    //first is the ITERATOR to the item in the map

    //pairs have 2 parts: first, second
    if (insertedItem.second) //pair was inserted
    {
        std::cout << pairToInsert.first << " was inserted.\n";
    }
    else
    {
        std::cout << pairToInsert.first << " was already on the menu.\n";
    }

    //range-based loop
    std::cout << "\n\nrange-based loop\n";
    for (auto& item : menu)
    {
        //first is the key (item name)
        //second is the value (item price)
        std::cout << item.first << " " << item.second << "\n";
    }
    std::cout << "\n\nmodern range-based loop\n";
    for (const auto& [itemName,itemPrice] : menu)
    {
        //itemPrice += 5;
        std::cout << itemName << " " << itemPrice << "\n";
    }

    std::cout << "\n\nIterator for-loop\n";
    for (auto iter = menu.begin(); iter != menu.end(); iter++)
    {
        std::cout << iter->first << " " << (*iter).second << "\n";
    }

    std::cout << "\n\nIterator while-loop\n";
    auto whileIter = menu.begin();
    while (whileIter != menu.end())
    {
        std::cout << whileIter->first << " " << (*whileIter).second << "\n";
        whileIter++;
    }


    //find coffee on the menu
    //find(key). returns an iterator.
    std::string itemToFind = "coffee";
    auto foundMenuItem = menu.find(itemToFind);
    if (foundMenuItem != menu.end())
    {
        //menu[foundMenuItem->first] = foundMenuItem->second * 1.10;
        float oldPrice = foundMenuItem->second;
        foundMenuItem->second *= 1.10;
        std::cout << "Coffee used to costs " << oldPrice << "\n";
        std::cout << "Coffee now costs " << foundMenuItem->second << "! Thanks PUTIN!!\n";
    }
    else
        std::cout << "Coffee is not on the menu. WHAAAAT?!\n";

    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    std::map<std::string, double> grades;

    std::vector<std::string> students{
        "Garrett", "Emrys", "Vincent", "Jakob", "Vintey", "Aaden", "Corey", "June",
        "Aaron", "Asher", "Edwin", "Jacob", "James", "Jesse", "Mathurin", "Melissa",
        "Mykell", "Tom", "Wiley"
    };
    srand(time(NULL));
    for (auto& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }

    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */
    std::cout << "\n\nPG2 2505\n";
    for (auto& [student,grade] : grades)
    {
        Console::SetForegroundColor(
            (grade < 59.5) ? ConsoleColor::Red :
            (grade < 69.5) ? ConsoleColor::Yellow :
            (grade < 79.5) ? ConsoleColor::Magenta :
            (grade < 89.5) ? ConsoleColor::Blue :
            ConsoleColor::Green);
        std::cout << std::right << std::setw(8) << grade;
        Console::Reset();
        std::cout << std::left << "  " << student << "\n";
    }

    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}