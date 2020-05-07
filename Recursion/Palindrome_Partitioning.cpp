// IP:
// aabbd
// O/P:
// a    a    b    b    d
// a    a    bb    d
// aa    b    b    d
// aa    bb    d

#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string S){
  int n = S.size();
  for(int i=0; i<n/2; i++){
    if(S[i] != S[n-1-i])
      return false;
  }
  return true;
}
void palPartition(vector<vector<string>> &ans,string S,int index, vector<string> v){
  if(index == S.size()){
    ans.emplace_back(v);
    return;
  }
  string s = "";
  for(int i=index; i<S.size(); i++){
    s += S[i];
    if(isPalindrome(s)){
      v.emplace_back(s);
      palPartition(ans,S,i+1,v);
      v.pop_back();
    }
  }
}
void printMat(vector<vector<string>> ans){
  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<<ans[i][j]<<"    ";
    }
    cout<<endl;
  }
}
int main(){
  string S;
  cin>>S;
  vector<vector<string>> ans;
  palPartition(ans,S,0,{});
  printMat(ans); //ANSWER in the form of 2d matrix
  return 0;
}
