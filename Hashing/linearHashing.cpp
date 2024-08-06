// This is a simple hash function where we define the size of the hash table.
// Assumtion all values are unique and in the range 0 - size of hash -1.

#include<bits/stdc++.h>
using namespace std;
class Hash{
    private:
        vector<int> arr;
        int size;
    public:
    Hash(int size){
        arr = vector<int>(size,INT_MIN);
        this->size = size;
    }
    int hashFunction(int val){
        int index = val%this->size;
        return index;
    }
    void insert(int val){
        int index = hashFunction(val);
        if(this->arr[index] != INT_MIN){
            cout<<"Index not free"<<endl;
            return;
        }
        else{
            this->arr[index] = val;
        }
    }
    void remove(int val){
        int index = hashFunction(val);
        if(this->arr[index]==INT_MIN){
            cout<<"Element not present"<<endl;
        }
        else{
            this->arr[index]=INT_MIN;
        }
    }
    bool search(int val){
        int index = hashFunction(val);
        if(this->arr[index]==INT_MIN)
            return false;
        if(arr[index]==val)
            return true;
        return false;
    }
    void display(){
        for(int i = 0;i<this->arr.size();i++){
            cout<<i<<" : "<<this->arr[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    Hash h(20);
    h.insert(5);
    h.insert(1);
    h.insert(9);
    h.insert(10);
    h.insert(3);
    h.insert(7);
    h.insert(4);
    h.display();
    cout<<h.search(10)<<endl;
    cout<<h.search(2)<<endl;
    h.remove(10);
    h.display();

}