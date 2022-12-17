#define _CRT_SECURE_NO_WARNINGS
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
#include "Data.h"
int Person::total_person = 0;
int main()
{
	Data data;
	int choose = 1;
	int op;
	char name[30];
	char phone[11];
	char massage[700];
	char* save_massage = NULL;
	long id;
	cout << "Hello! welcome to SCE" << endl;
	cout << "plesee choose: " << endl;
	while (choose != 0)
	{
		cout << "1-update person" << endl;
		cout << "2-remove person" << endl;
		cout << "3-find person" << endl;
		cout << "4-print all person" << endl;
		cout << "5-send a massage" << endl;
		cout << "0- exit" << endl;
		cin >> choose;
		switch (choose)
		{
		case 0:
			cout << "GOOD-BYE ! " << endl;
			break;
		case 1:
			data.init();
			break;
		case 2:
			cout << "Please enter id to remove object: " << endl;
			cin >> id;
			data.operator-=(id);
			break;
		case 3:
			cout << "Please enter id to find its details: " << endl;
			cin >> id;
			data.search(id);
			if(data.search(id)==false)
				{cout<<"we are not found this id"<<endl<< "may you want to add this id?"<<endl<<"1-yes"<<endl<<"2-no"<<endl;
				 cin>>op;
				 if(op==1)
				 	{data.init();}
				 if(op==2)
				 	{cout<<"please leave details and we will get back to you soon"<<endl; cout<< "enter your name"<<endl; cin>>name;  cout<< "enter your phone"<<endl; cin>>phone;}
				}
			break;
		case 4:
			data.print_all();
			break;
		case 5:	
			cout << "Please enter the massage: " << endl;
			cin >> massage;
			save_massage = new char[strlen(massage+1)];
			if (save_massage == NULL)
			{
				return 0;
			}
			strcpy(save_massage, massage);
			cout << save_massage << endl;
			break;
		default:
			cout << "Wrong Input! Please chose again: " << endl;
			break;
		}
	}
	return 0;
}
