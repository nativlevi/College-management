#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Employee.h"
#include <iostream>
using namespace std;
class Practitioner :virtual public Employee //מתרגל
{
protected:
	int weekly_hours;
public:
	Practitioner(char* name, long id, int weekly_hours, int seniority );
	virtual ~Practitioner();
	virtual int salary();
	virtual void print()const;
};
