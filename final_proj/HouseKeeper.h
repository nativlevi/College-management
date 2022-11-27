#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Person.h"
#include "Employee.h"
#include <iostream>
#include <string> 
using namespace std;
class HouseKeeper :virtual public Person,virtual public Employee
{
private:
	int extra_hours;
public:

	HouseKeeper(char* name, long id , int seniority, int extra_hours);
	virtual const char* get_type()const { return "HouseKeeper"; }
	virtual int salary();
	virtual void print()const;
	virtual ~HouseKeeper() {};
};

