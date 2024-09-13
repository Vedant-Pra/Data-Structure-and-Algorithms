#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool calc(vector<int> &bloomDay, int m, int k, int day)
{
    // int count = 0;
    int i = 0;
    while (i < bloomDay.size())
    {
        int count = 0;
        if (bloomDay[i] <= day)
        {
            while (i < bloomDay.size() && bloomDay[i] <= day)
            {
                count++;
                i++;
            }
        }
        else
        {
            i++;
        }
        m = m - (count / k);
    }
    return m <= 0;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int lb = 1;
    int ub = *(max_element(bloomDay.begin(), bloomDay.end()));
    int ans = -1;
    if (bloomDay.size() / m < k)
        return -1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        bool canMake = calc(bloomDay, m, k, mid);
        if (canMake)
        {
            ans = mid;
            ub = mid - 1;
        }
        else
            lb = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    cout<<minDays(bloomDay,3,1);
}