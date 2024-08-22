#include <iostream>
#include<vector>
#include<deque>
using namespace std;
vector<int> sliding_window_maximum(vector<int> arr, int n, int k)
{
    int i = 0;
    int j = 0;
    vector<int> ans;
    deque<int> dq;
    while (j < n)
    {
        while (!dq.empty() && dq.back() < arr[j])
            dq.pop_back();
        dq.push_back(arr[j]);
        int size = j - i + 1;
        if (size < k)
            j++;
        else
        {
            ans.push_back(dq.front());
            if (dq.front() == arr[i])
                dq.pop_front();
            i++;
            j++;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
    int n = 9;
    int k = 3;
    vector<int> ans = sliding_window_maximum(arr,n,k);
    for(auto it:ans)
        cout<<it<<" ";
}