// There are N piles of coins each containing  Ai (1<=i<=N) coins.
// Now, you have to adjust the number of coins in each pile such that for
// any two pile, if a be the number of coins in first pile and b is the
// number of coins in second pile then |a-b|<=K. In order to do that you
// can remove coins from different piles to decrease the number of coins
// in those piles but you cannot increase the number of coins in a pile
// by adding more coins. Now, given a value of N and K, along with the
// sizes of the N different piles you have to tell the minimum number of
// coins to be removed in order to satisfy the given condition.
// Note: You can also remove a pile by removing all the coins of that pile.
// Input
// 3
// 4 0
// 2 2 2 2
// 6 3
// 1 2 5 1 1 1
// 6 3
// 1 5 1 2 5 1
//
// Output
// 0
// 1
// 2

#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    int minOverall = INT_MAX;
    //Removal variable will hold the count of all the piles before a pile
    //that won't be considered.
    //That is at i-th pile, it will hold the count of all the coins
    // from 0 to i-1 th pile, which are dropped
	int removal=0;
	for(int j=0;j<n-1;j++){
    	int m = arr[j];
    	int counter=0;
    	if(j>0){
        	removal+=arr[j-1];
        	counter+=removal;
    	}
	    for(int i=j+1; i<n; i++){
	        if((arr[i]-m)>k){
	            counter += arr[i]-m-k;
	        }
	    }
	    // cout<<counter<<endl;
	    minOverall = min(minOverall,counter);
	}
    cout<<minOverall<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();

    return 0;
}
