#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
using namespace std;
#include <string.h>
#include "Person.h"
#include "Student.h"
#include "BA.h"
#include "MA.h"
#include "Practitioner.h"
#include "WorkingStudent.h"
#include "HouseKeeper.h"
#include "Secretary.h"
#include "Lecture.h"
#include "Cleaner.h"
class Data
{
private:
	Person** arr;
	int size;
public:
	Data();
	~Data();
	void init();
	void operator+=(Person* p);
	void print_all()const;
	bool find(int long id);
	void operator-=(long id);
	void search(long id);
};