#include<iostream>
#include<string>
using namespace std;
class Person{
	string FirstName;
	string LastName;
	int BirthYear;
	int BirthMonth;
	int BirthDate;
	public:
	Person():FirstName(""),LastName(""),BirthYear(0),BirthMonth(0),BirthDate(0);
	Person(string fn,string ln,int by,int bm,int bd):FirstName(fn),LastName(ln),BirthYear(By),BirthMonth(bm),BirthDate(bd){}
	void selectionsort(Person People[],int n){
		for (i = 0; i < n-1; i++){
			// Find the minimum element in unsorted array
			min_idx = i;
			for (j = i+1; j < n; j++){
				if(People[j].BirthYear<People[min_idx].BirthYear && (People[j].BirthYear==People[min_idx].BirthYear ||
				(People[j].BirthMonth<People[min_idx].BirthMonth && (People[j].BirthMonth==People[min_idx].BirthMonth||
				People[j].BirthDate<People[min_idx].BirthDate)))){
				min_idx = j;
				}
				if(min_idx!=i){
				swap(People[i],People[min_idx]);
			}
		}
	}
};
int main(){
	int N;
	cout<<"Enter the Number of People(N):";
	cin>>N;
	Person People[N];
	for(int i=0;i<N;i++){
		
	}
}