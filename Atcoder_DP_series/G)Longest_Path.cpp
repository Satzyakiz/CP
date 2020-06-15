// There is a directed graph GG with NN vertices and MM edges. 
// The vertices are numbered 1,2,…,N1,2,…,N, and for each ii (1≤i≤M1≤i≤M),
// the ii-th directed edge goes from Vertex xixi to yiyi. GG does not
// contain directed cycles. Find the length of the longest directed
// path in GG. Here, the length of a directed path is the number of
// edges in it.
// Sample Input 1
// 4 5
// 1 2
// 1 3
// 3 2
// 2 4
// 3 4
// Sample Output 1
// 3
// Sample Input 2
// 6 3
// 2 3
// 4 5
// 5 6
// Sample Output 2
// 2

#include<bits/stdc++.h>
using namespace std;
int ans;
unordered_map<int,int> dp;
int dfs(vector<vector<int>> &adj,int index){
  if(dp.find(index) != dp.end())
    return dp[index];
  int tempAns = 0;
  for(int j=0; j<adj[index].size(); j++){
    int u = adj[index][j];
    int temp = 1+dfs(adj,u);
    tempAns = max(tempAns,temp);
  }
  return dp[index] = tempAns;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  cin>>n>>m;
  vector<vector<int>> adj(n+1);
  int x,y;
  for(int i=0; i<m; i++){
    cin>>x>>y;
    adj[x].push_back(y);
  }
  ans = 0;
  for(int i=1; i<n+1; i++){
      // cout<<ans<<endl;
      ans = max(ans,dfs(adj,i));
  }
  cout<<ans;
  return 0;
}
