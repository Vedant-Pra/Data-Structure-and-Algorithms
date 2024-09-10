#include <iostream>
#include <vector>
using namespace std;
int search(vector<int> &nums, int target)
{
    int lb = 0, ub = nums.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << search(arr, 7) << endl;
    cout << search(arr, 21) << endl;
}