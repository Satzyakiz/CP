// You are given strings s and t. Find one longest string that is a
// subsequence of both s and t.

#include<bits/stdc++.h>
using namespace std;

string solve(string a,string b){
	int m = a.size(), n = b.size();
  	string ans ="";
  	vector<vector<int>> dp(m+1,vector<int>(n+1));
  	for(int i=1; i<=m; i++){
    	for(int j=1; j<=n; j++){
        	if(a[i-1] == b[j-1]){
            	dp[i][j] = 1 + dp[i-1][j-1];
            }else{
            	dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
  	int i = m, j = n;
  	while(i>0 && j>0){
    	if(a[i-1] == b[j-1]){
        	ans = a[i-1] + ans;
          	i--,j--;
        }else if(dp[i-1][j] > dp[i][j-1]){
        	i--;
        }else{
        	j--;
        }
    }
  	return ans;
}
int main(){
	string a,b;
  	cin>>a;
  	cin.ignore();
  	cin>>b;
  	cout<<solve(a,b);
	return 0;
}
