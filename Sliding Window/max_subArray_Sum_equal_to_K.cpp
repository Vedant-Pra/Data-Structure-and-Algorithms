#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> lenOfLongSubarr(vector<int> A,int N, int K)
{
    int sum = 0;
    unordered_map<int, int> mp;
    int maxLen = 0;
    int start = -1;
    int end = -1;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (sum == K){
            maxLen = i + 1;
            start = 0;
            end = i;
        }
        else
        {
            int diff = sum-K;
            if (mp.find(diff) != mp.end()){
                if(maxLen<i-mp[diff]){
                    maxLen = i-mp[diff];
                    start = mp[diff]+1;
                    end = i;
                }
            }
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return {maxLen,start,end};
}

int main(){
    vector<int> arr = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    // cout<<lenOfLongSubarr(arr,17,42);
    vector<int> ans;
    ans = lenOfLongSubarr(arr,17,42);
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
    
}