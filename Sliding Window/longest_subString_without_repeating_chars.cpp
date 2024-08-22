#include <iostream>
#include <unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> mp;
    int maxLen = 0;
    int i = 0, j = 0;
    while (j < s.size())
    {
        mp[s[j]]++;
        if (mp[s[j]] > 1)
        {
            while (mp[s[j]] > 1)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
        else
        {
            maxLen = max(maxLen, j - i + 1);
            j++;
        }
    }
    return maxLen;
}

int main(){
    string str = "abcabcbb";
    cout<<lengthOfLongestSubstring(str);
}