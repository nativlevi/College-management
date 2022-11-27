#pragma once
#include "Person.h"
#include "Student.h"
#include <iostream>
#include <string.h>
using namespace std;
class BA : public Student
{
protected:
	char* nameofdepartment;
public:

	BA(char* name, long id, float average, int num_of_courses, char* nameofdepartment);
	BA(const BA& b);
	virtual ~BA();
	virtual void print()const;
	virtual const char* Gettype()const { return " BA student"; }
};

