// Given an array of size N consisting of only 0's and 1's ,
// which is sorted in such a manner that all the 1's are placed
// first and then they are followed by all the 0's. You have to
// find the count of all the 0's.
// Input:
// 3
// 12
// 1 1 1 1 1 1 1 1 1 0 0 0
// 5
// 0 0 0 0 0
// 6
// 1 1 1 1 1 1
// Output:
// 3
// 5
// 0
#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> A){
    int n=A.size(),l=0,h=n-1,pos=-1;
    while(l <= h){
        int mid = l+(h-l)/2;
        if(A[mid] == 0){
            h = mid-1;
            pos = mid;
        }else if(A[mid] > 0){
            l = mid+1;
        }
    }
    if(pos == -1)
        return 0;
    return n-pos;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<helper(arr)<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
