#include <iostream>
#include <unordered_map>
using namespace std;
int longestKSubstr(string s, int k)
{
    // your code
    unordered_map<char, int> mp;
    int maxLen = -1;
    int i = 0, j = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp.size() < k)
            j++;
        else if (mp.size() == k)
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxLen;
}
int main(){
    string str = "aabacbebebe";
    int k = 3;
    cout<<longestKSubstr(str,k);
}