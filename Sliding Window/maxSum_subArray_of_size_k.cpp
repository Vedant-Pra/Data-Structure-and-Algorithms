// Given an array of integers Arr of size N and a number K. Return the maximum sum of a subarray of size K.
#include <iostream>
#include <vector>
using namespace std;
int maxSubarray(int k, vector<int> &arr, int n)
{
    // code here
    int i = 0;
    int j = 0;
    int sum = 0;
    int maxSum = 0;
    while (j < arr.size())
    {
        sum += arr[j];
        int size = j - i + 1;
        if (size < k)
        {
            j++;
        }
        else if (size == k)
        {
            maxSum = max(maxSum, sum);
            sum -= arr[i++];
            j++;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> arr =  {100, 200, 300, 400};
    int k = 2;
    cout << "Max sum Subarray of size K: " << maxSubarray(k, arr, arr.size());
}
