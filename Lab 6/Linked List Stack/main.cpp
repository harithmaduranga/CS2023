#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

class Node{

public:
    int data;
    Node* next;

};

class StackByLinkedList{

    public:
        int size;
        Node* head;

    public:
    void push(int value){
        Node n;
        n.data = value;
        if(head != NULL){
            n.next = head;
        }
        head = &n;
        cout << head->data << endl;
    }

    int pop(){
        if(head == NULL){
            cout << "STACK UNDERFLOW" << endl;
        }else{
            int value = head->data;
            head = head->next;
            return value;
        }
    }

    bool isEmpty(){
        if(head == NULL){
           return true;
        }else{
            return false;
        }
    }

    int stackTop(){
        Node temp;
        temp = *(head->next);
        while(temp.next != NULL){
              temp = *(temp.next);
        }
        return temp.data;
    }

    void display(){
        Node* temp;
        temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main()
{
    StackByLinkedList s;
    s.size = 10;
    auto start = high_resolution_clock::now();
    for(int i=0; i<1; i++){
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    //s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    //s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    //s.display();
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken = " << duration.count() << "microseconds" << endl;
}
