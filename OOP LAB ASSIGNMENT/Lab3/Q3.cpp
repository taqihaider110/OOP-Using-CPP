#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class bookType{
    string Title,publisher;
    int ISBN,CopiesinStock,AuthorNo;
    double Price;
    string* author;
    public:
        bookType(){Title="";publisher="";ISBN=0;CopiesinStock=0;AuthorNo=0;Price=0;author=NULL;}
        bookType(int N){
            Title="";
            publisher="";
            ISBN=0;
            CopiesinStock=0;
            AuthorNo=N;
            Price=0;
            author= new string[AuthorNo];
        }
        //////all
        void showalldata(){
            showtitle();
            showauthors();
            showPublisher();
            showISBN();
            showPrice();
            showstock();
        }
        void setalldata(){
            settitle();
            setauthors();
            setPublisher();
            setISBN();
            setPrice();
            setstock();
        }
        //////title
        void showtitle(){cout<<"Title : "<<Title<<endl;}
        void settitle(){
            cout<<"Enter Title of Book : "<<endl;
            cin>>Title;
            fflush(stdin);
        }
        //////stock
        void showstock(){cout<<"Number of Copies in stock : "<<CopiesinStock<<endl;}
        void setstock(){
            cout<<"Enter number of Copiess in stock : "<<endl;
            cin>>CopiesinStock;
        }
        void updatestock(){
            int diff;
            cout<<"How much to change stock by (+ve to add, -ve to reduce):"<<endl;
            cin>>diff;
            CopiesinStock+=diff;
        }
        //////authors
        void showauthors(){
            cout<<"Authors : "<<AuthorNo<<endl;
            for(int i=0;i<AuthorNo;i++){
                cout<<" Author #"<<i+1<<" : "<<author[i]<<endl;
            }
        }
        void setauthors(){
            cout<<"Input Number of Authors :"<<endl;
            cin>>AuthorNo;
            author= new string[AuthorNo];
            for(int i=0;i<AuthorNo;i++){
                cout<<"Input name of Author #"<<i+1<<endl;
                cin>>author[i];
                fflush(stdin);
            }
        }
        //////publisher
        void showPublisher(){cout<<"Publisher : "<<publisher<<endl;}
        void setPublisher(){
            cout<<"Enter Name of Publisher : "<<endl;
            cin>>publisher;
            fflush(stdin);
        }
        //////ISBN
        void showISBN(){cout<<"ISBN : "<<ISBN<<endl;}
        void setISBN(){
            cout<<"Enter ISBN of book :"<<endl;
            cin>>ISBN;
        }
        //////Price
        void showPrice(){cout<<"Price : "<<Price<<"$"<<endl;}
        void setPrice(){
            cout<<"Enter Price of Book : "<<endl;
            cin>>Price;
        }
        void updatePrice(){
            double diff;
            cout<<"How much to change price by : "<<endl;
            cin>>diff;
            Price+=diff;
        }
        //////CheckTitle
        int CheckTitle(string T){
            if(T == Title){return 1;}
            else{return 0;}
        }
        //////Deconstructor
        ~bookType(){
            delete author;
            cout<<"Deconstructor was called"<<endl;
        }

};

int main(){
    int N;
    cout<<"Enter Number of Books in array :"<<endl;
    cin>>N;
    bookType books[N];
    for(int i=0;i<N;i++){
        cout<<endl<<"Book #"<<i+1<<endl;
        books[i].setalldata();
    }
    for(int j=0;j<N;j++){
        cout<<endl<<"Book #"<<j+1<<endl;
        books[j].showalldata();
    }
    string SearchTitle;
    int found=0;
    cout<<"Enter Title you want to search : "<<endl;
    cin>>SearchTitle;
    for(int k=0;k<N;k++){
        found=books[k].CheckTitle(SearchTitle);
        if(found==1){
            cout<<"Book \""<<SearchTitle<<"\" was found at index "<<k<<" of Books[]"<<endl;
        }
        found=0;
    }
    return 0;
}