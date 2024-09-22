#include<iostream>
#include<climits>
using namespace std;
class Node{
    public:
        int data;
        Node* prev;
        Node* next;
        Node(){
            this->data = INT_MIN;
            this->prev = nullptr;
            this->next = nullptr;
        }
        Node(int val){
            this->data = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
};

class DoublyLinkedList{
    private:
        Node* head;
    public:
        DoublyLinkedList(){
            head = nullptr;
        }
        void insertAtHead(int val){
            Node* newNode = new Node(val);
            if(!head){
                head = newNode;
                return;
            }
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            Node* prev = nullptr;
            Node* cur = head;
            while(cur){
                prev = cur;
                cur = cur->next;
            }
            if(prev){
                prev->next = newNode;
                newNode->prev = prev;
            }
            else{
                head = newNode;
            }
        }
        void display(){
            Node* cur = head;
            while(cur){
                cout<<cur->data<<' ';
                cur = cur->next;
            }
            cout<<endl;
        }
        void deleteNode(int val){
            Node* cur = head;
            Node* prev = nullptr;
            while(cur && cur->data != val){
                prev = cur;
                cur = cur->next;
            }
            if(!cur){
                cout<<"Node not found."<<endl;
                return;
            }
            if(prev){
                prev->next = cur->next;
                if(cur->next)
                    cur->next->prev = prev;
                delete cur;
                cur = nullptr;
            }
            else{
                head = head->next;
                if(cur->next)
                    cur->next->prev = nullptr;
                delete cur;
                cur = nullptr;
            }
        }
};

int main(){
    DoublyLinkedList dl;
    dl.insertAtHead(5);
    dl.insertAtHead(10);
    dl.insertAtEnd(15);
    dl.insertAtHead(1);
    dl.display();
    dl.deleteNode(1);
    dl.display();
}