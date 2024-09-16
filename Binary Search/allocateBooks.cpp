#include<iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;
int calc(vector<int>&arr,int m,int size){
    int count = 0;
    int i = 0;
    while(i<arr.size()){
        int sum = 0;
        while(i<arr.size() && sum+arr[i]<=size){
            sum+=arr[i];
            i++;
        }
        count++;
    }
    return count;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n)
        return -1;
    int lb = *max_element(arr.begin(),arr.end());
    int ub = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(lb<=ub){
        int mid = lb+(ub-lb)/2;
        int count = calc(arr,m,mid);
        if(count<=m)
            ub = mid-1;
        else    
            lb = mid+1;
    }
    return lb;
}
int main(){
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;
    cout<<findPages(arr,4,2);
    return 0;
}