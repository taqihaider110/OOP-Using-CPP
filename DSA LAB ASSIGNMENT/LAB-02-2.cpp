#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Person
{
	string FirstName;
	string LastName;
	int BirthYear;
	int BirthMonth;
	int BirthDate;

public:
	Person() : FirstName(""), LastName(""), BirthYear(0), BirthMonth(0), BirthDate(0){};
	Person(string fn, string ln, int by, int bm, int bd) : FirstName(fn), LastName(ln), BirthYear(by), BirthMonth(bm), BirthDate(bd) {}
	void selectionsort(Person People[], int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			// Find the minimum element in unsorted array
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
			{
				if (People[j].BirthYear < People[min_idx].BirthYear || (People[j].BirthYear == People[min_idx].BirthYear &&
																		(People[j].BirthMonth < People[min_idx].BirthMonth || (People[j].BirthMonth == People[min_idx].BirthMonth &&
																															   People[j].BirthDate < People[min_idx].BirthDate))))
				{
					min_idx = j;
				}
				if (min_idx != i)
				{
					swap(People[i], People[min_idx]);
				}
			}
		}
	}
	string getFirstName(){
		return FirstName;
	}
	string getLastName(){
		return LastName;
	}
	int getBirthYear(){
		return BirthYear;
	}
	int getBirthMonth(){
		return BirthMonth;
	}
	int getBirthDate(){
		return BirthDate;
	}
};
int main()
{
	int N;
	cout << "Enter the Number of People(N):";
	cin >> N;
	Person* People=new Person[N];
	for (int i = 0; i < N; i++)
	{
		string first, last;
		int year, month, date;
		cout << "Person " << i + 1 << " Details: " << endl;
		cout << "First Name: ";
		cin >> first;
		cout << "Last Name: ";
		cin >> last;
		cout << "Birth Year: ";
		cin >> year;
		cout << "Birth Month: ";
		cin >> month;
		cout << "Birth Date: ";
		cin >> date;
		People[i] = Person(first, last, year, month, date);
	}
	Person p;
	p.selectionsort(People,N);
	cout << "-----------Sorted List of Persons----------- "<<endl;
	for (int i = 0; i < N; i++)
	{
		cout << People[i].getFirstName() << " " << People[i].getLastName() << " Birthdate: "
			 << People[i].getBirthYear() << "/" << People[i].getBirthMonth() << "/" << People[i].getBirthDate() << endl;
	}
	delete[] People;
	return 0;
}