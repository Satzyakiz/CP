// Given a string S, we need to write a program to check if it is possible
// to construct the given string S by performing any of the below operations
// any number of times. In each step, we can:
//
// Add any character at the end of the string.
// or, append the string to the string itself.
// The above steps can be applied any number of times. We need to print
// the minimum steps required to form the string.
// Input
// 3
// aaaaaaaa
// aaaaaa
// abcabca
// Output
// 4
// 4
// 5
//
// Explanation:
// 1.  move 1: add 'a' to form "a"
//      move 2: add 'a' to form "aa"
//      move 3: append "aa" to form "aaaa"
//      move 4: append "aaaa" to form "aaaaaaaa"
// 2.  move 1: add 'a' to form "a"
//      move 2: add 'a' to form "aa"
//      move 3: add 'a' to form "aaa"
//      move 4: append "aaa" to form "aaaaaa"
// 3.  move 1: add 'a' to form "a"
//      move 2: add 'b' to form "ab"
//      move 3: add 'c' to form "abc"
//      move 4: append "abc" to form "abcabc"
//      move 5: add 'a' to form "abcabca"

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(){
    string s;
    cin>>s;
    int count = 0, n = s.size()-1;
    while(n >= 0){
        if(n & 1){
            if(s.substr(0,n/2+1) == s.substr(n/2+1,n/2+1))
                n /= 2;
            else
                n--;
        }else{
            n--;
        }
        count++;
    }

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
