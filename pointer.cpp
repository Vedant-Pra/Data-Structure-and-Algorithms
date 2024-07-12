#include<bits/stdc++.h>
using namespace std;


typedef struct rectangle{
    float length;
    float breath;
}rectangle;

int min(int a, int b){
    cout<<"This function is the function pointed by a pointer"<<endl;
    return a>b?a:b;
}

int main(){

    //Poiter to a variable
    int a = 10;
    int *p;             //Pointer declaration
    p=&a;               //Pointer initialization. & --> address of operator  
    cout<<"Value of a: "<<a<<endl;
    cout<<"Address of a: "<<&a<<endl;
    cout<<"Value of p: "<<p<<endl;
    cout<<"Address of p: "<<&p<<endl;
    cout<<"Value at the address stored in p: "<<*p<<endl; // Pointer  dereferencing

    // Pointer to an array in the heap
    int *arr = new int[5];
    for(int i=0;i<5;i++){
        // arr[i]=i;        //Way 1
        *(arr+i)=i;         //Way 2 Value at adderss arr+i = i
    }
    for(int i=0;i<5;i++){
        // cout<<arr[i]<<" ";
        cout<<*(arr+i)<<" ";
    }
    cout<<endl;

    // Pointer to a structure
    rectangle rect = {10,15};
    rectangle *rectPtr = &rect;
    cout<<"Rectagle 1: Lenght: "<<rectPtr->length<<", "<<"Breath: "<<(*rectPtr).breath<<endl; // Two ways to access the variables. Using . operator and arrow operator

    rectangle *rectPtr2 = new rectangle;
    rectPtr2->length=1;
    rectPtr2->breath=2;
    cout<<"Rectagle 2: Lenght: "<<rectPtr2->length<<", "<<"Breath: "<<(*rectPtr2).breath<<endl;

    cout<<"Pointer to a function"<<endl;
    int (*fp)(int,int);           //pointer must be inside the bracket and and must be followed by bracket
    fp = min;       
    cout<<(*fp)(4,5);                //function call. We can pass args in the brackets.

}

