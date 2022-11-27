#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;
class MA : virtual public Student
{
protected:
	char* name_of_teza;
public:
	MA(char* name, long int id, float average, int num_of_courses, char* name_of_teza);
	MA(const MA& m);
	virtual ~MA();
	virtual void print()const;
	virtual const char* Gettype()const { return " MA student"; }
};