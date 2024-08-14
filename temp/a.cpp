#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0;
    int j = 0;
    long long sum = 0;
    int maxLen = 0;
    while(j<a.size()){
        sum+=a[j];
        if(sum<k){
            j++;
            continue;
        }
        else if(sum==k){
            maxLen=max(maxLen,j-i+1);
            j++;

        }
        else{
            while(sum>k){
                sum-=a[i++];
            }
            if(sum==k)
                maxLen=max(maxLen,j-i+1);
            j++;
        }
    }
    return maxLen;
}
int main(){
    vector<int> a = {1, 2, 1, 3};
    cout<<longestSubarrayWithSumK(a,2);
}