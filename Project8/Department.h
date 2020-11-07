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

};
