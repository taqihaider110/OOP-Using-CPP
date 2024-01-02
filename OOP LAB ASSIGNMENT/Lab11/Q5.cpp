#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    string Name;
    char choice;
    set<string> guestSet;

    do {
        cout << "Enter the name of a unique guest: ";
        getline(cin, Name);

        guestSet.insert(Name);

        cout << "Do you want to enter another guest? (y/n): ";
        cin >> choice;
        cin.ignore(); 
    } while (choice == 'y' || choice == 'Y');

    cout << endl;
    cout << "Unique guest names in alphabetical order: " << endl;
    for (const string& name : guestSet) {
        cout << name << endl;
    }

    cout << endl;
    cout << "Total number of unique guests: " << guestSet.size() << endl;

    return 0;
}
