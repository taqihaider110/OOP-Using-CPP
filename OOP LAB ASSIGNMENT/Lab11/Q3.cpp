#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void madesort(vector<int>& array) {
    int n = array.size();
    bool swapped;

    for (int i = 0; i < n - 1; i++) {
        swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            break;
        }
    }

    cout << "Sorted vector through made function: ";
    for (int arr : array) {
        cout << arr << " ";
    }
    cout << endl;
}

void btnsort(vector<int>& array) {
    sort(array.begin(), array.end());

    cout << "Sorted vector through builtin function: ";
    for (int arr : array) {
        cout << arr << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = { 95, 35, 26, 81, 19, 3 };

    cout << "Original vector: ";
    for (int arr : nums) {
        cout << arr << " ";
    }
    cout << endl;

    clock_t startTime = clock();
    madesort(nums);
    clock_t endTime = clock();
    double madeSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    startTime = clock();
    btnsort(nums);
    endTime = clock();
    double builtinSortTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "Time taken by made sort function: " << madeSortTime << " seconds" << endl;
    cout << "Time taken by built-in sort function: " << builtinSortTime << " seconds" << endl;

    return 0;
}
