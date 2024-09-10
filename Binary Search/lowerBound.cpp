#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> &arr, int target)
{
    int lb = 0;
    int ub = arr.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    return ub;
}
int main()
{
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    cout << lowerBound(arr, 100);
}