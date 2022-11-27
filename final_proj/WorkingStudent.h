#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "MA.h"
#include "Practitioner.h"
#include "Employee.h"
using namespace std;
#include <iostream>
class WorkingStudent : virtual public Person, virtual public Student, virtual public Employee,virtual public MA, virtual public Practitioner
{
public:
	WorkingStudent(char* name, int id, float average, int num_of_courses, char* name_of_teza, int seniority, int weekly_hours);
	WorkingStudent(const WorkingStudent& w);
	virtual ~WorkingStudent();
	virtual const char* get_type()const { return "WorkingStudent"; }
	virtual void print()const;
	virtual int salary();
};

