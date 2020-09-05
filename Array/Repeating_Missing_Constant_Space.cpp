// Given an unsorted array of size N of positive integers. One number 'A' 
// from set {1, 2, …N} is missing and one number 'B' occurs twice in array.
// Find these two numbers.
//
// Note: If you find multiple answers then print the Smallest number found.
// Also, expected solution is O(n) time and constant extra space.
//
// Input:
// 2
// 2
// 2 2
// 3
// 1 3 3
//
// Output:
// 2 1
// 3 2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int repeating, missing;
    for(int &x: arr){
        if(arr[abs(x)-1] < 0){
            repeating = abs(x);
        }else
            arr[abs(x)-1] = -arr[abs(x)-1];
    }

    for(int i=0; i<n; i++)
        if(arr[i] >= 0){
            missing = i+1;
        }
    cout<<repeating<<" "<<missing<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
