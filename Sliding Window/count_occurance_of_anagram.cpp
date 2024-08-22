#include <iostream>
#include <unordered_map>
using namespace std;
	int search(string pat, string txt)
{
    // code here
    unordered_map<char, int> mp;
    for (auto it : pat)
        mp[it]++;
    int count = 0;
    int i = 0, j = 0;
    while (j < txt.size())
    {
        mp[txt[j]]--;
        if (mp[txt[j]] == 0)
            mp.erase(txt[j]);
        int size = j - i + 1;
        if (size < pat.size())
            j++;
        else
        {
            if (mp.size() == 0)
                count++;
            mp[txt[i]]++;
            if(mp[txt[i]]==0)
                mp.erase(txt[i]);
            i++;
            j++;
        }
    }
    return count;
}
int main(){
    string txt = "forxxorfxdofr";
    string pat = "for";
    cout<<search(pat,txt);
}