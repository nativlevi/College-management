#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Employee.h"
#include <iostream>
using namespace std;
class Secretary : virtual public Employee
{
protected:
	long phone_num;//מספר טלפון של המזכירה
public:
	Secretary(char* name, long id, long seniority, long phone_num);
	virtual ~Secretary();
	virtual int salary();
	virtual void print()const;
};

