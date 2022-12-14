#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string.h>
#include "BA.h"
#include<string.h>
BA::BA(char* name, long id, float average, int num_of_courses, int days ,char* nameofdepartment) : Person(name,id) ,Student(name, id, average, num_of_courses , days)
{//בנאי עם פרמטרים
	this->nameofdepartment = new char[strlen(nameofdepartment) + 1];
	strcpy(this->nameofdepartment, nameofdepartment);
}
BA::BA(const BA& b) :Person(b), Student(b)
{
	this->nameofdepartment = new char[strlen(b.nameofdepartment) + 1];
	strcpy(this->nameofdepartment, b.nameofdepartment);
}
 void BA::print()const
{
	 cout << "Type:BA Student" << endl;
	 cout << "Name: " << name << endl;
	 cout << "ID: " << id << endl;
	 cout << "Average= " << average << endl;
	 cout << "Number Of Courses: " << num_of_courses << endl;
	 cout << "Missing days this year:" << days << endl;
	 cout << "Name Of Department: " << nameofdepartment << endl;
}
BA::~BA()
{
	delete[] nameofdepartment;
}