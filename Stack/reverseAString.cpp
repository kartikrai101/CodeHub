#include<bits/stdc++.h>
#include<stack>
using namespace std;

// creation of a stack datatype
class Stack{
    public: 
        int* arr;
        int top;
        int size;

    Stack(int size){
        this -> size = size;
        this -> top = -1;
        this -> arr = new int[size];
    }

    void push(int value){
        if(size - top > 1){
            top++;
            arr[top] = value;
        }else{
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }else{
            cout << "Stack is Empty!" << endl;
            return -1;
        }

        return -1;
    }
};

void removeMiddleElement(stack<int> &st, int count, int size){
    // base case
    if(count == size/2){
        st.pop();
        return;
    }

    int top = st.top();

    st.pop();

    removeMiddleElement(st, count+1, size);

    st.push(top);
}

int main(){
    stack<int> st;

    for(int i=1; i<10; i++){
        st.push(i);
    }

    removeMiddleElement(st, 0, 9);

    while(!st.empty()){
        cout << st.top() << " ";

        st.pop();
    }

    return 0;
}