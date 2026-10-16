#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int a = 0, b = 0, ans = 0, correct = 0, question = 0;
	char op;
	char ch;
	ifstream quiz("quiz.txt");
	if (!quiz)
	{
		cout << "File not found ";
		return 1;
	}
	ofstream corrections("corrections.txt");
	if (!corrections)
	{
		cout << "File not found ";
		return 1;
	}
	while (quiz >> a >> op >> b >> ch >> ans)
	{   
		int sum = 0;
		if (op == '+')
		{
			sum= a + b;
			if (sum == ans)
			{
				cout << a << " + " << b << " = " << ans << "Correct " << endl;
				correct++;
			}
			else
			{
				cout << a << " + " << b << " = " << ans << "Wrong " << endl;

				corrections << a << op << b << ch << a + b << "(you wrote " << ans << endl;
			}
		}
		if (op == '-')
		{
			sum = a - b;
			if (sum == ans)
			{
				cout << a << " - " << b << " = " << ans << "Correct " << endl;
				correct++;
			}
		
			else
			{
				cout << a << " - " << b << " = " << ans << "Wrong " << endl;

				corrections << a << op << b << ch << a - b << "(you wrote " << ans<<")" << endl;
			}
		}
		if (op == '*')
		{
			sum = a * b;
			if (sum == ans)
			{
				cout << a << " * " << b << " = " << ans << "Correct " << endl;
				correct++;
			}
			else
			{
				cout << a << " * " << b << " = " << ans << "Wrong " << endl;

				corrections << a << op << b << ch << a * b << "(you wrote " << ans << ")" << endl;
			}
		}
		if(op == '/')
		{
			if (b == 0)
			{
				cout << "Invalid question" << endl;
			}
			else
			{
				float div = static_cast<float>(a) / b;

				if (div == ans)
				{
					cout << a << " / " << b << " = "
						<< ans << " Correct" << endl;
					correct++;
				}
				else
				{
					cout << a << " / " << b << " = "
						<< ans << " Wrong" << endl;

					corrections << a << " / " << b << " = "
						<< div << " (you wrote "
						<< ans << ")" << endl;
				}
			}
		}

		question++;
		
	}
	cout << "Scores = " << correct << "/" << question << endl;
	quiz.close();
	corrections.close();
}