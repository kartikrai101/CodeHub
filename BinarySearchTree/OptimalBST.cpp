// wap to implement Optimal Binary Search Tree and analyze its time complexity
#include<bits/stdc++.h>
using namespace std;

// What is an optimal BST?
// So, if you have a set of nodes and a frequency of searches of every individual node
// then the BST that has a minimum total cost is called an optimal BST

int getSum(int arr[], int start, int end){
    int ans=0;
    for(int i = start; i<= end; i++){
        ans += arr[i];
    }

    return ans;
}

int optCost(int freq[], int start, int end){
    // base case
    if(start > end)
        return 0;
    if(start == end)
        return freq[start];

    // get sum of freq[start] to freq[end]
    int fsum = getSum(freq, start, end);

    int mini = INT_MAX;

    for(int i=start; i<=end; i++){
        int cost = optCost(freq, start, i-1) + optCost(freq, i+1, end);

        if(cost < mini)
            mini = cost;
    }

    return mini+fsum;
}

int OptimalBST(int keys[], int freq[], int n){
    // make each node a root node one by one and calculate the total cost
    return optCost(freq, 0, n-1);
}

int main(){
    int keys[] = {10, 12, 20}; // we assume that the keys are arranged in sorted order, so if the keys array is not sorted already, you need to sort it first
    int freq[] = {34, 8, 50};

    int n = sizeof(keys)/sizeof(keys[0]);

    cout << "The cost for Optimal Binary Search Tree is: " << OptimalBST(keys, freq, n) << endl;

    return 0;
}