#include "Department.h"
#include<time.h>
using namespace std;
void main()
{
	/*srand(time(0));*/
	Department departments[4];
	int NumberDepartment[4] = { 1, 2, 3, 4 };
	
		for (int i = 0; i < 4; i++)
		{
			departments[i].CreateDepartment();
		}
		for (int i = 0; i < 4; i++)
		{
			cout << "Department number # ";
			cout << NumberDepartment[i] << endl;
			departments[i].PrintDepartment();
		}
}