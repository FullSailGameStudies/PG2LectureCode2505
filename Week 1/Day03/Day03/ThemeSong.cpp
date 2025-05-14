#include "ThemeSong.h"
#include "../../../Shared/Console/Console.h"

//definition
void ThemeSong::batTheme(int naCount)
{
	for (int i = 0; i < naCount; i++)
	{
		Console::Write("na ", (ConsoleColor)(rand() % 7 + 1));
	}
	Console::WriteLine("BATMAN!!!", (ConsoleColor)(rand() % 7 + 1));
}