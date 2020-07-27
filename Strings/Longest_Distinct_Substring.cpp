// Given a string, find the length of the longest substring without
// repeating characters. For example, the longest substrings without
// repeating characters for “ABDEFGABEF” are “BDEFGA” and “DEFGAB”,
// with length 6.
//
// Input:
// 2
// geeksforgeeks
// qwertqwer
//
// Output:
// 7
// 5

//Hashing
int lengthOfLongestSubstring(string s) {
    if(s.size() < 2)
        return s.size();
    unordered_map<char,int> um;
    int ans = 0, start = 0,curr = 0,i=0;
    while(i < s.size()){
        if(um.count(s[i])){
            curr = 0;
            i = um[s[i]]+1;
            um.clear();
        }else{
            curr++;
            um[s[i]] = i;
            ans = max(ans, curr);
            i++;
        }
    }
    return ans;
}

//Using arr

#include<bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int count = 0, c = 0,start = 0;
    int arr[26];
    memset(arr, -1, sizeof(arr));
    int ans = 0,i=0,curr = 0;
    while(i < s.size()){
        int index = s[i] - 'a';
        if(arr[index] == -1){
            curr++;
            arr[index] = i;
            ans = max(ans,curr);
            i++;
        }else{
            curr = 0;
            i = arr[index]+1;
            memset(arr, -1, sizeof(arr));
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
