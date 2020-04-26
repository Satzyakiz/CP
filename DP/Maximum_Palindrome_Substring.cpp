#include<bits/stdc++.h>
using namespace std;

string maxPalSubstr(string s){
  int n = s.size();
  if(n == 0 || n == 1) return s;
  vector<vector<int>> truth(n, vector<int>(n));
  int startIndex = 0, lastIndex = 0,maxLength = 1;
  //Substrings of length 1
  for(int i=0; i<n; i++){
    truth[i][i] = 1;
  }
  //Substrings of length 2
  for(int i=0; i<n-1; i++){
    if(s[i] == s[i+1]){
      truth[i][i+1] = 1;
      if(lastIndex == 0){
        startIndex = i;
        lastIndex = i+1;
        maxLength = 2;
      }
    }
  }
  //Substrings of length 3
  for(int k=3; k<=n; k++){
    for(int i=0; i<n-k+1; i++){
      int j=i+k-1;
      if(s[i] == s[j] && truth[i+1][j-1] == 1){
          truth[i][j] = 1;
          if(k > maxLength){
            maxLength = k;
            startIndex = i;
            lastIndex = j;
          }
      }
    }
  }

  string ans = "";
  for(int i=startIndex; i<=lastIndex; i++){
    ans += s[i];
  }
  return ans;
}

int main(){
  // string s = "!madam123"; o/p: madam
  string s = "abacab";  //o/p: bacab
  cout<< maxPalSubstr(s)<<endl;
  return 0;
}
