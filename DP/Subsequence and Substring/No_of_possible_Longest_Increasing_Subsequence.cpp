// Program to get no of possible ways to get maximum LIS
#include<bits/stdc++.h>
using namespace std;

int possibleWays(vector<int> v){
  int n = v.size();
  vector<int> lis(n,1);
  vector<int> count(n,1);
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if(v[j] < v[i]){
        if(lis[j] >= lis[i]){
          lis[i] = lis[j]+1;
          count[i] = count[j];
        }
        else if(lis[j]+1 == lis[i]){
          count[i] += count[j];
        }
      }
    }
  }
//   Print lis vector
//   for(int x: lis){
//     cout<<x<<" ";
//   }
//   cout<<endl;
// print count vector
//   for(int x: count){
//     cout<<x<<" ";
//   }
//   cout<<endl;
    int ans=0, maxCount = INT_MIN;
    for(int x: count){
        maxCount = max(maxCount, x);
    }
    // cout<<maxCount<<endl;
    for(int x: count){
        if(x == maxCount)
            ans+= x;
    }
  return ans;
}

int main(){
//   vector<int> v{1,2,1,3,4,5,6,1,2,3,4,5,6,7}; O/P : 8
    vector<int> v{2,2,2,2,2}; //O/P: 5
  cout<<possibleWays(v)<<endl;
  return 0;
}
// Time Complexity : O(n^2)
// Space Complexity: O(n)
