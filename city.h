//
// Created by Daniel Fellous on 10/20/20.
//
#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <cstring>
#include <string>


#define _CRT_SECURE_NO_WARNINGS

typedef struct city
{
	char* cityName;
	unsigned int pokeNum;
} City;

typedef struct cityMngArray
{
	City* cityNameArray;
	int citySize;
}CityMngArray;

namespace pokemon
{
	namespace cityName
	{
		char* realloc(int newSize = 1, char* str = NULL);
	}

	namespace citiesArray
	{
		City* realloc(City* citiesArray, int oldSize = 0, int newSize = 1);
	}

	int findCity(cityMngArray& citiesMng, char* city, bool addCity = false);

	bool IsExist(cityMngArray& citiesArray, char* city);

	void free(cityMngArray& citiesArray);

	void printCitiesDetails(cityMngArray& citiesArray);



}


#endif //CITY_H