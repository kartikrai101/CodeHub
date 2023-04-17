#include<bits/stdc++.h>
using namespace std;

class DoubleStack{
    public:
        int* arr1;
        int top1;
        int size1;
        int* arr2;
        int top2;
        int size2;

    DoubleStack(int size){
        this -> size1 = size;
        this -> top1 = -1;
        this -> arr1 = new int[size];
        this -> size2 = size;
        this -> top2 = -1;
        this -> arr2 = new int[size];
    }

    void push1(int value){
        if(size1-top1 > 1){
            top1++;
            arr1[top1] = value;
        }else{
            cout << "Stack Overflow!" << endl;
        }
    }
    void push2(int value){
        if(size2-top2 > 1){
            top2++;
            arr2[top2] = value;
        }else{
            cout << "Stack Overflow!" << endl;
        }
    }

    void pop1(){
        if(top1 >= 0){
            top1--;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }
    void pop2(){
        if(top2 >= 0){
            top2--;
        }else{
            cout << "Stack Underflow" << endl;
        }
    }

    void peek1(){
        if(top1 >= 0){
            cout << arr1[top1] << endl;
        }else{
            cout << "Stack1 Underflow!" << endl;
        }
    }
    void peek2(){
        if(top2 >= 0){
            cout << arr2[top2] << endl;
        }else{
            cout << "Stack2 Underflow!" << endl;
        }
    }
};

int main(){
    DoubleStack dst(10);

    dst.push1(100);
    dst.push2(213);

    dst.push1(187);
    dst.push2(256);

    dst.push2(289);

    dst.peek1();
    dst.peek2();
    cout << endl;
    dst.pop1();
    dst.pop2();

    dst.peek1();
    dst.peek2();

    return 0;
}