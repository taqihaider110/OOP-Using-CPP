#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter No.Of students:";
    cin >> n;
    cin.ignore();
    string **StudentNames = new string *[n];
    int *count = new int[n];
    for (int i = 0; i < n; i++)
    {
        int n1;
        cout << "Total No. of Contributors for student " << i + 1 << ": ";
        cin >> n1;
        cin.ignore();
        count[i] = n1;
        StudentNames[i] = new string[n1];
        cout << "Enter Contributor names for Student " << i + 1 << ": " << endl;
        for (int j = 0; j < n1; j++)
        {
            cout << "Contributor " << j + 1 << ": ";
            getline(cin, StudentNames[i][j]);
        }
    }
    string SearchName;
    cout << "Enter Name you want to search:" << endl;
    getline(cin, SearchName);
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            if (StudentNames[i][j] == SearchName)
            {
                found = true;
                cout << SearchName << " Found in the contributor list of Student " << i + 1 << ". " << endl;
                break;
            }
        }
    }
    if (!found)
    {
        cout << SearchName << " Not found in the contributor list of Student." << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] StudentNames[i];
    }
    delete[] StudentNames;
    delete[] count;
    return 0;
}