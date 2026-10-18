#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	const int s = 30;
	int roll[s], marks[s],count=0;
	char grade[s];
	int A = 0, B = 0, C = 0, F = 0,topper=0;
	ifstream results("results.txt");
	ofstream toppers("gradeA.txt");
	if (!results )
	{
		cout << "File not found ";
		return 1;
	}
	if (!toppers)
	{
		cout << "File not found ";
		return 1;
	}
	results.ignore(100, '\n');
	while (count<30 && results >> roll[count]>>grade[count]>>marks[count])
	{
		count++;

	}
	cout << " Roll Grade MARKS" << endl;
	for (int i = 0;i < count;i++)
	{   
		cout << roll[i] <<"  " << grade[i] <<"  " << marks[i]<<endl;
		if (grade[i] == 'A')
		{
			A++;
			toppers << roll[i] <<" " << marks[i] << endl;
		}
		else if (grade[i] == 'B')
		{
			B++;
		}
		else if (grade[i] == 'C')
		{
			C++;
		}
		else if (grade[i] == 'F')
		{
			F++;
		}
		if (marks[i] > marks[topper])
			topper = i;


	}
	cout << "Total Students " << count << endl;
	cout << "A: " << A << "  " << "B " << B << endl;
	cout << "C: " << C << "  " << "F: " << F << endl;


	cout << "Topper: Roll " << roll[topper]
		<< " (" << marks[topper] << ")" << endl;
	toppers.close();
	results.close();

}
