#pragma once
#include "Person.h"
#include <iostream>
#include <string.h>
using namespace std;
class Student : virtual public Person
{
protected:
	float average;//ממוצע ציונים
	int num_of_courses;//מספר הקורסים לכל סטודנט
public:
	Student(char* name, long id, float average, int num_of_courses);
	Student(const Student& s);
	virtual ~Student();
	virtual void print()const;
	const char* get_type()const { return "Student"; }
	virtual float get_average() { return average; }
};