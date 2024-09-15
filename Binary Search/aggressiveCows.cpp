#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

bool calc(vector<int> &stalls, int cows, int diff)
{
    int count = 1;
    int cur = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - cur >= diff)
        {
            count++;
            cur = stalls[i];
        }
        if (count >= cows)
            return true;
    }
    return false;
}

int solve(int n, int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());  
    int lb = 1;
    int ub = stalls[stalls.size() - 1];
    int ans = -1;
    
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        bool isPossible = calc(stalls, k, mid);
        if (isPossible)
        {
            ans = mid;
            lb = mid + 1;
        }
        else
            ub = mid - 1;
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int n = stalls.size();
    int k = 3;  
    cout << "Maximum minimum distance: " << solve(n, k, stalls) << endl;
    return 0;
}
