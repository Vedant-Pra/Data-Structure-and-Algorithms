#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr){
    for(auto &it:arr)
        cout<<it<<' ';
    cout<<endl;
}
void merge(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int i=low,j=mid+1;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=high){
        temp.push_back(arr[j++]);
    }
    int k = 0;
    for(i=low;i<=mid;i++){
        arr[i]=temp[k++];
    }
    for(j=mid+1;j<=high;j++){
        arr[j]=temp[k++];
    }
    cout<<"After Merging: ";
    printArray(arr);
}
void mergeSort(vector<int>& arr){
    int n=arr.size();
    int i;
    cout<<"Iterative Merge Sort"<<endl;
    for(i=2;i<=n;i=i*2){
        for(int j=0;j+i-1<=n;j+=i){
            int low = j;
            int high = j+i-1;
            int mid = low + (high-low)/2;
            merge(arr,low,mid,high);
        }
    }
    if(i/2<n)
        merge(arr,0,i/2-1,n-1);
}
int main(){
    vector<int> arr = {111,32,21,523,63,62,5,3732342,22,45,6,32,53,3};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout<<"Before Sorting: ";
    printArray(arr);
    mergeSort(arr);
    cout<<endl<<"After Sorting: ";
    printArray(arr);
}