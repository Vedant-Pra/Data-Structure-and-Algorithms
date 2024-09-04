#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    //int maxSum = 0; //concidering the subarray chosen can be empty
    int maxSum = INT_MIN; // Concidering atleast one element has to be taken
    int sum = 0;
    // int start = 0, end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        // maxSum = max(sum, maxSum);
        if(maxSum<sum){
            maxSum = sum;
            // end = i;
        }
        if (sum < 0)
        {
            sum = 0;
            // start = i+1;
        }
    }
    // cout<<start<<" "<<end<<endl;
    return maxSum;
}
int main(){
    // vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> arr = {-1,-2};
    cout<<maxSubArray(arr);
}