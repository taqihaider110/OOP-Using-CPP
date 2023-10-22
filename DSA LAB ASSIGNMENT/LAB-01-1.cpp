#include <iostream>
using namespace std;

int main()
{
    int rows = 4;
    int columns = 4;

    int twoDArray[rows][columns] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {1, 5, 7, 19}};
    int oneDArray[rows * columns];

    // Copy data from the 2D array to the 1D array in column-major order
    int index = 0;
    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            oneDArray[index] = twoDArray[i][j];
            index++;
        }
    }

    // Display the 1D array
    cout << "1D array (Column Major Order):" << endl;
    for (int i = 0; i < rows * columns; i++)
    {
        cout << oneDArray[i] << " ";
    }
    cout << endl;

    return 0;
}
