// Given a string 's'. The task is to find the smallest window length 
// that contains all the characters of the given string at least one time.
// For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest
// window will be “dbca”.
//
// Input:
// 2
// aabcbcdbca
// aaab
//
// Output:
// 4
// 2
//
// Explanation:
// Testcase 1: Smallest window size is 4 which is of "dbca" which
// consists all characters of the string.

#include<bits/stdc++.h>
using namespace std;


void solve(){
    string a;
    cin>>a;
    int n1 = a.size();
    vector<int> large(26),unique(26);
    int count = 0;
    for(char &c: a){
        if(unique[c - 'a'] == 0)
            count++;
        unique[c - 'a'] = 1;
    }
    int ans = INT_MAX, c2 = 0,start = 0;
    for(int i=0; i<n1; i++){
        if(large[a[i] - 'a'] == 0){
            c2++;
        }

        large[a[i] - 'a']++;

        if(c2 >= count){
            while(c2 == count && start <= i){
                ans = min(ans, i - start + 1);
                large[a[start] - 'a']--;
                if(large[a[start] - 'a'] == 0){
                    c2--;
                }
                start++;
            }
        }
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
