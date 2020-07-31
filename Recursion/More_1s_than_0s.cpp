// Given a positive integer N, print all N bit binary numbers having more 1’s
// than 0’s for any prefix of the number.
//
// Input:
// 2
// 2
// 3
// Output:
// 11 10
// 111 110 101

#include<bits/stdc++.h>
using namespace std;

void helper(string s, int one, int zero,int total){
    if(one + zero == total){
        cout<<s<<" ";
        return;
    }

    if(one < total)
        helper(s+"1",one+1,zero,total);
    if(one > zero)
        helper(s+"0",one,zero+1,total);
}
void solve(){
    int n;
    cin>>n;
    string s = "";
    helper(s,0,0,n);
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
