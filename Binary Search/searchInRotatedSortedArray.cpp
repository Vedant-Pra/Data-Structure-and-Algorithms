#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>&arr,int target){
    int lb = 0;
    int ub = arr.size()-1;
    while(lb<=ub){
        int mid = lb+(ub-lb)/2;
        if(arr[mid]==target)
            return mid;
        else if(arr[lb]<=arr[mid])      // Left half sorted
        {
            if(target>=arr[lb] && target<arr[mid])
                ub = mid-1;
            else
                lb = mid+1;
        }
        else {
            if(target<=arr[ub] && target>arr[mid])
                lb = mid+1;
            else    
                ub = mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<search(arr,0);
}
