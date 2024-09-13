//Capacity To Ship Packages Within D Days

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool calc(vector<int>&wt,int cap,int days){
        int count = 0;
        int i = 0;
        int sum = 0;
        while(i<wt.size()){
            while(i<wt.size() && sum+wt[i]<=cap){
                sum+=wt[i++];
            }
            count++;
            sum = 0;
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        int lb = *(max_element(wt.begin(),wt.end()));
        int ans = -1;
        int ub = accumulate(wt.begin(),wt.end(),0);
        while(lb<=ub){
            int mid = lb+(ub-lb)/2;
            bool canTake = calc(wt,mid,days);
            if(canTake){
                ans = mid;
                ub = mid-1;
            }
            else    
                lb = mid+1;
        }
        return ans;
    }
    int main(){
        vector<int> wt = {1,2,3,4,5,6,7,8,9,10};
        cout<<shipWithinDays(wt,5);
    }