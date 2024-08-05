#include <bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr)
{
    for (auto &it : arr)
        cout << it << ' ';
    cout << endl;
}
int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(i<high && arr[i]<=pivot){
            i++;
        }
        while(j>low && arr[j]>pivot){
            j--;
        }
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high)
{
    if(low<high){
        int partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}
int main()
{
    vector<int> arr = {24, 18, 38, 43, 14, 40, 1, 54};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout << "Before Sorting: ";
    printArray(arr);
    quickSort(arr, 0, arr.size() - 1);
    cout << endl
         << "After Sorting: ";
    printArray(arr);
}