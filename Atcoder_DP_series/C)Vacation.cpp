// Taro's summer vacation starts tomorrow, and he has decided to make
// plans for it now.The vacation consists of NN days. For each ii (1≤i≤N1≤i≤N),
// Taro will choose one of the following activities and do it on the ii-th day:
// A: Swim in the sea. Gain aiai points of happiness.
// B: Catch bugs in the mountains. Gain bibi points of happiness.
// C: Do homework at home. Gain cici points of happiness.
// As Taro gets bored easily, he cannot do the same activities for two
// or more consecutive days.
// Find the maximum possible total points of happiness that Taro gains.


// Sample Input 1
// 3
// 10 40 70
// 20 50 80
// 30 60 90
// Sample Output 1
// 210
// If Taro does activities in the order C, B, C, he will gain
// 70
// +
// 50
// +
// 90
// =
// 210
//  points of happiness.
//
// Sample Input 2
// 1
// 100 10 1
// Sample Output 2
// 100
// Sample Input 3
// 7
// 6 7 8
// 8 8 3
// 2 5 2
// 7 8 6
// 4 6 8
// 2 3 4
// 7 5 1
// Sample Output 3
// 46


#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> m;
int ans;
int solve(vector<vector<int>> &mat,int day,int item){
  if(day >= mat.size()){
      return 0;
  }
  if(m.find({day,item}) != m.end())
      return m[{day,item}];
  int temp = 0;
  for(int j=0; j<3; j++){
    if(j != item)
      temp = max(temp,mat[day][item]+solve(mat,day+1,j));
  }
  return m[{day,item}] = temp;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin>>n;
  vector<vector<int>> mat(n,vector<int>(3));
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      cin>> mat[i][j];
    }
  }
  ans = 0;
  for(int i=0; i<3; i++){
    ans = max(ans,solve(mat,0,i));
  }
  cout<<ans;
  return 0;
}

// Using unordered_map, we have to write our own hash function
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<pair<int,int>,int,hash_pair> m;
