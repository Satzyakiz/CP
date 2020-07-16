// Given an array of positive numbers, the task is to find the number of
// possible contiguous subarrays having product less than a given number K.

// Input:
// 2
// 4 10
// 1 2 3 4
// 7 100
// 1 9 2 8 6 4 3
//
// Output:
// 7
// 16


#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    int n;
    ll k;
    cin>>n>>k;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = 0;
    int start = 0;
    ll p = 1;
    for(int end = 0; end < n; end++){
        p *= arr[end];
        while(p >= k){
            p /= arr[start++];
        }
        ans += end-start+1;
    }
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
