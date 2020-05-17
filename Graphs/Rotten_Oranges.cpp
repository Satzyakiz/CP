// 0: Empty cell
// 1: Cells have fresh oranges
// 2: Cells have rotten oranges

#include<bits/stdc++.h>
using namespace std;

int rottenOranges(vector<vector<int>> g){
  int goodOranges,r=g.size(),c=g[0].size();
  queue<pair<int,int>> q;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      if(g[i][j] == 1) goodOranges++;
      if(g[i][j] == 2){
        q.push({i,j});
      }
    }
  }
  // cout<<q.size()<<endl;
  if(goodOranges == 0) return 0;
  int time = 0;
  set<pair<int,int>> s;
  int i,j;
  while(!q.empty()){
    int k = q.size();
    while(k--){
      i = q.front().first;
      j = q.front().second;
      // cout<<i<<"  "<<j<<endl;
      q.pop();
      if(i-1 >= 0 && g[i-1][j] == 1){
        g[i-1][j] = 2;
        q.push({i-1,j});
        goodOranges--;
      }
      if(i+1 < r && g[i+1][j] == 1){
        g[i+1][j] = 2;
        q.push({i+1,j});
        goodOranges--;
      }
      if(j-1 >= 0 && g[i][j-1] == 1){
        g[i][j-1] = 2;
        q.push({i,j-1});
        goodOranges--;
      }
      if(j+1 < c && g[i][j+1] == 1){
        g[i][j+1] = 2;
        q.push({i,j+1});
        goodOranges--;
      }
    }
    time++;
  }
  if(goodOranges > 0) return -1;
  return time-1;
}
void solve(){
  int r,c;
  cin>>r>>c;
  vector<vector<int>> g(r,vector<int>(c));
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      cin>>g[i][j];
    }
  }
  // cout<<"Done\n";
  cout<<rottenOranges(g)<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  // cout<<t<<endl;
  while(t--){
    solve();
  }
  return 0;
}
// Input:  arr[][C] = { {2, 1, 0, 2, 1},
//                      {1, 0, 1, 2, 1},
//                      {1, 0, 0, 2, 1}};
// Output:
// All oranges can become rotten in 2-time frames.
// Explanation:
// At 0th time frame:
//  {2, 1, 0, 2, 1}
//  {1, 0, 1, 2, 1}
//  {1, 0, 0, 2, 1}
//
// At 1st time frame:
//  {2, 2, 0, 2, 2}
//  {2, 0, 2, 2, 2}
//  {1, 0, 0, 2, 2}
//
// At 2nd time frame:
//  {2, 2, 0, 2, 2}
//  {2, 0, 2, 2, 2}
//  {2, 0, 0, 2, 2}
//
//
// Input:  arr[][C] = { {2, 1, 0, 2, 1},
//                      {0, 0, 1, 2, 1},
//                      {1, 0, 0, 2, 1}};
// Output:
// All oranges cannot be rotten.
// Explanation:
// At 0th time frame:
// {2, 1, 0, 2, 1}
// {0, 0, 1, 2, 1}
// {1, 0, 0, 2, 1}
//
// At 1st time frame:
// {2, 2, 0, 2, 2}
// {0, 0, 2, 2, 2}
// {1, 0, 0, 2, 2}
//
// At 2nd time frame:
// {2, 2, 0, 2, 2}
// {0, 0, 2, 2, 2}
// {1, 0, 0, 2, 2}
// ...
// The 1 at the bottom left corner of the matrix is never rotten.
