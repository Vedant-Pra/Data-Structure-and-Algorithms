//In chaining the hash table is made up of an array of linked lists.

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};
class HashTable
{
private:
    vector<Node*> vec;
    int size;

public:
    HashTable()
    {
        this->size = 10;
        vec = vector<Node *>(10, nullptr);
    }
    HashTable(int size)
    {
        this->size = size;
        vec = vector<Node *>(size, nullptr);
    }
    int hashFunction(int value)
    {
        return value % 10;
    }

    // We insert the elements as nodes of a linked list after getting the index from the hash function. Like 16%10 = 6 so element stored as a node at index 6. 
    void insert(int value)
    {
        int hashIndex = hashFunction(value);
        Node *node = new Node(value);
        Node *prev = nullptr;
        Node *head = vec[hashIndex];
        Node *cur = head;
        while (cur && cur->data < value)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur && cur->data == value)
        {
            return;
        }
        if (prev == nullptr)
        {
            node->next = head;
            vec[hashIndex] = node;
        }
        else
        {
            node->next = cur;
            prev->next = node;
        }
    }
    void remove(int value)
    {
        int hashIndex = hashFunction(value);
        Node *head = vec[hashIndex];
        Node *prev = nullptr;
        Node *cur = head;
        while (cur && cur->data != value)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            cout << "Value not found" << endl;
            return;
        }
        else if (prev == nullptr)
        {
            Node *temp = head;
            head = head->next;
            vec[hashIndex] = head;
            delete temp;
            temp = nullptr;
        }
        else
        {
            Node *temp = cur;
            temp->next = cur->next;
            delete temp;
            temp = nullptr;
        }
    }

    // For searching an element we get the index from the hash function and then go to that index and search the element in the linked list linearly.
    bool find(int value)
    {
        int hashIndex = hashFunction(value);
        Node *head = vec[hashIndex];
        Node *cur = head;
        while (cur && cur->data != value)
        {
            cur = cur->next;
        }
        if (cur == nullptr)
            return false;
        return true;
    }
    void print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << i << ": ";
            Node *cur = vec[i];
            while (cur)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable hash = HashTable(10);
    hash.insert(1);
    hash.insert(2);
    hash.insert(3);
    hash.insert(14);
    hash.insert(4);
    hash.insert(66);
    hash.insert(6);
    hash.insert(8);
    hash.insert(9);
    hash.insert(99);
    hash.insert(5);
    hash.print();
    cout<<hash.find(5)<<endl;
    hash.remove(2);
    hash.remove(4);
    hash.print();
    return 1;
}