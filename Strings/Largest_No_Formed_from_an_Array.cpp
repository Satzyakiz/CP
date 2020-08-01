// Given a list of non negative integers, arrange them in such a manner 
// that they form the largest number possible.The result is going to be
// very large, hence return the result in the form of a string.
//
// Input:
// 2
// 5
// 3 30 34 5 9
// 4
// 54 546 548 60
//
// Output:
// 9534330
// 6054854654

#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(string s1,string s2){
    return s1+s2 > s2+s1;
}
void solve(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end(),compare);
    string ans = "";
    for(string &s: v)
        ans += s;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
