//Get first non-repeating character in a string
// I/P: "madam" O/P: 2 (because index of d is 2)
#include<bits/stdc++.h>
using namespace std;

int getEleIndex(string s){
  vector<int> arr(26,0);
  for(char c: s){
    arr[c - 'a']++;
  }
  for(int i=0; i<s.size(); i++){
    if(arr[s[i] - 'a'] == 1) return i;
  }
  return -1;
}
int main(){
  string s;
  cin>>s;
  cout<<getEleIndex(s)<<endl;
  return 0;
}
