#include <iostream>
#include <vector>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    if (k < arr[0])
        return k;
    if (arr[arr.size() - 1] - arr.size() < k)
        return arr[arr.size() - 1] + (k - (arr[arr.size() - 1] - arr.size()));
    int lb = 0;
    int ub = arr.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        int totalMissing = arr[mid] - (mid + 1);
        if (totalMissing >= k)
        {
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    int totalMissing = arr[ub] - ub - 1;
    // cout<<arr[ub]<<" "<<totalMissing;
    return arr[ub] + (k - totalMissing);
}
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    cout << findKthPositive(arr, 5);
}