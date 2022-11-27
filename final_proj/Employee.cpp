#include "Employee.h"
#include <string.h>
#include <iostream>
using namespace std;
Employee::Employee(char* name, long int id, int seniority) :Person(name, id)
{//בנאי עם פרמטרים
	this->seniority = seniority;
}
Employee::Employee(const Employee& e) : Person(e)
{//בנאי מעתיק
	this->seniority = e.seniority;
}
void Employee::print()const
{//הדפסה מסודרת של האובייקט
	cout << "Type: Employee " << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Seniority: " << seniority <<endl;
}
Employee ::~Employee()
{//פונקציה הורסת
}