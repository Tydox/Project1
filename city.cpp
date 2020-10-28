#define _CRT_SECURE_NO_WARNINGS
#include "city.h"

namespace pokemon {

	char* cityName::realloc(int newSize, char* str)
	{
		if (str == NULL)
		{
			std::cout << "\nATTENTION!\nInserted Empty String, default init!\n";
			char* newStr = new char[1]();
			return newStr;
		}

		char* newStr = new char[newSize]();

		int oldSize = (int)strlen(str) + 1;

		if (newSize >= oldSize)
			std::memcpy(newStr, str, oldSize);
		else
			std::memcpy(newStr, str, newSize);

		newStr[newSize - 1] = '\0';
		delete[] str;
		str = nullptr;
		return newStr;
	}

	City* citiesMngArray::realloc(City* citiesArray, int oldSize, int newSize)
	{
		if (citiesArray == nullptr || (oldSize == 0 && newSize > 0))
		{
			City* newCitiesArray = new City[newSize]();
			delete citiesArray;
			std::cout << "\nInitialization of Empty City Array - SUCCESS\n";
			return newCitiesArray;
		}
		if (oldSize == newSize)  //CALLING FUNCTION WITH THE SAME CITY SIZE
		{
			std::cout << "New Size is the same as Old Size, nothing to do!" << std::endl;
			return citiesArray;
		}

		City* newCitiesArray = new City[newSize]();

		if (newSize > oldSize) { //INCREASING ARRAY LENGTH
			for (int i = 0; i < oldSize; ++i)
			{
				newCitiesArray[i].pokeNum = citiesArray[i].pokeNum;
				newCitiesArray[i].cityName = pokemon::cityName::realloc((int)(strlen(citiesArray[i].cityName) + 1), citiesArray[i].cityName); // removes old pointer
			}
		}
		else if (oldSize > newSize)//DECREASING ARRAY LENGTH
		{
			for (int i = 0; i < oldSize - 1; ++i)
			{
				newCitiesArray[i].pokeNum = citiesArray[i].pokeNum;
				newCitiesArray[i].cityName = pokemon::cityName::realloc((int)(strlen(citiesArray[i].cityName) + 1), citiesArray[i].cityName); // removes old pointer
			}

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
			citiesMng.cityNameArray = citiesMngArray::realloc(citiesMng.cityNameArray, citiesMng.citySize, citiesMng.citySize + 1);

			return i;
		}
		return -1;
	}

	bool IsExist(cityMngArray& citiesArray, char* city)
	{
		int num = findCity(citiesArray, city, false);
		if (num == -1)
			return false;

		return true;
	}

	void free(cityMngArray& citiesArray)
	{
		for (int i = 0; i < citiesArray.citySize; ++i) // delete all the cities name
		{
			delete[] citiesArray.cityNameArray[i].cityName;
		}
		delete[] citiesArray.cityNameArray; // delete pointer of city array
	}

	void printCitiesDetails(cityMngArray& citiesArray)
	{
		std::cout << "\nAll City Printer\n--------------------\n";

		if (citiesArray.citySize == 0 || citiesArray.cityNameArray == nullptr)
			std::cout << "City Name: Error, non-exist\n";
		else
			for (int i = 0; i < citiesArray.citySize; ++i)
			{
				std::cout
					<< "City's Name: " << citiesArray.cityNameArray[i].cityName << "\n"
					<< "City's pokemons: " << citiesArray.cityNameArray[i].pokeNum << "\n\n";
			}
	}

	void addCity(cityMngArray& citiesArray)
	{
		{
			using namespace std;

			char newName[1000];
			int pokenum = 0;

			cout
				<< "\nCity Adder Manager\n"
				<< "[Please Enter The name of the City You Wish To Add and Pokemons Amount]\n"
				<< "Name: ";

			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.getline(newName, 999);

			cout << "Number of Pokemons: ";
			cin >> pokenum;

			bool cityExist = IsExist(citiesArray, newName);

			int cityIndex = findCity(citiesArray, newName, !cityExist);

			citiesArray.cityNameArray[cityIndex].cityName = new char[strlen(newName) + 1];

			citiesArray.cityNameArray[cityIndex].pokeNum = pokenum;

			if (cityExist == false)
				++citiesArray.citySize;

			memcpy(citiesArray.cityNameArray[cityIndex].cityName, newName, strlen(newName) + 1);

		}
	}

	bool isArithmeticProgression(cityMngArray& citiesArray) //CHECK IF WORKING
	{
		int d = 0;

		//size is too small to be a series
		if (citiesArray.citySize == 0 || citiesArray.citySize == 1)
			return false;

		//init hefresh
		d = (int)(citiesArray.cityNameArray[1].pokeNum - citiesArray.cityNameArray[0].pokeNum);

		for (int i = 1; i < citiesArray.citySize - 1; ++i)
		{
			if ((int)(citiesArray.cityNameArray[i + 1].pokeNum - citiesArray.cityNameArray[i].pokeNum) != d)
				return false;
		}

		return true;
	}

	bool isGeometricSeries(cityMngArray& citiesArray)
	{
		//size is too small to be a series
		if (citiesArray.citySize == 0 || citiesArray.citySize == 1)
			return false;

		int k = 0;

		k = (citiesArray.cityNameArray[1].pokeNum) / (citiesArray.cityNameArray[0].pokeNum);

		for (int i = 2; i < citiesArray.citySize; ++i)
		{
			if ((int)((citiesArray.cityNameArray[i].pokeNum) / (citiesArray.cityNameArray[i - 1].pokeNum)) != k)
				return false;
		}

		return true;
	}

	void removeCity(cityMngArray& citiesArray)
	{
		if (citiesArray.citySize == 0)
		{
			std::cout << "NO CITIES IN ARRAY,\nPLEASE ADD SOME BEFORE TRYING TO DELETE\n";
			return;
		}

		{
			using namespace std;

			char remName[1000] = "\0";

			while (1)
			{

				cout << "\nEnter City's Name to remove: ";
				fseek(stdin, 0, SEEK_END);

				cin.clear();
				cin.getline(remName, 999);

				//index of DELETE city
				int nameIndex = findCity(citiesArray, remName, false);

				if (nameIndex == -1)
				{
					cout << "Name not found, try again!";
					continue;
				}

				//size of last city NAME
				int tmpSize = (int)strlen(citiesArray.cityNameArray[citiesArray.citySize - 1].cityName) + 1;

				//replacing deleted name
				char* newCity = new char[tmpSize];
				memcpy(newCity, citiesArray.cityNameArray[citiesArray.citySize - 1].cityName, tmpSize);
				delete citiesArray.cityNameArray[nameIndex].cityName;
				citiesArray.cityNameArray[nameIndex].cityName = newCity;

				//copy pokenum
				citiesArray.cityNameArray[nameIndex].pokeNum = citiesArray.cityNameArray[citiesArray.citySize - 1].pokeNum;

				//RESIZE ARRAY SIZE -1
				citiesArray.cityNameArray = citiesMngArray::realloc(citiesArray.cityNameArray, citiesArray.citySize, citiesArray.citySize - 1);

				//ARRAY SIZE -1
				--citiesArray.citySize;

				break;
			}
		}
	}

	bool isEmpty(cityMngArray& citiesArray)
	{
		int num = citiesArray.citySize;
		if(num==0)
		{
			std::cout << "No Cities For Now\n";
			return true;
		}
		return false;
	}
	
}
