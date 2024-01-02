#include<iostream>
using namespace std;
class Sort{
	int* arr;
	int n;
	string choice;
	int cmp[3],swap[3];
	public:
		Sort(int x): n(x){
			arr = new int[x];
		}
		void bubbleSort(){
			for(int i=0;i<n;i++){
				cmp[0]++;
				for(int j=0;j<n-i-1;j++){
					cmp[0]++;
					if(arr[j]>arr[j+1]){
						int temp;
						temp=arr[j];
						arr[j]=arr[j+1];
						arr[j+1]=temp;
						swap[0]++;
					}
					cmp[0]++;
				}
			}
		}
		void InsertionSort(){
			int key;
			for(int i=1;i<n;i++){
				cmp[1]++;
				key=arr[i];
				int j=i-1;
				while( j >=0 && arr[j]>key){
					arr[j+1]=arr[j];
					j--;
					cmp[1]++;
					swap[1]++;
				}
				arr[j+1]=key;
				swap[1]++;
			}
		}
		void SelectionSort(){
			int min_index=0;
			for(int i=0;i<n;i++){
				cmp[2]++;
				min_index=i;
				for(int j=i+1;j<n;j++){
					cmp[2]++;
					if(arr[j]<arr[min_index]){
						min_index=j;
					}
					cmp[2]++;
				}
				if(min_index!=i){
					int temp;
					temp=arr[i];
					arr[i]=arr[min_index];
					arr[min_index]=temp;
					swap[2]++;
				}
			}
		}
		void choose(){
			cout<<"Enter Data of Array:"<<endl;
			for(int i=0;i<n;i++){
				cin>>arr[i];
			}
			cout<<"\nBefore Sort:\n";
			Display();
			cout<<"enter choice b:bubble i:insertion s:selection"<<endl;
			cin>>choice;
			if(choice=="b"){
				bubbleSort();
			}
			else if(choice=="i"){
				InsertionSort();
			}
			else{
				SelectionSort();
			}
			cout<<"\nAfter Sort:\n";
			Display();
		
		}
		void comparison(){
			for(int i=0;i<3;i++){
				cmp[i]=0;
				swap[i]=0;
			}
			int temp[n];
			for(int i=0;i<n;i++){
				arr[i]=rand();
				temp[i]=arr[i];
			}
			bubbleSort();
			for(int i=0;i<n;i++){
				arr[i]=temp[i];
			}
			InsertionSort();
			for(int i=0;i<n;i++){
				arr[i]=temp[i];
			}
			SelectionSort();
			
			int BestS=99999,WorstS=-1,BestC=99999,WorstC=-1;
            int tBS,tWS,tBC,tWC;
            
			for(int i=0;i<3;i++){
            	if(swap[i]<BestS){
            		BestS=swap[i];tBS=i;
				}
				if(swap[i]>WorstS){
            		WorstS=swap[i];tWS=i;
				}
				if(cmp[i]<BestC){
					BestC=cmp[i];tBC=i;
				}
				if(cmp[i]>WorstC){
            		WorstC=cmp[i];tWC=i;
				}
			}
			
			cout<<"Test Array:\n";
			for(int i=0;i<n;i++){
				cout<<temp[i]<<"	";
			}
			cout<<endl<<endl;
			
			cout<<"Bubble Sort for "<<n<<" Size array - Comparisons: "<<cmp[0]<<"  Swaps: "<<swap[0]<<endl;
			cout<<"Insertion Sort for "<<n<<" Size array - Comparisons: "<<cmp[1]<<"  Swaps: "<<swap[1]<<endl;
			cout<<"Selection Sort for "<<n<<" Size array - Comparisons: "<<cmp[2]<<"  Swaps: "<<swap[2]<<endl<<endl<<endl;
			cout<<"Technique 0 = BubbleSort, 1 = InsertionSort, 2 = SelectionSort"<<endl<<endl;
			cout<<"Best Technique (Comparisons) : "<<tBC<<" - at "<<BestC<<" Comparisons."<<endl<<endl;
			cout<<"Worst Technique (Comparisons) : "<<tWC<<" - at "<<WorstC<<" Comparisons."<<endl<<endl;
			cout<<"Best Technique (Swaps) : "<<tBS<<" - at "<<BestS<<" Swaps."<<endl<<endl;
			cout<<"Worst Technique (Swaps) : "<<tWS<<" - at "<<WorstS<<" Swaps."<<endl<<endl;
			
		}
		
		void Display(){
			for(int i=0;i<n;i++){
				cout<<arr[i]<<"	";
			}
			cout<<endl<<endl;
		}
};

int main(){
	int n;
	cout<<"Enter Size of Array to sort:\n";
	cin>>n;
	Sort x(n);
	x.choose();
	cout<<"\n\nEnter Size of Array to Compare sorts:\n";
	cin>>n;
	Sort y(n);
	y.comparison();
}