// Consider a game where a player can score 3 or 5 or 10 points
// in a move. Given a total score n, find the number of distinct
// combinations to reach the given score.
//
// Input:
// 3
// 8
// 20
// 13
//
// Output:
// 1
// 4
// 2

//Coin change variation

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int get(int arr[],int i, int n){
    if(n == 0)
        return 1;
    if(n < 0 || i <= 0)
        return 0;

    return get(arr,i,n-arr[i-1]) + get(arr,i-1,n);
}
void solve(){
    int n;
    cin>>n;
    int arr[] = {3,5,10};
    cout<<get(arr,3,n)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
