#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int> &arr, int target)
{
    int lb = 0;
    int ub = arr.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    if (lb >= arr.size())
        return -1;
    return lb;
}

int main()
{
    vector<int> arr = {1, 2, 8, 10, 11, 12, 19};
    cout << upperBound(arr, 9);
}