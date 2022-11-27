#define _CRT_SECURE_NO_WARNINGS
#include "Cleaner.h"
#include "Student.h"
#include "Employee.h"
#include <iostream>
#include <string> 
using namespace std;
Cleaner::Cleaner(char* name, long id, int seniority, int work_hours) :Person(name,id) , Employee(name,id, seniority)
{
	this->work_hours = work_hours;
}
void Cleaner::print()const
{
	cout << "Type: Cleaner " << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Seniority: " << seniority << endl;
	cout << "Work Hours: " << work_hours << endl;
}
Cleaner::~Cleaner()
{
}
int Cleaner::salary()
{
	return 60 * work_hours;
}