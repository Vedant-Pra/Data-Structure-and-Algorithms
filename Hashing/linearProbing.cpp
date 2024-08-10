#include<bits/stdc++.h>
using namespace std;
class HashTable{
    public:
    vector<int> vec;
    int size;
    HashTable(){
        this->size = 10;
        vec = vector<int>(10,INT_MIN);
    }
    HashTable(int size){
        this->size = size;
        vec = vector<int>(size,INT_MIN);
    }
    int hashFunction(int value){
        return value%this->size;
    }
    void insert(int value){
        int hashIndex = hashFunction(value);
        if(vec[hashIndex]==INT_MIN){
            vec[hashIndex]=value;
            return;
        }
        int index = (hashIndex+1)%this->size;
        while(index!=hashIndex){
            if(vec[index]==INT_MIN){
                vec[index]=value;
                return;
            }
            index = (index+1)%this->size;
        }
        cout<<"Hash Table full. Cannot insert values. "<<endl;
    }
    int search(int value){
        int hashIndex = hashFunction(value);
        if(vec[hashIndex]==value)
            return hashIndex;
        int index = (hashIndex+1)%this->size;
        while(index!=hashIndex && vec[index] != INT_MIN){
            if(vec[index]==value)
                return index;
            index = (index+1)%this->size;
        }
        cout<<"Value not found."<<endl;
        return -1;

    }
    void remove(int value){
        int index = search(value);
        if(index==-1){
            return;
        }
        vec[index]=INT_MIN;
    }
    void print(){
        for(int i=0;i<this->size;i++){
            cout<<i<<": "<<vec[i]<<endl;
        }
        cout<<endl;
    }
};

int main(){
    HashTable hash(10);
    hash.insert(2);
    hash.insert(22);
    hash.insert(1);
    hash.insert(11);
    hash.insert(0);
    hash.insert(9);
    hash.insert(56);
    hash.insert(74);
    hash.insert(77);
    hash.insert(3);
    hash.insert(8828);
    hash.print();
    cout<<hash.search(22)<<endl;
    hash.remove(10);
    hash.print();
}

