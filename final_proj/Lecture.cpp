#define _CRT_SECURE_NO_WARNINGS
#include "Lecture.h"
#include <iostream>
#include <string> 
using namespace std;
Lecture::Lecture(char* name, long id, int seniority, int courses_count) :Person(name,id) , Employee(name,id, seniority)
{
	this->courses_count = courses_count;
}

int Lecture::salary()
{
	return 12000 + 500 * courses_count;
}
void Lecture::print()const
{
	cout << "Type: Lecture" << endl;
	cout << "Name: " << name << endl;
	cout << "Id: " << id << endl;
	cout << "Seniority: " << seniority << endl;
	cout << "Number of Courses: " << courses_count << endl;
}