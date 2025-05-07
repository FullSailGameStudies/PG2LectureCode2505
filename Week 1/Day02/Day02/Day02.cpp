#include <iostream>
#include <string>
#include <vector>
#include <Console.h>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //size() - # of items that are IN the vector
    //capacity() - size of its internal array
    //size() <= capacity()
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}
//pass by reference:
//  prevents a copy
//  allows access to variables in a different scope
//  better performance
void Adder(int& num, int delta)//pass by reference
{
    std::cout << "\n" << &num << "\n";
    num = num + delta;
}

//when to use pass by reference...
//- if it is a class, pass by reference
//  especially if it is a container of other objects!!
//- or, when you need to change the parameter
void PrintNames(const std::vector<std::string>& names)
{
    //names[0][0] = 'c';// = "Steev!";
    for (auto& name : names)
    {
        std::cout << name << "\n";
    }
}

void FillerGrades(std::vector<float>& course)
{
    //add 10 grades to the course variable
    for (int i = 0; i < 10; i++)
    {
        course.push_back(rand() % 10001 / 100.0F);
    }

}

int main()
{
    FullSailCourse pg2;
    pg2.SetName("PG2 2505");

    //a reference variable
    int num1 = 5;
    int& numRef = num1;//num REFERS to num1 (another name for num1)
    numRef = 10;
    std::cout << num1;
    std::cout << "\n" << & num1 << "\n";
    Adder(num1, 5);//int& num = num1;
    int bats = 10;
    Adder(bats, 10);//int& num = bats;
    //Adder(15);
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of 
            floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector
            3) call the method
            4) print the vector after calling the method

    */
    std::vector<float> grades;
    FillerGrades(grades);
    Console::WriteLine("\nPG2 2505", ConsoleColor::Green);
    for (int i = 0; i < grades.size(); i++)
    {
        //if (grades[i] < 59.5) Console::SetForegroundColor(ConsoleColor::Red);
        //else if(grades[i] < 69.5) Console::SetForegroundColor(ConsoleColor::Yellow);
        //else if(grades[i] < 79.5) Console::SetForegroundColor(ConsoleColor::Blue);
        //else if(grades[i] < 89.5) Console::SetForegroundColor(ConsoleColor::White);
        //else  Console::SetForegroundColor(ConsoleColor::Green);
        Console::WriteLine(grades[i], 
            //ternary operator  (condition) ? true block : false block
            (grades[i] < 59.5) ? ConsoleColor::Red :
            (grades[i] < 69.5) ? ConsoleColor::Yellow :
            (grades[i] < 79.5) ? ConsoleColor::Blue :
            (grades[i] < 89.5) ? ConsoleColor::White :
            ConsoleColor::Green
        
        );
    }
    Console::Reset();
    std::cout << "\n\n\n";

    const int five = 5;
    



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    // vectors: only allowed to acces indexes < size
    std::vector<int> highScores;
    highScores.reserve(10);
    //int hScore = highScores[5];
    printInfo(highScores);//size: ?  capacity: ?
    for (int i = 0; i < 15; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500
    for (int i = 0; i < highScores.size(); i++)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
            i--;
        }
    }
    //OR...
    for (int i = 0; i < highScores.size(); )
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
        else i++;//only increment when we don't erase
    }
    //OR...
    for (int i = highScores.size() - 1; i >= 0; i--)
    {
        if (highScores[i] < 2500)
        {
            highScores.erase(highScores.begin() + i);
        }
    }
    //OR...
    for (auto i = highScores.begin(); i != highScores.end(); )
    {
        if (*i < 2500)
        {
            i = highScores.erase(i);
        }
        else ++i;
    }


    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}