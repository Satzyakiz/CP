
// Given an array containing N integers and an integer K. 
// Your task is to find the length of the longest Sub-Array with sum
// of the elements equal to the given value K.
//
// Input:
// 3
// 6 15
// 10 5 2 7 1 9
// 6 -5
// -5 8 -14 2 4 12
// 3 6
// -1 2 3
// Output:
// 4
// 5
// 0

#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int> &arr,int k){
    int i=0,ans = 0;
    int sum = 0;
    unordered_map<int,int> um;
    for(int j=0; j<arr.size(); j++){
        sum += arr[j];
        if(sum == k){
            ans = j+1;
        }
        if(um.find(sum - k) != um.end()){
            ans = max(j-um[sum-k], ans);
        }
        if(um.find(sum) == um.end()){
            um[sum] = j;
        }
    }
    return ans;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<atMost(arr,k)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
