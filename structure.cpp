#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
typedef struct rectangle{
    float length;
    float breath;
}rectanngle;
int main(){
    //Declration
    rectangle rect1;
    rect1.length = 10.5;
    rect1.breath = 11.5;
    cout<<"Area of reactangle 1: "<<rect1.length*rect1.breath<<endl;

    //Declaration and defining 
    rectangle rect2 = {12.6,4.7};
    cout<<"Area of reactangle 2: "<<rect2.length*rect2.breath<<endl;
}