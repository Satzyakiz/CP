// Given a snake and ladder board of order 5x6,
// find the minimum number of dice throws required to
// reach the destination or last cell (30th cell) from source (1st cell) .
//
// Input:
// The first line of input contains an integer T
// denoting the no of test cases. Then T test cases follow.
// Each test case contains two lines. The first line of input
// contains an integer N denoting the no of ladders and snakes
// present. Then in the next line are 2*N space separated values
// a,b which denotes a ladder or a snake at position 'a' which takes
// to a position 'b'.
//
// Output:
// For each test case in a new line print the required answer
// denoting the min no of dice throws.
// 
// IP:
// 4
// 6
// 11 26 3 22 5 8 20 29 27 1 21 9
// 1
// 2 30
// 3
// 21 8 13 29 16 26
// 2
// 12 18 3 19
// OP:
// 3
// 1
// 3
// 3


#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
  int val;
  int dist;
}Node;
int snakeAndLadder(vector<int> g){
  vector<int> visited(31,0);
  Node n = {1,0};
  queue<Node> q;
  q.push(n);
  visited[1] = 1;
  while(!q.empty()){
    Node k = q.front();
    q.pop();
    if(k.val == 30){
      n = k;
      break;
    }
    for(int i=k.val+1; i<=k.val+6 && i<31; i++){
      if(visited[i] == 0){
        visited[i] = 1;
        if(g[i] != -1){
          q.push({g[i],k.dist+1});
        }else{
          q.push({i,k.dist+1});
        }
      }
    }

  }
  return n.dist;
}
void solve(){
  int N;
  cin>>N;
  vector<int> g(31,-1);
  for(int i=0; i<N; i++){
    int a,b;
    cin>>a>>b;
    g[a] = b;
  }
  cout<<snakeAndLadder(g)<<endl;
}
int main(){
  int t;
  cin>>t;
  // cout<<t<<endl;
  while(t--){
    solve();
  }
  return 0;
}
