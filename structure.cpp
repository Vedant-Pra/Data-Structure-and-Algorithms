#include <stdio.h>
using namespace std;
#include <bits/stdc++.h>
struct rectangle{
    float length;
    float breath;
};
int main(){
    rectangle rect1;
    rect1.length = 10.5;
    rect1.breath = 11.5;
    cout<<rect1.length*rect1.breath;
}