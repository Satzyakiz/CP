// Given an array with n distinct elements, convert the given array 
// to a reduced form where all elements are in range from 0 to n-1.
// The order of elements is same, i.e., 0 is placed in place of smallest
// element, 1 is placed for second smallest element, … n-1 is placed
// for largest element.
//
// Input:
// 2
// 3
// 10 40 20
// 5
// 5 10 40 30 20
//
// Output:
// 0 2 1
// 0 1 4 3 2

#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int,int> um;
    int i = 0;
    for(int i=0; i<n; i++) cin>>arr[i];
    vector<int> temp(arr.begin(),arr.end());
    sort(arr.begin(),arr.end());
    for(int &x: arr){
        if(um.find(x) == um.end())
            um[x] = i++;
    }
    for(int i=0; i<n; i++){
        int x = temp[i];
        cout<<um[x]<<" ";
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
