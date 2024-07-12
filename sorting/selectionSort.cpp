#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr){
    for(auto &it:arr)
        cout<<it<<' ';
    cout<<endl;
}
void selectionSort(vector<int>& arr){
    int n = arr.size();
    cout<<"Selection Sort"<<endl;
    for(int i=0; i<n-1;i++){
        int smallestIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[smallestIndex]>arr[j])
                smallestIndex=j;
        }
        swap(arr[i],arr[smallestIndex]);
        cout<<endl<<"After "<<i+1<<" iteration: ";
        printArray(arr);
    }
}
int main(){
    vector<int> arr = {111,32,21,523,63,62,5,3732342,22,45,6,32,53,3};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout<<"Before Sorting: ";
    printArray(arr);
    selectionSort(arr);
    cout<<endl<<"After Sorting: ";
    printArray(arr);
}