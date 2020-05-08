#include<bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2){
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
  int size = lcsVal[m][n];
  string ans = "";
  int i = m, j = n;
  while(i> 0 && j>0){
    if(s1[i-1] == s2[j-1]){
      ans = s1[i-1] + ans;
      i--;
      j--;
    }
    else if(lcsVal[i-1][j] > lcsVal[i][j-1])
      i--;
    else
      j--;
  }
  return ans;

}

int main(){
  string s1 = "ABCDE";
  string s2 = "ABCGHCE";
  cout<<lcs(s1,s2)<<endl;
}

// o/p: ABCE
