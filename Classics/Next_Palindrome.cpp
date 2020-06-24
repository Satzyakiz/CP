// Given a number, in the form of an array a[] containing digits
// from 1 to 9(inclusive). The task is to find the next smallest
// palindrome larger than this number.
//
//
// Input:
// 2
// 11
// 9 4 1 8 7 9 7 8 3 2 2
// 3
// 9 9 9
//
// Output:
// 9 4 1 8 8 0 8 8 1 4 9
// 1 0 0 1

#include<bits/stdc++.h>
using namespace std;
bool all9(vector<int> &arr){
    for(int x: arr){
        if(x != 9)
            return false;
    }
    return true;
}
void helper(vector<int> &arr){
    int n = arr.size();
    int mid = n/2;
    int i = mid-1;
    int j = (n & 1) ? mid+1 : mid;
    bool leftSmaller = false;

    while(i >= 0 && arr[i] == arr[j]){
        i--, j++;
    }

    if(i<0 || arr[i] < arr[j])
        leftSmaller = true;

    while(i >= 0){
        arr[j] = arr[i];
        i--;
        j++;
    }

    if(leftSmaller){
        int carry = 1;
        i = mid-1;
        if(n & 1){
            arr[mid] += carry;
            carry = arr[mid] / 10;
            arr[mid] %= 10;
            j = mid+1;
        }else{
            j = mid;
        }

        while(i >= 0){
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] %= 10;
            arr[j] = arr[i];
            j++;
            i--;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    if(all9(arr)){
        cout<<"1 ";
        for(int i=1; i<n; i++) cout<<"0 ";
        cout<<"1\n";
        return;
    }
    helper(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

// LOGIC:
// 1) If all 9's, just return 100..01
// 2) If middle part values need not be changed:
//     i) if left part of middle element is greater than right part, just copy the
//     left part values in the right part, and we will get the required value.
//     Ex: 9335 => 9339, 643 => 646
//     ii) If left part is smaller, change the right part to smaller values, and
//     change the middle part.
// 3) If middle part needs to be changed:
//     i) Take a carry variable and continue to add it in the left part,
//     until all the part is traversed. Copy the subsequent left portion to the right.
//     Ex: 1338 => 1441, 1992 => 2002, 193 => 202
