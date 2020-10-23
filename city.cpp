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
		//do i need to make a thing for every option, newsize is -5 invalid for example
		if (citiesArray == nullptr || (oldSize == 0 && newSize > 0))
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
				newCitiesArray[i].cityName = pokemon::cityName::realloc((int)(strlen(citiesArray[i].cityName) + 1), citiesArray[i].cityName); // removes old pointer
			}
		}
		else if(oldSize >= newSize)
		{
			for (int i = 0; i < oldSize-1; ++i)
			{
				newCitiesArray[i].pokeNum = citiesArray[i].pokeNum;
				newCitiesArray[i].cityName = pokemon::cityName::realloc((int)(strlen(citiesArray[i].cityName) + 1), citiesArray[i].cityName); // removes old pointer
			}
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
			citiesMng.cityNameArray = citiesMngArray::realloc(citiesMng.cityNameArray, citiesMng.citySize, citiesMng.citySize + 1);

			return i;
		}
		return -1;
	}





	bool IsExist(cityMngArray& citiesArray, char* city)
	{
		int num = findCity(citiesArray, city, false);
		if (num==-1)
			return false;
		
		return true; 
	}

	void free(cityMngArray& citiesArray) //CHECK IF WORKS
	{
		for (int i = 0; i < citiesArray.citySize; ++i) // delete all the cities name
		{
			delete citiesArray.cityNameArray[i].cityName; // NOT SURE IF NEED [] on delete
		}
		delete[] citiesArray.cityNameArray; // delete holder of all city names
	}

	void printCitiesDetails(cityMngArray& citiesArray) //CHECK IF WORKS
	{
		std::cout << "\nAll City Printer\n";
	
		if (citiesArray.citySize == 0 || citiesArray.cityNameArray == nullptr)
			std::cout << "The City is a ghost town\n";
		else
			for (int i = 0; i<citiesArray.citySize; ++i)
			{
				std::cout
				<< "City's Name: " << citiesArray.cityNameArray[i].cityName << "\n"
				<< "City's pokemons: " << citiesArray.cityNameArray[i].pokeNum << "\n\n"; // WILL PROBLEMS
			}
	}

	void addCity(cityMngArray& citiesArray) //CHECK IF WORKS
	{
		{
			using namespace std;

			char newName[1000];
			int pokenum=0;

			cout
			<<"\nCity Adder Manager\n"
			<< "[Please Enter The name of the City You Wish To Add and Pokemons Amount]\n"
			<< "Name: ";

			
			cin.ignore(numeric_limits<streamsize>::max(),'\n');			

			cin.getline(newName,999);

		

			cout <<"Number of Pokemons: ";
			
			cin >> pokenum;

			bool cityExist = IsExist(citiesArray,newName);

			int cityIndex = findCity(citiesArray,newName,!cityExist);

			citiesArray.cityNameArray[cityIndex].cityName = new char[strlen(newName)+1];
			
			citiesArray.cityNameArray[cityIndex].pokeNum=pokenum;

			if(cityExist==false)
			++citiesArray.citySize;

			memcpy(citiesArray.cityNameArray[cityIndex].cityName,newName,strlen(newName)+1);
			
			
			
		//	std::cout << "\nCity was added successfully\n";
			
			
		}
			
	}

	bool isArithmeticProgression(cityMngArray& citiesArray) //CHECK IF WORKING
	{
		 int d=0;
		//bool aP=true;

		//size is too small to be a series
		if(citiesArray.citySize==0 || citiesArray.citySize==1)
			return false;

		//init hefresh
		d = (int)(citiesArray.cityNameArray[1].pokeNum-citiesArray.cityNameArray[0].pokeNum);
	
		
		for(int i=1; i<citiesArray.citySize-1;++i)
		{
			//if(citiesArray.cityNameArray[i+1].pokeNum == NULL) //stop 1 step before so you don't comp last with junk
			//	break;

			if((int)(citiesArray.cityNameArray[i+1].pokeNum-citiesArray.cityNameArray[i].pokeNum) != d)
			return false;
			
		}
		
		return true;
	}

	bool isGeometricSeries(cityMngArray& citiesArray)
	{
		//size is too small to be a series
		if(citiesArray.citySize==0 || citiesArray.citySize==1)
			return false;

		int k=0;

		k = (citiesArray.cityNameArray[1].pokeNum)/(citiesArray.cityNameArray[0].pokeNum);

		
		for(int i=2; i<citiesArray.citySize;++i)
		{
			if((int)((citiesArray.cityNameArray[i].pokeNum)/(citiesArray.cityNameArray[i-1].pokeNum)) != k)
			return false;		
		}
		
		return true;
	}

	void removeCity(cityMngArray& citiesArray)
	{

		{
			using namespace std;

			//char* remName = new char[1000](); //CHECK IF U CAN REALOC SIZE
			char remName[1000];
			
			while(1)
			{
			//ALDJASKDJALSKJDSLDJALKSJDASLDK
			cout << "\nEnter City's Name to remove: ";

				cin.ignore(numeric_limits<streamsize>::max(),'\n');			
				cin.getline(remName,999);

			//index of DELETE city
			int nameIndex = findCity(citiesArray,remName,false);
			if(nameIndex==-1)
			{
				cout << "Name not found" << std::endl;
				continue;
			}
				

			//size of last city NAME
			int tmpSize = (int)strlen(citiesArray.cityNameArray[citiesArray.citySize-1].cityName)+1;


				
			char* newCity = new char[tmpSize];
			memcpy(newCity,citiesArray.cityNameArray[citiesArray.citySize-1].cityName,tmpSize);
				delete citiesArray.cityNameArray[nameIndex].cityName;
				citiesArray.cityNameArray[nameIndex].cityName=newCity;

				
			//RAPE NAME
			//citiesArray.cityNameArray[nameIndex].cityName = cityName::realloc(tmpSize,citiesArray.cityNameArray[nameIndex].cityName);
			//RAPE POKE nUM
			citiesArray.cityNameArray[nameIndex].pokeNum = citiesArray.cityNameArray[citiesArray.citySize-1].pokeNum;

			//DELETE
			citiesArray.cityNameArray=citiesMngArray::realloc(citiesArray.cityNameArray,citiesArray.citySize,citiesArray.citySize-1);

				--citiesArray.citySize;
				 

				break;
			}


			
		}

		
	}






	
}