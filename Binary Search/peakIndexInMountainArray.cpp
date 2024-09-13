#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int> &nums)
{
    if (nums.size() == 1)
        return 0;
    if (nums[0] > nums[1])
        return 0;
    if (nums[nums.size() - 1] > nums[nums.size() - 2])
        return nums.size() - 1;
    int lb = 1;
    int ub = nums.size() - 2;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        if (nums[mid] < nums[mid + 1])
            lb = mid + 1;
        else
            ub = mid;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 1};
    cout << findPeakElement(arr);
}