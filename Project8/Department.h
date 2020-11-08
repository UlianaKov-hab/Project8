#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include"Worker.h"
using namespace std;
struct Department
{
	
	
	int CountWorker;
	Worker* workers;	
	void CreateDepartment();
	void PrintDepartment();
	void AddWorker();
	void DeleteWorker(int dismiss);
	void FindWorker(Department* departments);
	void DepartmentData(Department* departments);
	void Average_amount_no_worked_day_depart_per_year(Department* departments);
	void Count_no_worked_day_by_month(Department* departments);

};
