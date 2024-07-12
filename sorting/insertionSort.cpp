#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr){
    for(auto &it:arr)
        cout<<it<<' ';
    cout<<endl;
}
void insertionSort(vector<int>& arr){
    int n = arr.size();
    cout<<"Insertion Sort"<<endl;
    for(int i=1; i<n; i++){
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j-1],arr[j]);
            j--;
        }
        cout<<endl<<"After "<<i<<" iteration: ";
        printArray(arr);
    }
}
int main(){
    vector<int> arr = {111,32,21,523,63,62,5,3732342,22,45,6,32,53,3};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout<<"Before Sorting: ";
    printArray(arr);
    insertionSort(arr);
    
    cout<<endl<<"After Sorting: ";
    printArray(arr);
}