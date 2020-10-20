#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "city.h"

int main()
{
    //init City Manager Array and starter values
    cityMngArray* cityManagerArray = new cityMngArray();
    cityManagerArray->cityNameArray = pokemon::citiesArray::realloc(cityManagerArray->cityNameArray, 0, 1);
    cityManagerArray->cityNameArray->cityName = pokemon::cityName::realloc();
    cityManagerArray->citySize = 1;

    //testing region
    char* name = new char[7];
    strcpy(name, "daniel");
    cityManagerArray->cityNameArray->cityName = pokemon::cityName::realloc(4, name);
    std::cout << cityManagerArray->cityNameArray->cityName << std::endl;

    char* name2 = new char[4];
    strcpy(name2, "dan");

    char* name3 = new char[4];
    strcpy(name3, "ta");
    std::cout << "City:" << pokemon::findCity(*cityManagerArray, name2, false) << std::endl;
    std::cout << "City:" << pokemon::findCity(*cityManagerArray, name3, false) << std::endl;
    std::cout << "City:" << pokemon::IsExist(*cityManagerArray, name2) << std::endl;


    int userInput = 1;
    while (userInput < 6 && userInput>0)
    {
        std::cout << "\nProject 1 Menu\n1. Print Cities details\n2. Add City\n3.Is Arithmetic Progression\n4.Is Geometric\n5.Remove City\n6.Exit" << std::endl;
        std::cin >> userInput;
        switch (userInput)
        {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            std::cout << "Thank you for using our program!" << std::endl;
            break;
        }
        //	default: 
        }
    }

    {

        using namespace std;
        char* name = new char[7];

        strcpy(name, "daniel");
        cout << name << endl;
        char* newName = pokemon::cityName::realloc(4, name);

        cout << newName << endl;


        char* newName2 = pokemon::cityName::realloc(7, newName);

        cout << newName2 << endl;
        strcpy(newName2, "lavati");
        cout << newName2;

    }
}