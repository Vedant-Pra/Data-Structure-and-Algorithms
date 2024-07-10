#include<bits/stdc++.h>
using namespace std;

//Passing by value
void swap1(int a,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void swap3(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}



int main(){
    int a = 5;
    int b = 10;
    cout<<"Values of a and b before swap: "<<a<<" "<<b<<endl;
    cout<<"Calling pass by value swap"<<endl;
    swap1(a,b);
    cout<<"Values of a and b after swap: "<<a<<" "<<b<<endl<<endl;

    cout<<"Values of a and b before swap: "<<a<<" "<<b<<endl;
    cout<<"Calling pass by value address"<<endl;
    swap2(&a,&b);
    cout<<"Values of a and b after swap: "<<a<<" "<<b<<endl<<endl;

    cout<<"Values of a and b before swap: "<<a<<" "<<b<<endl;
    cout<<"Calling pass by reference swap"<<endl;
    swap3(a,b);
    cout<<"Values of a and b after swap: "<<a<<" "<<b<<endl<<endl;
}