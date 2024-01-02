#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    int length_s = str.length();

    ofstream my_file("file1");
    if (!my_file) {
        cout << "File not created!";
    }
    else {
        my_file << str;
        my_file.close();
    }

    ifstream read_file("file1");
    if (!read_file) {
        cout << "Error opening file!";
    }
    else {
        string filestring;
        while (getline(read_file, filestring)) {
            cout << filestring;
        }
        read_file.close();
    }

    return 0;
}
