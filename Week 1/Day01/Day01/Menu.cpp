#include "Menu.h"
#include <iostream>
#include <Console.h>

//a method DEFINITION
void Menu::AddMenuItem(std::string itemToAdd)
{
	menuItems.push_back(itemToAdd);
}

void Menu::DisplayMenu()
{
	for (int i = 0; i < menuItems.size(); i++)
	{
		//vector[index]
		std::string item = menuItems[i];
		std::cout << item << "\n";
		//OR...
		Console::WriteLine(menuItems[i].size());
	}
	//range-based for loop
	//& - reference variable
	std::cout << "Range-Based for loop\n";
	for (std::string& menuItem : menuItems)
	{
		Console::WriteLine(menuItem);
	}
	//iterator loop
	//an iterator: object that knows how to move through thte collection
	//vector.begin() - gives an iterator to the first item
	//vector.end() - gives an iterator to the item AFTER the last item?????
	//first index: 0
	//last index: size()-1
	for (std::vector<std::string>::iterator i = menuItems.begin(); i != menuItems.end(); i++)
	{
		std::string item = *i;
		Console::WriteLine(item);
	}

	//erase the last item
	int index = 3;
	menuItems.erase(menuItems.begin() + index);
}

