
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    int count = 0, day = 0, month = 0, year = 0;
    int inhour = 0, inmin = 0, outhour = 0, outmin = 0;
    int start = 0, finish = 0, work = 0, total = 0;
    int hours = 0, minutes = 0, late = 0;
    char slash;

    ifstream intput("attendance.txt");

    if (!intput)
    {
        cout << "File not found";
        return 1;
    }

    while (intput >> day >> slash >> month >> slash >> year >> inhour)
    {
        intput.ignore(1, ':');
        intput >> inmin;

        intput >> outhour;
        intput.ignore(1, ':');
        intput >> outmin;

        start = inhour * 60 + inmin;
        finish = outhour * 60 + outmin;

        work = finish - start;
        total = total + work;

       
        hours = work / 60;
        minutes = work % 60;

      
        cout << day << "/" << month << "/" << year
            << " worked " << hours << " h "
            << minutes << " min";

        
        if (inhour > 9 || (inhour == 9 && inmin > 0))
        {
            cout << " (LATE)";
            late++;
        }

        cout << endl;
        count++;
    }
    cout << "Total worked: " << total / 60
        << " h " << total % 60 << " min" << endl;

    cout << "Days late: " << late << endl;

    intput.close();

    return 0;
}
