#include <iostream>
#include<vector>
#include <chrono>
using namespace std::chrono;
using namespace std;

class StackByArray{

    public:
        int size;
        vector<int> stack;
        int top = -1;

    public:
    void push(int value){
        if(this->top == this->size-1){
            cout << "STACK OVERFLOW" << endl;
        }else{
            this->top++;
            this->stack.push_back(value);
        }
    }

    int pop(){
        if(this->top == -1){
            cout << "STACK UNDERFLOW" << endl;
        }else{
            this->top--;
            int value = this->stack[this->top+1];
            stack.erase(stack.end());
            return value;
        }
    }

    bool isEmpty(){
        if(this->top == -1){
            return true;
        }else{
            return false;
        }
    }

    bool isFull(){
        if(this->top == this->size-1){
            return true;
        }else{
            return false;
        }
    }

    int stackTop(){
        if(this->top == -1){
            cout << "EMPTY STACK" << endl;
        }else{
            return this->stack[this->top];
        }
    }

    void display(){
        for(int i=0; i<=top; i++){
            cout << this->stack[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    StackByArray s;
    s.size = 10;
    auto start = high_resolution_clock::now();
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
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken = " << duration.count() << "microseconds" << endl;
}
