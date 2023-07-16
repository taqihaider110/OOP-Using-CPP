#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    string line;
    ifstream file1("file1");
    if (!file1) {
        cout << "File does not exist!";
    }
    else {
        fstream file2;
        file2.open("file2", ios::app);
        if (!file2) {
            cout << "Error creating file!";
        }
        else {
            while (getline(file1, line)) {
                file2 << line << endl;
            }
            file2.close();
            cout << "File copied successfully!";
        }
        file1.close();
    }
    return 0;
}
