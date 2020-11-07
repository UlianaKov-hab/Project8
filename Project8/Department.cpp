#include "Department.h"

void Department::CreateDepartment()
{
	CountWorker = 1 + rand() % 5;
	workers = new Worker[CountWorker];
	for (int i = 0; i < CountWorker; i++)
	{
		 workers[i].CreateWorker();
	}
	
}

void Department::PrintDepartment()
{	
	for (int i = 0; i < CountWorker; i++)
	{
		workers[i].PrintWorker();
		cout << endl;
	}
	cout << "----------------------------------" << endl;
}

void Department::AddWorker()
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

void Department::DeleteWorker(int dismiss)
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

void Department::FindWorker(Department* departments)
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

void Department::DepartmentData(Department* departments)
{
	int count_no_worked_deys = 0;
	int count_worked_hours = 0;
	int number;
	int month;
	cout << "Enter number of department";
	cin >> number;
	cout << "Enter number of month";
	cin >> month;
	for (int i = 0; i < 5; i++)
	{
		if (i != number)
		{
			continue;
		}
		else
		{
			for (int j = 0; j < CountWorker; j++)
			{
				for (int m = 0; m < 12; m++)
				{
					count_no_worked_deys += departments[number].workers[j].NumberDaysNoWorked[month-1];
					count_worked_hours += departments[number].workers[j].NumberHoursWorked[month - 1];
				}
			}
		}
	}
	cout << "Department " << number << endl;
	cout << "Number of hours worked:  " << count_no_worked_deys << endl;
	cout << "Number of days not worked:  " << count_worked_hours << endl;

}


