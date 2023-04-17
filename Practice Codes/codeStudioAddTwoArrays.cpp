#include<bits/stdc++.h>
using namespace std;

void addArrays(vector<int> &first, vector<int> &sec){
    vector <int> third;

    int num1=0, num2=0;
    int p=0, q=0;

    for(int i = first.size()-1; i>=0; i--){
        num1 += first[i] * pow(10, p);
        p++;
    }
    for(int i = sec.size()-1; i>=0; i--){
        num2 += sec[i] * pow(10, q);
        q++;
    }

    int num3 = num1+num2;

    while(num3>0){
        int temp = num3%10;
        num3 = num3/10;
        third.push_back(temp);
    }

    vector<int> fourth;
    for(int i = third.size()-1; i>=0; i--){
        fourth.push_back(third[i]);
    }

    for(int i= 0; i<fourth.size(); i++){
        cout<<fourth[i];
    }
}

int main(){
    vector<int> arr1;
    arr1.push_back(1);arr1.push_back(2);arr1.push_back(3);arr1.push_back(4);arr1.push_back(5);
    vector<int> arr2;
    arr2.push_back(6);arr2.push_back(7); arr2.push_back(8);arr2.push_back(9);

    addArrays(arr1, arr2);

    return 0;
}