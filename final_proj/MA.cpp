#define _CRT_SECURE_NO_WARNINGS
#include "MA.h"
#include<string.h>
#include <iostream>
using namespace std;
MA::MA(char* name, long int id, float average, int num_of_courses, char* name_of_teza) :Person(name, id), Student(name, id, average, num_of_courses)
{
	this->name_of_teza = new char[strlen(name_of_teza) + 1];
	strcpy(this->name_of_teza, name_of_teza);
}
MA::MA(const MA& m) : Person(m), Student(m)
{
	this->name_of_teza = new char[strlen(m.name_of_teza) + 1];
	strcpy(this->name_of_teza, m.name_of_teza);
}
void MA::print()const
{
	cout << "Type: MA student" << endl;
	cout << "Name: " << name << endl;
	cout << "Id: " << id << endl;
	cout << "Average: " << average << endl;
	cout << "Number of courses: " << num_of_courses << endl;
	cout << "Name of teza: " << name_of_teza << endl;
}
MA ::~MA()
{
	delete[] name_of_teza;
}