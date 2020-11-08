#include "Department.h"

void Department::CreateDepartment() //1
{
	CountWorker = 1 + rand() % 5;
	workers = new Worker[CountWorker];
	for (int i = 0; i < CountWorker; i++)
	{
		 workers[i].CreateWorker();
	}
	
}

void Department::PrintDepartment() //2
{	
	for (int i = 0; i < CountWorker; i++)
	{
		workers[i].PrintWorker();
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}

void Department::AddWorker() //3
{
	Worker* workers1 = new Worker[CountWorker+1];
	for (int i = 0; i < CountWorker; i++)
	{
		workers1[i]=workers[i];
	}
	workers1[CountWorker].CreateWorker();
	delete[] workers;
	CountWorker++;
	workers = workers1;
}

void Department::DeleteWorker(int dismiss) //4
{
	Worker* workers1 = new Worker[CountWorker - 1];
	for (int i = 0; i < CountWorker; i++)
	{
		if (dismiss != workers->PersonalNumber)
		{
			workers1[i] = workers[i];
		}
		else
		{
			workers1[i] = workers[i+1];
		}
		
	}
	delete[] workers;
	CountWorker--;
}

void Department::FindWorker(Department* departments) //6
{
	string FirstNameFind;
	string LastNameFind;
	int PersonalNumberFind;

	cout << "Enter information about the worker to search:"<<endl;
	cout << "First name: ";
	cin >> FirstNameFind;	
	cout << "Last name: ";
	cin >> LastNameFind;	
	cout << "Personal number: ";
	cin >> PersonalNumberFind;	

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < CountWorker; j++)
		{
			if (departments[i].workers[j].PersonalNumber == PersonalNumberFind)
			{
				departments[i].workers[j].PrintWorker();
			}			
		}
	}
	
	//FirstNameFind == workers->FirstName /*&& LastNameFind == workers->LastName && PersonalNumberFind == workers->PersonalNumber*/
}

void Department::DepartmentData(Department* departments) //7
{
	int count_worked_hours = 0;
	int number;
	int month;
	cout << "Enter number of department";
	cin >> number;
	cout << "Enter number of month";
	cin >> month;
	for (int i = 0; i < 5; i++)
	{
		if (i != (number-1))
		{
			continue;
		}
		else
		{
			for (int j = 0; j < CountWorker; j++)
			{
				for (int m = 0; m < 12; m++)
				{					
					count_worked_hours += departments[number-1].workers[j].NumberHoursWorked[month - 1];
				}
			}
		}
	}
	cout << "Department " << number << endl;
	cout << "Number of hours worked in "<< month<<" months: " << count_worked_hours << endl;	
}

void Department::Average_amount_no_worked_day_depart_per_year(Department* departments) //9
{
	int nembe_department;
	float sum;
	float average_amount_no_worked_day_depart[5];
	for (int i = 0; i < 5; i++)
	{
		sum = 0;
		for (int j = 0; j < CountWorker; j++)
		{
			for (int m = 0; m < 12; m++)
			{
				sum+= departments[i].workers[j].NumberDaysNoWorked[m];
			}
		}
		average_amount_no_worked_day_depart[i] = sum/ CountWorker/12;
	}
	cout << "Enter number of department: ";
	cin >> nembe_department;
	cout << "Average amount no worked day in department " << nembe_department << " per year: " << average_amount_no_worked_day_depart[nembe_department - 1];
}

void Department::Count_no_worked_day_by_month(Department* departments) //10
{
	int no_worked_day_by_month[5][12];
	int sum;
	for (int i = 0; i < 5; i++)
	{		
		sum = 0;
		for (int m = 0; m < 12; m++)
		{
			sum;
			for (int j = 0; j < CountWorker; j++)
			{
				sum+= departments[i].workers[j].NumberDaysNoWorked[m];
			}
			no_worked_day_by_month[i][m] = sum;
		}			
	}
	cout << "Number no worked days per mohths";
	
	for (int i = 0; i < 5; i++)
	{
		cout << "Depaptment "<<i+1 << endl;
		for (int m = 0; m < 12; m++)
		{
			cout<<setw(2)<<no_worked_day_by_month[i][m];
		}
	}
}


//for (int i = 0; i < 5; i++)
//{
//	for (int j = 0; j < CountWorker; j++)
//	{
//		for (int m = 0; m < 12; m++)
//		{
//
//		}
//	}
//}