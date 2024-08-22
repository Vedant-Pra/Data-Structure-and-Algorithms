#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) 
{
    vector<long long> ans;
    queue<long long> q;
    long long int i = 0;
    long long int j = 0;
    while(j<N){
        if(A[j]<0)
            q.push(A[j]);
        long long int size = j-i+1;
        if(size<K){
            j++;
        }
        else{
            if(q.size()==0){
                ans.push_back(0);
                i++;
                j++;
            }
                
            else{
                ans.push_back(q.front());
                if(q.front()==A[i])
                    q.pop();
                i++;
                j++;
            }
        }
    }
    return ans;
}
int main(){
    long long int A[] = {12, -1, -7, 8, -15, 30, 16, 28};
    long long int N = 8;
    long long int K = 3;
    vector<long long> ans = printFirstNegativeInteger(A,N,K);
    for(auto it:ans)
        cout<<it<<" ";
}