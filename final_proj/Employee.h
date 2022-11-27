#pragma once
#include "Person.h"
class Employee : virtual public Person
{
protected:
	int seniority;
public:
	Employee(char* name, long int id, int seniority);
	Employee(const Employee& e);
	virtual ~Employee();
	virtual void print()const;
	virtual const char* Gettype()const { return "Employee"; }
	int Getsenurity() const { return this->seniority; }
	virtual int salary() = 0;// חישוב משכורת לעובד
};