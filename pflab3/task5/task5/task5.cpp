
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char key[10];
    char name[50], answers[11];
    char topName[50] = "";

    int count = 0, passed = 0, failed = 0;
    int score=0, topScore = -1;

    ifstream keyFile("key.txt");
    ifstream responses("responses.txt");
    ofstream scores("scores.txt");

    if (!keyFile || !responses || !scores)
    {
        cout << "File not found!";
        return 1;
    }
    for (int i = 0; i < 10; i++)
    {
        keyFile >> key[i];
    }
    while (responses >> name >> answers)
    {
        score = 0;
        for (int i = 0; i < 10; i++)
        {
            if (answers[i] == key[i])
            {
                score++;
            }
        }

        cout << name << ": " << score << "/10" << endl;
        scores << name << " " << score << endl;
        if (score >= 5)
        {
            passed++;
        }
        else
        {
            failed++;
        }
        if (score > topScore)
        {
            topScore = score;
            strcpy_s(topName, sizeof(topName), name);
        }

        count++;
    }

    cout << "Passed: " << passed
        << "  Failed: " << failed << endl;

    if (count > 0)
    {
        cout << "Topper: " << topName
            << " (" << topScore << "/10)" << endl;
    }

    keyFile.close();
    responses.close();
    scores.close();

    return 0;
}
