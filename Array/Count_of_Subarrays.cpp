// Given an array of N positive integers  a1, a2 ............ an. 
// The value of each contiguous subarray of given array is the maximum
// element present in that subarray. The task is to return the number of
// subarrays having value strictly greater than K.
//
// Example:
// Input:
// 2
// 3 2
// 3 2 1
// 4 1
// 1 2 3 4
//
// Output:
// 3
// 9

#include<bits/stdc++.h>
using namespace std;

int get(vector<int> &arr, int k){
    int n = arr.size();
    int total = (n*(n+1))/2;
    int count = 0, totalImp = 0;
    for(int &x: arr){
        if(x <= k){
            count++;
        }else{
            totalImp += (count*(count+1))/2;
            count = 0;
        }
    }
    totalImp += (count*(count+1))/2;
    return total - totalImp;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<get(arr,k)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
