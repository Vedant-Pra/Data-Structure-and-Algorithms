#include <bits/stdc++.h>
using namespace std;
int getLucky(string s, int k)
{
    int sum = 0;
    for (auto it : s)
    {
        int val = (int)it;
        while (val > 0)
        {
            sum = sum * 10 + val % 10;
            val = val / 10;
        }
    }
    int temp;
    while (k > 0)
    {
        temp = 0;
        while (sum > 0)
        {
            temp += k % 10;
            k = k / 10;
        }
        sum = temp;
        k--;
    }
    return sum;
}
int main()
{
    vector<int> a = {1, 2, 1, 3};
    cout << getLucky("iiii",2);
}