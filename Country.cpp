//File: Country.cpp
//Author: Kyle Shake
//Date: 11/4/16
//Purpose: Provide implementation of the member functions of class Country


#include "Country.h"
#include "SortingList.h"
#include <cassert>

using namespace std;

    Country::Country()
    {
	name = "";
	population = 0;
        area = 0;
    }

    Country::Country(string n, long p, double a)
    {
	name = n;
	population = p;
        area = a;
    }

    string Country::get_name() const { return name; }

    long Country::get_population() const { return population; }

    double Country::get_area() const { return area; }

    int Country::compareByName(Country C1, Country C2)
    {
	if (C1.name > C2.name)	return 1;
	else 	return -1;
    }

    int Country::compareByPopulation(Country C1, Country C2)
    {
	if (C1.population > C2.population) return 1;
	else return -1;
    }

    ostream &operator<<(ostream &out, const Country &C) 
    {
	return(cout << C.name << "    (" << C.population << " : " << C.area << ")\n");
    }


