#include <iostream>
#include <string>
using namespace std;

void input_2Darray(float arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter GPA's for student " << i + 1 << endl;
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void display_array(float arr[5][5])
{
    for (int i = 0; i < 5; i++)
    {
        float sum = 0.0;
        cout<<"GPA's: ";
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j];
            if(j<4){
                cout<<" , ";
            }
            arr[i][j] = arr[i][j] * 3;
            sum += arr[i][j];
        }
        float avg = sum / 15;
        string studentNames[5] = {"Ali", "Hiba", "Asma", "Faisal", "Ali"};
        cout << "  Total GPA of Student " << studentNames[i] << " is: " << avg << endl;
    }
}

int main()
{
    float arr[5][5];
    input_2Darray(arr);
    display_array(arr);
    return 0;
}
