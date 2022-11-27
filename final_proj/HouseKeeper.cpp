#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include "Employee.h"
#include "HouseKeeper.h"
#include "Person.h"
#include <iostream>
#include <string> 
using namespace std;
HouseKeeper::HouseKeeper(char* name, long id, int seniority, int extra_hours) :Person(name, id), Employee(name, id, seniority)
{
	this->extra_hours = extra_hours;
}

int HouseKeeper::salary()
{
	return 7000 + (50 * extra_hours) + (100 * seniority);
}

void HouseKeeper::print()const
{
	cout << "Type: House Keeper" << endl;
	cout << "Name: " << name << endl;
	cout << "Id: " << id << endl;
	cout << "Seniority: " << seniority << endl;
	cout << "Extra_hours: " << extra_hours << endl;
}