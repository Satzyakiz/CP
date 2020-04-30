// I/P: abcd
// O/P: [['a','b','c','d']]
//
// I/P: aab
// O/P: [['a','a','b'], ['aa','b']]
//
// I/P: aabb
// O/P: [['a','a','b','b'],['a','a','bb'],['aa','b','b'],['aa','bb']]

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s){
  int n = s.size();
  for(int i=0; i<n/2; i++){
    if(s[i] != s[n-i-1]){
      return false;
    }
  }
  return true;
}

void getPalPer(vector<vector<string>> &ans,string S, int index, vector<string> vArr){
  	if(index == S.length()){
        ans.emplace_back(vArr);
        return;
    }
    string str = "";
    for(int i=index; i<S.length(); i++){
        str += S[i];
        if(isPalindrome(str)){
          vArr.emplace_back(str);
          getPalPer(ans,S,i+1,vArr);
          vArr.pop_back();
        }
    }
    return;
}

int main(){
  string s;
  cin>>s;
  vector<vector<string>> ans;
  getPalPer(ans,s,0,{});
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
