#include<iostream>
#include<vector>
using namespace std;
int minimum(vector<int>&arr){
    int mini = INT_MAX;
    int lb = 0;
    int ub = arr.size()-1;
    while(lb<=ub){
        if(arr[lb]<=arr[ub]){
            return min(mini,arr[lb]);
        }
        int mid = lb+(ub-lb)/2;
        if(arr[lb]<=arr[mid]){
            mini = min(mini,arr[lb]);
            lb = mid+1;
        }
        else{
            mini = min(arr[mid],mini);
            ub= mid-1;
        }
    }
    return mini;
}
int main(){
    vector<int> arr = {3,4,5,1,2};
    cout<<minimum(arr);
}