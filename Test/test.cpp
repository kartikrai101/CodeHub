#include<bits/stdc++.h>
using namespace std;

// int solve1(string str){
//     if(str[0] == '0'){
//         return 0;
//     }

//     int n = str.length();
//     int ans=1;
//     int count = 0;
//     for(int i=0; i<n; i++){
//         if(str[i] == '?'){
//             count++;
//         }
//     }

//     if(str[0] == '?'){
//         ans = pow(10, count-1) * 9;
//     }else{
//         ans = pow(10, count);
//     }

//     return ans;
// }

// pair<int, int> solve2(int n, int arr1[], int arr2[]){
//     int ptr1=0;
//     int ptr2 =0;

//     pair<int, int> ans = make_pair(0, 0);
//     int maxi=0;
//     int count = 0;
//     while(ptr2 < n){
//         if(arr1[ptr1] == arr2[ptr1]){
//             count = 0;
//             ptr1++; ptr2++;
//         }else{
//             ptr2 = ptr1;
//             while(arr1[ptr2] != arr2[ptr2]){
//                 count++;
//                 ptr2++;
//             }
//             while(arr2[ptr2] >= arr2[ptr2-1]){
//                 count++;
//                 ptr2++;
//             }
//             if(count > maxi){
//                 maxi = count;
//                 ans.first = ptr1;
//                 ans.second = ptr2-1;
//             }
//         }
//         ptr1 = ptr2;
//     }

//     return ans;
// }

pair<int, int> solve3(int n, int arr1[], int arr2[]){
    int count =0;
    int maxi = 0;

    int p1 = 0; int p2 = 0;
    pair<int, int> ans = make_pair(0, 0);

    while(p2 < n-1){
        p1 = p2;
        count = 0;
        while(arr2[p2] <= arr2[p2+1]){
            count++;
            p2++;
        }
        if(count > maxi){
            maxi=count;
            ans.first = p1;
            ans.second = p2;
        }
        p2++;
    }

    return ans;
}

pair<int, int> solve4(int n, int arr1[], int arr2[]){
    int p1 = -1;
    int p2 = -1;
    int mini = INT_MAX; int maxi = INT_MIN;

    pair<int, int> ans = make_pair(0, 0);

    for(int i=0; i< n; i++){
        if(arr1[i] != arr2[i]){
            p1 = i;
            break;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(arr1[i] != arr2[i]){
            p2 = i;
            break;
        }
    }

    for(int i=p1; i<=p2; i++){
        maxi = max(maxi, arr1[i]);
        mini = min(mini, arr1[i]);
    }

    if(p1 > 0){
        for(int i=p1-1; i>=0; i--){
            if(arr1[i] <= mini){
                p1--;
                mini = arr1[i];
            }else{
                break;
            }
        }
    }

    if(p2 < n-1){
        for(int i=p2+1; i<n; i++){
            if(arr1[i] >= maxi){
                p2++;
                maxi = arr1[i];
            }else{
                break;
            }
        }
    }

    ans.first = p1+1;
    ans.second = p2+1;

    return ans;
}

// i think you need to find the biggest sorted chunk in the second array

int main(){
    int t; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        int arr1[n]; int arr2[n];
        for(int i=0; i< n; i++){
            int d; cin >> d;
            arr1[i] = d;
        }
        for(int i=0; i< n; i++){
            int d; cin >> d;
            arr2[i] = d;
        }

        // the arrays have zero base indexing
        pair<int, int> p;
        p = solve4(n, arr1, arr2);

        cout << p.first << " " << p.second << endl;
    }

    return 0;
}