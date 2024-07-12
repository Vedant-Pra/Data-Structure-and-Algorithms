#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr){
    for(auto &it:arr)
        cout<<it<<' ';
    cout<<endl;
}
void bubbleSort(vector<int>& arr){
    int n = arr.size();
    cout<<endl<<"Bubble Sort"<<endl;
    for(int i= 0; i< n-1;i++){
        bool flag = true;   // Flag to check at any point if the array is sorted. If not then flag will be false.
        for(int j=1;j<n-i;j++){
            if(arr[j-1]>arr[j]){
                flag = false;
                swap(arr[j-1],arr[j]);
            }
        }
        cout<<endl<<"After "<<i+1<<" iteration: ";
        printArray(arr);
        if(flag)   //If flag is true --> sorted --> outer loop will break;
            break;
    }
}
int main(){
    vector<int> arr = {111,32,21,523,63,62,5,3732342,22,45,6,32,53,3};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout<<"Before Sorting: ";
    printArray(arr);
    bubbleSort(arr);
    
    cout<<endl<<"After Sorting: ";
    printArray(arr);
}