#include<iostream>
#include<vector>
using namespace std;
int calcTime(vector<int> &piles, int k, int h)
{
    long long int time = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] % k == 0)
            time += piles[i] / k;
        else
            time += piles[i] / k + 1;
    }
    return time <= h;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int lb = 1;
    int ub = INT_MIN;
    for (auto it : piles)
        ub = max(it, ub);
    int ans = ub;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        int canEat = calcTime(piles, mid, h);
        if (canEat)
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
    vector<int> arr = {805306368,805306368,805306368};
    int h = 1000000000;
    cout<<minEatingSpeed(arr,h);
}