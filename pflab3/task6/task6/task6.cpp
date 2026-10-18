#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream inFile("donations.txt");
    if (!inFile) {
        cout << "donations.txt not found!" << endl;
        return 1;
    }

    int n;
    inFile >> n;                                // count on the first line
    inFile.ignore(100,'\n');                          // skip the rest of line 1

    char name[30], topName[30];
    int amount, total = 0, best = -1;

    for (int i = 0; i < n; i++) {
        inFile.getline(name, 30, ',');   // full name
        inFile >> amount;
        inFile.ignore(100,'\n');                      // skip the new line
        cout << "[" << name << "] gave " << amount << endl;
        total = total + amount;
        if (amount > best) {
            best = amount;
            strcpy_s(topName,sizeof(topName), name);                // remember the name
        }
    }
    inFile.close();

    cout << "Donors: " << n << endl;
    cout << "Total collected: " << total << endl;
    cout << "Top donor: " << topName << " (" << best << ")" << endl;
    return 0;
}
