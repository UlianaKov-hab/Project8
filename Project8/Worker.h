#pragma once
#include<iostream>
#include<string>
#include<time.h>
using namespace std;
struct Worker
{
	string FirstName;
	string LastName;
	string Position;
	int PersonalNumber;
	int NumberHoursWorked[12];
	int NumberDaysWorked[12];
	
	void CreateWorker();
	void PrintWorker();


};
