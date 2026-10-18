#include <iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream inFile("sensor.txt");
    if (!inFile) {
        cout << "sensor.txt not found!" << endl;
        return 1;
    }

    int count = 0, bad = 0, x;
    int total = 0;
    char junk[50];
    ofstream outFile("clean.txt");

    while (count < 20) 
    {
        if (inFile >> x) 
        {                 // a number
            if (x == -1)                   // sentinel: stop
                break;
            outFile << x << endl;
            total = total + x;
            count++;
        }
        else if (inFile.eof())             // end of the file
            break;
        else {                             // junk
            inFile.clear();
            inFile >> junk;
            bad++;
        }
       
    }
    inFile.close();
    outFile.close();

    cout << "Valid readings: " << count << endl;
    cout << "Skipped: " << bad << endl;
    cout << "Average: "
        << static_cast<double>(total) / count << endl;
    return 0;
}
