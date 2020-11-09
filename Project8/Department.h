#pragma once
#include<iostream>
#include<string>
#include<time.h>
#include"Worker.h"
#include <conio.h>
#include<fstream>
#include <windows.h>

using namespace std;
struct Department
{	
	int CountWorker;
	Worker* workers;	
	void CreateDepartment();//1
	void PrintDepartment();//2
};

/*void AddWorker(Department* departments, int index); */    //3


void SetColor(int col);
void SetPos(int x, int y);
void Size_Console(int x, int y);
int Menu(string menu_items[], int SIZE);
int MenuDep(Department* departments);
int MainMenu(Department* departments);


//int menuWorker(Worker* workers, int CountWorker);
//void DeleteWorker(Department* departments, int index, int dismiss);//4
//void SortWorkers();            //5
//void FindWorker(Department* departments);//6
//void DepartmentData(Department* departments);//7
//void Average_amount_no_worked_day_depart_per_year(Department* departments);//9
//void Count_no_worked_day_by_month(Department* departments);//10
//void Count_no_worked_day_per_year(Department* departments);//11