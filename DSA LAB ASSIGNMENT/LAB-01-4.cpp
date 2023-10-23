#include <iostream>
using namespace std;
class matrix
{
    int row, column;

public:
    int **arr1, **arr2;
    matrix(int r, int c) : row(r), column(c) {}
    void arr1(int row, int column)
    {
        arr1[row][column];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << "Enter element of array 1 at position (" << i + 1 << "," << j + 1 << ") : ";
                cin >> arr1[i][j];
            }
        }
    }
    void arr1_1D()
    {
        int *arr1_1d = new int[row * column];
        int k = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                // cout << "Element [" << i << "][" << j <<"]=" << arr1[i][j] << endl;
                arr1_1d[k] = arr1[i][j];
                k++;
            }
        }
        delete[] arr1_1d;
    }
    void arr2(int row, int column)
    {
        arr2[row][column];
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << "Enter element of array 1 at position (" << i + 1 << "," << j + 1 << ") : ";
                cin >> arr2[i][j];
            }
        }
    }
    void arr2_1D()
    {
        int *arr2_1d = new int[row * column];
        int k = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                // cout << "Element [" << i << "][" << j <<"]=" << arr1[i][j] << endl;
                arr2_1d[k] = arr2[i][j];
                k++;
            }
        }
        delete[] arr2_1d;
    }
    void multiply(matrix &x){
        

    }
};
int main()
{
    return 0;
}