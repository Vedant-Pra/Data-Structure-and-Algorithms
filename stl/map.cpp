#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    map<int,string> mpp;
    
    // 1. Insertion
    mpp.insert(pair<int,string>(1,"One"));
    mpp[2]="Two";

    //2. Access
    cout<<mpp[2]<<endl;

    //3. Search:
    auto p = mpp.find(1);   //Return an iterator to the element if found else map.end()
    if(p!=mpp.end()){
        cout<<p->first<<"->"<<p->second<<endl;  // We need to dereference the iterator using -> to access its elements.
    }

    //4. Delete
    mpp.erase(1);
    for(auto it: mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    cout<<endl;




    map<int,int> mp;
    vector<int> arr = {1,3,4,6,6,3,342523,624,5,342,534,6,57,545,2,43,5,2};
    for(auto it: arr){
        mp[it]++;
    }
    // for(auto it:mp){
    //     cout<<it.first<<"->"<<it.second<<endl;
    // }
    
}