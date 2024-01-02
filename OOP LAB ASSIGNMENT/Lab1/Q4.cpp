#include<iostream>
using namespace std;
void print_matrix(int matrix[3][3]){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
void add_matrix(int matrix1[3][3],int matrix2[3][3],int result[3][3]){
    cout<<"The sum of two matrix is "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    
}
void mult_matrix(int matrix1[3][3],int matrix2[3][3],int result[3][3]){
    cout<<"The product of two matrix is "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            result[i][j]=0;
            for (int k = 0; k < 3; k++)
            {
                result[i][j]+=matrix1[i][k] * matrix2[k][j];
            }   
        }
    }
}
int main(){
    int matrix1[3][3],matrix2[3][3],sum[3][3],product[3][3];
    //Input first matrix
    cout<<"Enter the element of first matrix: "<<endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin>>matrix1[i][j];
        }
    }
    //Input Second matrix
    cout<<"Enter the element of second matrix: "<<endl;
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <3; j++)
        {
            cin>>matrix2[i][j];
        }
        
    }
    cout<<"Matrix 1: "<<endl;
    print_matrix(matrix1);
    cout<<"Matrix 2: "<<endl;
    print_matrix(matrix2);
    add_matrix(matrix1,matrix2,sum);
    print_matrix(sum);
    mult_matrix(matrix1,matrix2,product);
    print_matrix(product);
    return 0;
}