//Nearset large in right

// Gotham has been attacked by Joker . Bruce Wayne has deployed automatic
// machine gun at each tower of Gotham.
// All the towers in Gotham are in straight line.
// You are given no of towers 'n' followed by height of 'n' towers.
// For every tower(p), find the height of the closest tower (towards the right),
// greater than the height of tower(p).
// Now , Print sum of all such heights (mod 1000000001).
//
// Note : If for a tower(k) , no such tower exsits then take its height as 0.

// Input:
// 1
// 9
// 112 133 161 311 122 512 1212 0 19212
//
// Output:
// 41265
//
// Explanation :
// nextgreater(112) : 133
// nextgreater(133) : 161
// nextgreater(161) : 311
// nextgreater(311) : 512
// nextgreater(122) : 512
// nextgreater(512) : 1212
// nextgreater(1212) : 19212
// nextgreater(0) : 19212
// nextgreater(19212) : 0
//
// add = 133+161+311+512+512+1212+19212+19212+0 = 41265.
//
// Expected Time complexity - O(n).

#include<bits/stdc++.h>
using namespace std;

int get(vector<int> &arr){
    long long ans = 0;
    stack<int> s;
    int n = arr.size();
    for(int i=n-1; i>=0; i--){
        while(!s.empty() && s.top() <= arr[i]){
            s.pop();
        }
        if(s.empty()){
            ans += 0;
        }else{
            ans += s.top();
        }
        s.push(arr[i]);
    }
    return ans%1000000001;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<get(arr)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
