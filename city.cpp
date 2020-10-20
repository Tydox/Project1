//
// Created by Daniel Fellous on 10/20/20.
//
#define _CRT_SECURE_NO_WARNINGS
#include "city.h"

namespace pokemon {

	char* cityName::realloc(int newSize, char* str)
	{
		if (str == NULL)
		{
			char* newStr = new char[1]();
			return newStr;
		}
		char* newStr = new char[newSize]();

		int oldSize = strlen(str) + 1;

		if (newSize >= oldSize)
			std::memcpy(newStr, str, oldSize);
		else
			std::memcpy(newStr, str, newSize);

		newStr[newSize - 1] = '\0';
		delete[] str;
		str = nullptr;
		return newStr;
	}



	City* citiesArray::realloc(City* citiesArray, int oldSize, int newSize)
	{
		//do i need to make a thing for every option, newsize is -5 invalid for example
		if (citiesArray == NULL && oldSize == 0 && newSize > 0)
		{
			std::cout << "Cities are empty, Initializing" << std::endl;
			City* newCitiesArray = new City[newSize]();
			delete citiesArray; // check if needed to delete the old cities
			return newCitiesArray;
		}
		if (oldSize == newSize)
		{
			std::cout << "New Size is the same as Old Size" << std::endl;
			return citiesArray;
		}

		City* newCitiesArray = new City[newSize]();

		if (oldSize < newSize) {
			for (int i = 0; i < oldSize; ++i)
			{
				newCitiesArray[i].pokeNum = citiesArray[i].pokeNum;
				newCitiesArray[i].cityName = pokemon::cityName::realloc((strlen(citiesArray[i].cityName) + 1), citiesArray[i].cityName); // removes old pointer
			}
		}
		else
		{
			//DO I NEED TO REALLOC WHEN A SMALLER SIZE OLDNUM > NEWNUM
		}
		return newCitiesArray;
	}






	int findCity(cityMngArray& citiesMng, char* city, bool addCity)
	{
		int i = 0;
		for (; i < citiesMng.citySize; ++i)
		{
			if (strcmp(citiesMng.cityNameArray[i].cityName, city) == 0)
			{
				return i;
			}
		}
		if (addCity == true)
		{
			citiesMng.cityNameArray = citiesArray::realloc(citiesMng.cityNameArray, citiesMng.citySize, citiesMng.citySize + 1);
			return ++i;
		}
		return -1;
	}





	bool IsExist(cityMngArray& citiesArray, char* city)
	{
		return findCity(citiesArray, city, false);
	}

	void free(cityMngArray& citiesArray)
	{
		for (int i = 0; i < citiesArray.citySize; ++i) // delete all the cities name
		{
			delete[] citiesArray.cityNameArray[i].cityName; // NOT SURE IF NEED [] on delete
		}
		delete[] citiesArray.cityNameArray; // delete holder of all city names
	}

	void printCitiesDetails(cityMngArray& citiesArray)
	{
		std::cout << "All City Printer" << std::endl;
		if (citiesArray.citySize == 0)
			std::cout << "The City is a ghost town" << std::endl;
		else
			for (int i = 0; citiesArray.citySize; ++i)
			{
				std::cout << "City's Name: " << citiesArray.cityNameArray[i].cityName << " City's population: " << citiesArray.citySize << std::endl;
			}
	}

}