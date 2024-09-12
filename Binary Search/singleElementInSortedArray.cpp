#include<iostream>
#include<vector>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums[nums.size() - 1] != nums[nums.size() - 2])
        return nums[nums.size() - 1];
    if (nums[0] != nums[1])
        return nums[0];
    int lb = 1;
    int ub = nums.size() - 2;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid & 1 == 1)
        {
            if (nums[mid + 1] == nums[mid])
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        else
        {
            if (nums[mid + 1] == nums[mid])
                lb = mid + 1;
            else
                ub = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {3,3,7,7,10,11,11};
    cout<<singleNonDuplicate(arr);
}