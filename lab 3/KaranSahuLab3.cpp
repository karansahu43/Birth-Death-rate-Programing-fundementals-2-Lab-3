// Author:  Karan Sahu
// Assignment Number: Lab 3
// File Name: KaranSahuLab3.cpp
// Course/Section: COSC 1337 Section 003
// Due Date:  6/28/2018
// Instructor: Bernard Ku
//
// Chapter 7 - Programming Challenge 5, Population
// This program calculates birth and death rates using
// a Population class.
#include <iostream>
#include <iomanip>
#include <string>  
using namespace std;

class Pop
{
  private:
	long population;   // Current population
	int  numBirths,    // Annual number of births
	     numDeaths;    // Annual number of deaths
	string townName;   // Town Name

  public:
	// Constructors
   Pop();                       
   Pop(long, int, int);
   
	// Mutators (i.e. "set" functions)
   void setPopulation(long p);  
   void setBirths(int b);
   void setDeaths(int d);
   void settownName (string s);
   
  	// Accessors
   long getPopulation()         // getPopulation is not required by specs
      { return population; };    
	double getBirthRate() 
      { return double (numBirths) / population; }
	double getDeathRate() 
      { return double (numDeaths) / population; }
    string gettownName()
      { return townName; }
	  
};

/********************************************************
 *                     Pop::Pop                         *
 * Population class default constructor                 *
 ********************************************************/ 
Pop::Pop()
{
	population = 2;
	numBirths  = 0;
	numDeaths  = 0;
}

/********************************************************
 *                      Pop::Pop                        *
 * Population class constructor with 3 parameters       *
 ********************************************************/ 
Pop::Pop(long p, int b, int d)
{
	setPopulation(p);
	setBirths(b);
	setDeaths(d);
}

/********************************************************
 *                Pop::setPopulation                    *
 * Validates and sets the population.                   *
 ********************************************************/ 
void Pop::setPopulation(long p)
{
	if (p >= 2)
		population = p;
	else
		population = 2;       // Default value
}

/********************************************************
 *                    Pop::setBirths                    *
 * Validates and sets the annual number of births.      *
 ********************************************************/ 
void Pop::setBirths(int b)
{
	if (b >= 0)
		numBirths = b;
	else
		numBirths = 0;        // Default value
}

/********************************************************
 *                    Pop::setDeaths                    *
 * Validates and sets the annual number of deaths.      *
 ********************************************************/ 
void Pop::setDeaths(int d)
{
	if (d >= 0)
		numDeaths = d;
	else
		numDeaths = 0;        // Default value
}

/********************************************************
 *                    Pop::settownName                    *
 * Validates and sets the townName.                       *
 ********************************************************/ 
void Pop::settownName(string s)
{
	if (s == "")
		townName = "TownDefault";   // Default value
	else
		townName = s;       
}

bool isLetter(string);

//*********************** main ****************************

int main()
{
	Pop  myTown;             // instantiate one Pop object
	long numPeople;
	int  numBirths,
		 numDeaths;
	bool townNamecondition = true;
	string townName;
	string name[townName.length()];

	// Input, validate, and set values for myTown
	
	
	
	while (townNamecondition)
	{	
		cout << "Enter Name of the town: ";
		getline(cin, townName);
//		for(int i = 0; i < name.length(); i++)
//		{
//			name[i] = 
//		}
		townNamecondition = isLetter(townName);
	}
	
	myTown.settownName (townName);
	
	
	
	
	
	
	cout << "Enter total population: ";
	cin  >> numPeople;
	
	while (numPeople < 1)
	{	cout << "Value must be greater than 0.  Please re-enter: ";
		cin  >> numPeople;
	} 
	
	myTown.setPopulation(numPeople);  

	cout << "Enter annual number of births: ";
	cin  >> numBirths;
	
	while (numBirths < 0)
	{	cout << "Value cannot be negative.  Please re-enter: ";
		cin  >> numBirths;
	} 
	
	myTown.setBirths(numBirths);  
  
	cout << "Enter annual number of deaths: ";
	cin  >> numDeaths;
	
	while (numDeaths < 0)
	{	cout << "Value cannot be negative.  Please re-enter: ";
		cin  >> numDeaths;
	}
	
	myTown.setDeaths(numDeaths);
	

	

	

	// Display statistics for myTown
	cout << "\nPopulation Statistics " << myTown.gettownName() <<  "\n";         
	cout << fixed << showpoint  << setprecision(3);
	cout << "\n\tPopulation:  " << setw(7) << myTown.getPopulation();
	cout << "\n\tBirth Rate:  " << setw(7) << myTown.getBirthRate();
	cout << "\n\tDeath Rate:  " << setw(7) << myTown.getDeathRate() << endl;

	return 0;
}


bool isLetter(string name)
{
	for(int i = 0; i < name.length(); i++)
	{
		char ch = name[i];
		if(ch != ' ' && isalpha(ch) == 0)
		{
			cout << "Player name must be alphabetical characters only!\n";
			return true;
		}

	}
	return false;
}

/* SAMPLE RUN RESULTS
Enter Name of the town: karan5
Player name must be alphabetical characters only!
Enter Name of the town: 5karan
Player name must be alphabetical characters only!
Enter Name of the town: Austin
Enter total population: -10
Value must be greater than 0.  Please re-enter: 0
Value must be greater than 0.  Please re-enter: 100000
Enter annual number of births: 1000
Enter annual number of deaths: -10
Value cannot be negative.  Please re-enter: 0

Population Statistics Austin

        Population:   100000
        Birth Rate:    0.010
        Death Rate:    0.000
*/
