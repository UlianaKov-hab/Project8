#include "Department.h"
using namespace std;

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
void AddWorker(Department* departments, int index) //2
{
	Worker* workers1 = new Worker[departments[index].CountWorker+1];
	for (int i = 0; i < departments[index].CountWorker; i++)
	{
		workers1[i]= departments[index].workers[i];
	}
	workers1[departments[index].CountWorker].CreateWorker();
	delete[] departments[index].workers;
	departments[index].CountWorker++;
	departments[index].workers = workers1;
}
void Department::DeleteWorker(int index_worker) //3
{
	Worker* workers1 = new Worker[CountWorker-1];
	CountWorker--;
	for (int i = 0; i < CountWorker; i++)
	{
		if ( i < index_worker)
		{
			workers1[i] = workers[i];
		}
		else if (i >= index_worker)
		{
			workers1[i] = workers[i+1];
		}		
	}
	delete[] workers;
	workers = workers1;	
}

void SortWorkers(Department* departments) //4
{
	int count_workers = 0;
	for (int i = 0; i < 5; i++)
	{
		count_workers+=departments[i].CountWorker;				
	}
	cout << count_workers << endl;
	Worker* workers1 = new Worker[count_workers];
	for (int i = 0, k=0; i < 5; i++)
	{
		for (int j = 0; j < departments[i].CountWorker; j++, k++)
		{
			workers1[k] = departments[i].workers[j];
		}
	}
	for (int i = 0; i < count_workers; i++)
	{
		for (int j = 0; j < count_workers-1; j++)
		{
			if (workers1[j].LastName > workers1[j+1].LastName)
			{
				swap(workers1[j] , workers1[j + 1]);
			}
		}
	}
	for (int i = 0; i < count_workers; i++)
	{
		workers1[i].PrintWorker();
		cout << endl;
	}	
}

void FindWorker(Department* departments) //5
{
	string FirstNameFind;
	string LastNameFind;
	//int PersonalNumberFind;

	cout << "Enter information about the worker to search:" << endl;
	cout << "First name: ";
	cin >> FirstNameFind;
	cout << "Last name: ";
	cin >> LastNameFind;
	//cout << "Personal number: ";
	//cin >> PersonalNumberFind;
	cout << endl;
	system("CLS");	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < departments[i].CountWorker; j++)
		{
			if (departments[i].workers[j].FirstName == FirstNameFind && departments[i].workers[j].LastName == LastNameFind)
			{
				departments[i].workers[j].PrintWorker();
			}			
		}		
	}	
}
void DepartmentData(Department* departments, int index) //6
{
	int count_worked_hours = 0;	
	int month;	
	bool a = true;
	do
	{
		cout << "Enter number of month  ";
		cin >> month;
		for (int i = 0; i < departments[index].CountWorker; i++)
		{
			for (int m = 0; m < 12; m++)
			{
				count_worked_hours += departments[index].workers[i].NumberHoursWorked[month - 1];
			}
		}	
	cout << "* D E P A R T M E N T   # " << index + 1 << " *" << endl;
	cout << "Number of hours worked in "<< month<<" months: " << count_worked_hours << endl;
	cout <<  endl;
	cout << "Next month? - press 1"<<endl;
	cout << "Exit - press 0" << endl;	
	cin >> a;
	//system("pause");
	system("CLS");
	} while (a == true);
}
void Department::SumHoursWorker(int index_worker) //7
{
	int count_worked_hours = 0;	
	
	for (int m = 0; m < 12; m++)
	{
		count_worked_hours += workers[index_worker].NumberHoursWorked[m];			
	}	
	workers[index_worker].PrintWorker();
	cout << endl;
	cout << "Number of hours worked per year " <<  count_worked_hours << endl;
	cout << endl;
}
void Department::Change_worker_position(int index_worker)//11
{
	string new_position;
	cout << "Enter new worker position ";
	getline(cin, new_position);
	workers[index_worker].Position = new_position;
	PrintDepartment();

}
void Average_amount_no_worked_day_depart_per_year(Department* departments, int index) //8
{	
	float sum;
	float average_amount_no_worked_day_depart[5];
	sum = 0;
	for (int j = 0; j < departments[index].CountWorker; j++)
	{
		for (int m = 0; m < 12; m++)
		{
			sum+= departments[index].workers[j].NumberDaysNoWorked[m];
		}
	}
	average_amount_no_worked_day_depart[index] = sum/ departments[index].CountWorker/12;
	cout << endl;
	cout << "Average amount no worked day in department # " << index + 1 << " per year: " << sum / departments[index].CountWorker << endl;
	cout << endl;
}
void Count_no_worked_day_by_month(Department* departments) //9
{
	int no_worked_day_by_month[5][12];
	int sum;
	for (int i = 0; i < 5; i++)
	{		
		sum = 0;
		for (int m = 0; m < 12; m++)
		{
			sum;
			for (int j = 0; j < departments[i].CountWorker; j++)
			{
				sum+= departments[i].workers[j].NumberDaysNoWorked[m];
			}
			no_worked_day_by_month[i][m] = sum;
		}			
	}
	cout << "Number no worked days per mohths"<<endl;
	cout << endl;
	cout << endl;
	for (int m = 0; m < 12; m++)
	{
		cout << setw(4) << m+1 << " ";
		
	}
	cout << " Month" << endl;
	cout << endl;
	cout << endl;
	
	
	for (int i = 0; i < 5; i++)
	{
		cout << "         * D E P A R T M E N T   # " << i + 1 << " *" << endl;		
		for (int m = 0; m < 12; m++)
		{
			cout<<setw(4)<<no_worked_day_by_month[i][m]<<" ";
		}
		cout << endl;
		cout << endl;
	}
}
void Count_no_worked_day_per_year(Department* departments)//10
{
	int count_no_worked_day_per_year=0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < departments[i].CountWorker; j++)
		{
			for (int m = 0; m < 12; m++)
			{
				count_no_worked_day_per_year+= departments[i].workers[j].NumberDaysNoWorked[m];
			}
		}
	}
	cout << "Total days not worked per year: " << count_no_worked_day_per_year << endl;
	cout << endl;
}

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}

int Menu(string menu_items[], int SIZE)
{
	int key = 0;
	int code;
	do {
		//system("cls");
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(0, 2 + i);
			if (key == i)
			{

				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;

	//return 0;
}

int MenuWorker(Worker* workers, int size)
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + size) % size;
		for (int i = 0; i < size; i++)
		{
			if (key == i)
			{
				SetColor(6);  workers[i].PrintWorker(); SetColor(3); SetColor(15);
				cout << endl;
			}
			else
			{
				workers[i].PrintWorker();
				cout << endl;
			}
		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int MenuDep(Department* departments)
{	
	Size_Console(65, 45);
	string menu[] = { "Department # 1","Department # 2",
		"Department # 3","Department # 4",
		"Department # 5", "Exit" };
	int index = Menu(menu, size(menu));
	
	return index;
}


int MainMenu(Department* departments)
{
	Size_Console(65, 45);
	string menu[] = { "1.Show all workers data","2.Add worker",
		"3.Delete worker","4.Sort workers by Last Name",
		"5.Find worker", "6.Show the number of hours worked by month in the department",
		"7.Number of hours worked per year of the worker", "8.Average amount no worked day in department",
		"9.Count no worked day by month", "10.Count no worked day per year", "11.Change worker position", "0.Exit" };
	int m = Menu(menu, size(menu));
	if (m == 0) //Show all workers data
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "* D E P A R T M E N T   # " << i + 1 <<" *"<< endl;
			cout <<  endl;			
			departments[i].PrintDepartment();
		}
	}
	if (m == 1)//Add worker
	{
		cout << "Select department"<<endl;		
		
		int index = MenuDep(departments);
		cout << "* D E P A R T M E N T   # " << index + 1 << " *" << endl;
		departments[index].PrintDepartment();
		system("pause");
		system("CLS");
		
		AddWorker(departments, index);
		cout << "* D E P A R T M E N T   # " << index + 1 << " *" << endl;
		departments[index].PrintDepartment();
	}
	if (m == 2) //DeletWorcer
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);		
		int index_worker = MenuWorker(departments[index].workers, departments[index].CountWorker);
		departments[index].DeleteWorker(index_worker);
		/*system("pause");
		system("CLS");	*/	
		departments[index].PrintDepartment();
	}
	if (m == 3) //Sort workers
	{		
		SortWorkers(departments);		
	}
	if (m == 4)
	{		
		FindWorker(departments);
	}
	if (m == 5)
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);
		DepartmentData(departments, index);
	}
	if (m == 6)
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);		
		int index_worker = MenuWorker(departments[index].workers, departments[index].CountWorker);
		//SumHoursWorker(departments, index, index_worker);		
		departments[index].SumHoursWorker(index_worker);
	}
	if (m == 7)
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);
		Average_amount_no_worked_day_depart_per_year(departments, index);
	}
	if (m == 8)
	{
		Count_no_worked_day_by_month(departments);
	}
	if (m == 9)
	{
		Count_no_worked_day_per_year( departments);
	}
	if (m == 10)
	{
		cout << "Select department" << endl;
		int index = MenuDep(departments);
		int index_worker = MenuWorker(departments[index].workers, departments[index].CountWorker);
		departments[index].Change_worker_position(index_worker);
	}
	/*if (m == 11)
	{
		return 13;
	}*/
	
	system("pause");
	system("CLS");
	return m;
}
