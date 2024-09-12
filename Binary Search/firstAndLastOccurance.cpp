#include<iostream>
#include<vector>
using namespace std;
int findIndex(vector<int> &nums, int target, bool first)
{
    int lb = 0;
    int ub = nums.size() - 1;
    int ans = -1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            if (first)
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        else if (nums[mid] > target)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int firstOcc = findIndex(nums, target, true);
    int lastOcc = findIndex(nums, target, false);
    return {firstOcc, lastOcc};
}
int main(){
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> ans = searchRange(arr,8);
    for(auto it:ans)
        cout<<it<<" ";
}