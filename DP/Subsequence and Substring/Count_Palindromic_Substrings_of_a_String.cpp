// Given a string, the task is to count all palindromic sub-strings
// present in it.
// Input
//
// 2
// 5
// abaab
// 7
// abbaeae
//
// Output
//
// 3
// 4
//
// Explanation:
//
// Test Case 1
// Input : str = "abaab"
// Output: 3
// All palindrome substring are : "aba" , "aa" , "baab"
//
// Test Case 2
// Input : str = "abbaeae"
// Output: 4
// All palindrome substring are : "bb" , "abba" ,"aea","eae"
//

#include<bits/stdc++.h>
using namespace std;
#define ll long long
void LPS(string s,int &count){
    int n = s.size();
    vector<vector<int>> truth(n,vector<int>(n));
    for(int i=0; i<n; i++) truth[i][i] = 1;
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            count++;
            truth[i][i+1] = 1;
        }
    }

    for(int len = 3; len<=n; len++){
        for(int i=0; i<n-len+1; i++){
            int j = i+len-1;
            if(s[i] == s[j] && truth[i+1][j-1]){
                truth[i][j] = 1;
                count++;
            }
        }
    }
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count = 0;
    LPS(s,count);
    cout<<count<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
