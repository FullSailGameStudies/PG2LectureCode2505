#pragma once
#include <string>
#include <vector>
class Menu
{
public:

	//a method DECLARATION
	void AddMenuItem(std::string itemToAdd);
	void DisplayMenu();

private:
	std::vector<std::string> menuItems;
};

