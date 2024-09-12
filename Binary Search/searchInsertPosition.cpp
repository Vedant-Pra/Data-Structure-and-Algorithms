#include<iostream>
#include<vector>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int lb = 0;
    int ub = nums.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    return lb;
}
int main(){
    vector<int> nums = {1,3,5,6};
    cout<<searchInsert(nums,2);
}