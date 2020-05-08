#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
  int m=s1.size(), n=s2.size();
  vector<vector<int>> lcsVal(m+1,vector<int>(n+1));
  for(int i=0; i<=m; i++){
    for(int j=0; j<=n; j++){
        if(i == 0 || j==0){
          lcsVal[i][j] = 0;
        }
        else if(s1[i-1] == s2[j-1]){
          lcsVal[i][j] = 1+lcsVal[i-1][j-1];
        }
        else{
          lcsVal[i][j] = max(lcsVal[i-1][j],lcsVal[i][j-1]);
        }
    }
  }
  return lcsVal[m][n];

}

int main(){
  string s1 = "shinchan";
  string s2 = "nohara";
  cout<<lcs(s1,s2)<<endl;
}

// o/p: 3 (nha)
