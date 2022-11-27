#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include "Employee.h"
#include <iostream>
#include <string> 
using namespace std;
class Cleaner :virtual public Person, virtual public Employee
{
private:
	int work_hours;
public:
	Cleaner(char* name,long id,int seniority , int work_hours);
	virtual void print()const;
	virtual int salary();
	virtual ~Cleaner();
	const char* get_type()const { return "Cleaner"; }
};