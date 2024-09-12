#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int> &nums, int target)
{
    int lb = 0;
    int ub = nums.size() - 1;
    while (lb <= ub)
    {
        while (lb <= ub && nums[lb] == nums[ub])
            ub--;
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] == target)
            return true;
        else if (nums[lb] <= nums[mid])
        {
            if (target >= nums[lb] && target < nums[mid])
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        else
        {
            if (target <= nums[ub] && target > nums[mid])
                lb = mid + 1;
            else
                ub = mid - 1;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {4,5,6,6,7,0,1,2,4,4};
    cout<<search(arr,7);
}