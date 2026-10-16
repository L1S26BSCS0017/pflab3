#include<iostream>
#include<fstream>
using namespace std;
int main()
{   
	char comma;
	const int s = 7;
	double arr[s];
	float sum = 0;
	float count = 0;
	float avg = 0;
	ifstream rainfall("rainfall.txt");
	if (!rainfall)
	{
		cout << "File not found ";
		return 1;
	}
	for (int i = 0; i < s; i++)
	{
		rainfall >> arr[i];
		sum += arr[i];
		count++;
		rainfall.ignore(100, ',');
		//rainfall >> comma;
	}
	rainfall.close();
	avg = sum / count;
	cout << "Total days recorded " << count << endl;
	cout << "Readings " << endl;
	for (int i = 0; i < s; i++)
	{
		cout  << arr[i]<<" ";
	}
	cout << endl;
	cout << "Total rainfall " << sum<<" mm" << endl;
	cout << "Average " << avg << "mm" << endl;
	ofstream write("rainy_days.txt");
	if (!write)
	{
		cout << "File not found ";
		return 1;
	}
	for (int i = 0; i < s; i++)
	{
		if (arr[i] > 0)
		{
			write << "DAY " << i+1 << " " << arr[i] << "mm" << endl;
		}
	}

	write.close();
}