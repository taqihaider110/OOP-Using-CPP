#include <iostream>
using namespace std;
class ArrayMultiplier
{
public:
    virtual void calculate() = 0;
};
class ArrayMultiplier1D : public ArrayMultiplier
{
    int *arr;
    int size;

public:
    ArrayMultiplier1D(int *array, int s) : arr(array), size(s) {}
    void calculate()
    {
        int result = 1;
        for (int i = 0; i < size; i++)
        {
            result *= arr[i];
        }
        cout << "1D Array Multiplication " << result << endl;
    }
};
class ArrayMultiplier2D : public ArrayMultiplier
{
    int **arr;
    int rows;
    int columns;

public:
    ArrayMultiplier2D(int **array, int r, int c) : arr(array), rows(r), columns(c) {}
    void calculate()
    {
        int result = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                result *= arr[i][j];
            }
        }
        cout << "2D Array Multiplication " << result << endl;
    }
};
int main()
{
    int Arrsize1D;
    cout << "Enter the 1D array size:";
    cin >> Arrsize1D;
    int *arr1D = new int[Arrsize1D];
    cout << "Enter the 1D array elements:";
    for (int i = 0; i < Arrsize1D; i++)
    {
        cin >> arr1D[i];
    }
    ArrayMultiplier1D arrayMultiplier1D(arr1D, Arrsize1D);
    arrayMultiplier1D.calculate();
    delete[] arr1D;
    int Arrsize2D;
    int numRows, numCols;
    cout << "Enter the number of rows in the 2D array: ";
    cin >> numRows;
    cout << "Enter the number of columns in the 2D array: ";
    cin >> numCols;

    int** arr2D = new int*[numRows];
    cout << "Enter the elements of the 2D array: ";
    for (int i = 0; i < numRows; i++) {
        arr2D[i] = new int[numCols];
        for (int j = 0; j < numCols; j++) {
            cin >> arr2D[i][j];
        }
    }
    ArrayMultiplier2D arrayMultiplier2D(arr2D, numRows, numCols);
    arrayMultiplier2D.calculate();
    for (int i = 0; i < numRows; i++) {
        delete[] arr2D[i];
    }
    delete[] arr2D;
}