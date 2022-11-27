#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iostream>
#include <string> 
using namespace std;
class Lecture : virtual public Employee
{
protected:
	int courses_count;
public:
	Lecture(char* name ,long id, int seniority, int courses_count);
	virtual const char* get_type()const { return "Lecture"; }
	virtual int salary();
	void print()const;
	virtual ~Lecture() {};
};
