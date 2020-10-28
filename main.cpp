#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "city.h"

int main()
{
    { using namespace pokemon;
    	
    //init City Manager Array and starter values
    cityMngArray cityManagerArray;
    
    cityManagerArray.citySize = 0;
	cityManagerArray.cityNameArray=nullptr;

    char userInput = '1';
    while (userInput!='6')
    {
        std::cout
    	<< "\n----Project 1 Menu----\n"
    	<< "1. Print Cities details\n"
    	<< "2. Add City\n"
    	<< "3. Is Arithmetic Progression\n"
    	<< "4. Is Geometric\n"
    	<< "5. Remove City\n"
    	<< "6. Exit" << std::endl
    	<< "Option: ";
    	
        std::cin >> userInput;

    	switch (userInput)
        {
        case '1':
        {
            if (isEmpty(cityManagerArray) == false)
            printCitiesDetails(cityManagerArray);

        	break;
        }
        case '2':
        {
        		addCity(cityManagerArray);
            break;
        }
        case '3':
        {
            if (isEmpty(cityManagerArray) == false)
            {
                if (isArithmeticProgression(cityManagerArray))
                    std::cout << "\nis Arithmetic Progression = YES\n";
                else
                    std::cout << "\nis Arithmetic Progression = NO\n";
            }
        		
            break;
        }
        case '4':
        {
            if (isEmpty(cityManagerArray) == false)
            {
                if (isGeometricSeries(cityManagerArray))
                    std::cout << "\nis Geometric Series = YES\n";
                else
                    std::cout << "\nis Geometric Series = NO\n";
            }
            break;
        }
        case '5':
        {
            if (isEmpty(cityManagerArray) == false)
        		removeCity(cityManagerArray);
        		
            break;
        }
        case '6':
        {
            std::cout << "Thank you for using our program!" << std::endl;
            break;
        }
        default:
	        {
		        std::cout << "Invalid Number Input.. Restarting\n";
        		break;
	        } 
        }
    }

 
    }
}