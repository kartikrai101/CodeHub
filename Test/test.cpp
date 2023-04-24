#include<bits/stdc++.h>
using namespace std;

long long int maximumBeauty(int n, vector<long long> arr){
    //return the maximum beauty that she can get
    if(n == 2){
        return arr[0]*arr[1];
    }

    if(n == 3){
        // either the multiple of 1&2, or the multiple of 2&3 or 1,3
        return max(arr[0]*arr[1], max(arr[1]*arr[2], arr[0]*arr[2]));
    }

    sort(arr.begin(), arr.end());
    //cout << arr[0] << " " << arr[n-1] << endl;
    return max(arr[0]*arr[1], arr[n-1]*arr[n-2]);
}

long long bunLover(long long n){
    // using the relation : n*4 + n(n-2) + 2
    long long ans = n*4 + n*(n-2) + 2;
    return ans;
}

// Function for swapping two numbers
void swap(int& x, int& y)
{
   int temp = x;
   x = y;
   y = temp;
}

// Function to find the all possible permutations
void permutations(vector<vector<int> >& res,
            vector<int> nums, int l, int h)
{
   // Base case
   // Add the vector to result and return
   if (l == h) {
      res.push_back(nums);
      return;
   }

   // Permutations made
   for (int i = l; i <= h; i++) {

      // Swapping
      swap(nums[l], nums[i]);

      // Calling permutations for
      // next greater value of l
      permutations(res, nums, l + 1, h);

      // Backtracking
      swap(nums[l], nums[i]);
   }
}

vector<vector<int> > permute(vector<int>& nums)
{
   // Declaring result variable
   vector<vector<int> > res;
   int x = nums.size() - 1;

   // Calling permutations for the first
   // time by passing l
   // as 0 and h = nums.size()-1
   permutations(res, nums, 0, x);
   return res;
}

vector<int> superPermutation(int n, vector<int> permutation){

}

int main(){
    int q;
    cin >> q;
    while(q--){
        int n; cin >> n;
        string s; cin >> s;

        cout << requiredSwaps(n, s) << endl;
    }

    return 0;
}

// int n; cin >> n;
//         vector<int> nums(n);
//         for(int i =0; i< n; i++){
//             nums[i] = i+1;
//         }
//         vector<vector<int> > res = permute(nums);

//         //res contains all the permutations of numbers up to n
//         // now for every permutation, find the corresponding super permutation
//         vector<int> super = superPermutation(n, nums);