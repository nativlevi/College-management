#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <string.h>
using namespace std;
class Person
{
protected:
	char* name;
	long id;
	static int total_person;
public:
	Person(char* name, long  id);
	Person(const Person& p);
	virtual void print()const;
	virtual ~Person();
	virtual const char* get_type()const { return "Person"; }
	long get_id() { return id; }
	virtual char* get_name() { return name; }
	static void print_static();
};