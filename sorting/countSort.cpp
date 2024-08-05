#include<bits/stdc++.h>
using namespace std;

// Helper Functions
void printArray(vector<int> &arr)
{
    for (auto &it : arr)
        cout << it << ' ';
    cout << endl;
}

int findMax(vector<int>& arr){
    int maxVal = INT_MIN;
    for(auto &it:arr){
        maxVal=max(maxVal,it);
    }
    return maxVal;
}

int findMin(vector<int>&arr){
    int minVal=INT_MAX;
    for(auto &it:arr){
        minVal=min(minVal,it);
    }
    return minVal;
}

//Count Sort function to sort an array contaning only positive numbers
void countSortOnlyPositiveNos(vector<int>& arr){
    int maxVal = findMax(arr);
    vector<int> count(maxVal+1,0);
    for(auto &it:arr){
        count[it]++;
    }
    int idx=0;
    for(int i=0;i<count.size();i++){
        while(count[i]>0){
            arr[idx++]=i;
            count[i]--;
        }
    }
}

//Count Sort function for an array contaningg both positive and negative numbers
void countSortPosAndNeg(vector<int>& arr){
    int maxVal = findMax(arr);
    int minVal = findMin(arr);
    int mask=-1*minVal;                 // Adding mask value to each number such that the after addition each value >= 0
    vector<int> count(maxVal+mask+1,0);
    for(auto &it:arr){
        count[it+mask]++;               // Adding mask value to each number such that the after addition each value >= 0
    }
    int idx=0;
    for(int i=0;i<count.size();i++){
        while(count[i]>0){
            arr[idx++]=i-mask;
            count[i]--;
        }
    }
}
int main(){
    vector<int> arr = {-24, 18, 38, 43, 14, -40, 1, 54};
    // vector<int> arr = {4, 1, 3, 9, 7};
    cout << "Before Sorting: ";
    printArray(arr);
    // countSortOnlyPositiveNos(arr);
    countSortPosAndNeg(arr);
    cout << endl
         << "After Sorting: ";
    printArray(arr);
}