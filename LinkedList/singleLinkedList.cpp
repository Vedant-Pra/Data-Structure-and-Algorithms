#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

        Node(int val){
            this->data=val;
            this->next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void insertAtEnd(int val){
            Node* newNode = new Node(val);
            // Node newNode = Node(val);
            Node* cur = head;
            Node* prev = nullptr;
            while(cur){
                prev=cur;
                cur = cur->next;
            }
            if(prev){
                prev->next = newNode;
            }
            else
                head = newNode;
        }
        void insertAtHead(int val){
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        void print(){
            Node* cur = head;
            while(cur){
                cout<<cur->data<<' ';
                cur = cur->next;
            }
            cout<<endl;
        }
        void deleteNodeVal(int val){
            Node* prev = nullptr;
            Node* cur = head;
            while(cur && cur->data!=val){
                prev = cur;
                cur = cur->next;
            }
            if(!cur){
                cout<<"Node not found."<<endl;
                return;
            }
            if(prev){
                prev->next = cur->next;
                delete cur;
                cur = nullptr;  // Set the pointer to nullptr after deletion for safety and preventing dangiling
                cout<<"Node deleted."<<endl;
            }
            else{
                Node* temp = head;
                head = head->next;
                delete temp;
                temp = nullptr;
                cout<<"Node deleted."<<endl;
            }
        }
        void reverseList() {
            Node* cur = head;
            Node* prev = nullptr;
            while(cur){
                Node* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            head = prev;
        }
        int length(){
            int count = 0;
            Node* cur = head;
            while(cur){
                count++;
                cur = cur->next;
            }
            return count;
        }
        bool searchNode(int val){
            Node* cur = head;
            while(cur){
                if(cur->data==val)
                    return true;
                cur = cur->next;
            }
            return false;
        }
};

int main(){
    LinkedList ll = LinkedList();
    ll.insertAtHead(1);
    ll.insertAtHead(2);
    ll.insertAtEnd(3);
    ll.insertAtEnd(4);
    ll.print();
    ll.deleteNodeVal(1);
    ll.print();
    cout<<ll.length()<<endl;
    cout<<ll.searchNode(10)<<endl;
    ll.reverseList();
    ll.print();

}