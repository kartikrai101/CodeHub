#include<bits/stdc++.h>
using namespace std;

class Stack{
    // building a stack using array
    public:
        int* arr;
        int top;
        int size;
    
    Stack(int size){
        this -> size = size;
        this -> arr = new int[size]; // creating a dynamic array for the stack
        this -> top = -1; // initializing the top pointer with -1
    }

    // member functions of the stack class
    void push(int value){    // push function
        if(size - top >= 1){
            top++;
            arr[top] = value;
        }
        else{
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout << "Stack Underflow!" << endl;
        }
    }

    int peek(){
        if(top != -1){
            return arr[top];
        }
        cout << "Stack is empty!" << endl;
        return -1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};

int main(){
    Stack st(10);

    st.push(21);
    st.push(100);
    st.push(148);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    if(st.isEmpty()){
        cout << "Stack is empty" << endl;
    }else{
        cout << "Stack is not empty yet!" << endl;
    }
}