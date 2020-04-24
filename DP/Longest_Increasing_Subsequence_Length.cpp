#include<bits/stdc++.h>
using namespace std;

int lengthLIS(vector<int> v){
  int n = v.size(),maxLIS = 1;
  vector<int> lis(n,1);
  for(int i=1; i<n; i++){
    for(int j=0; j<i; j++){
      if(v[j] < v[i] && lis[i] < lis[j]+1 ){
        lis[i] = lis[j]+1;
        if(lis[i] > maxLIS)
          maxLIS = lis[i];
      }
    }
  }
  return maxLIS;
}

int main(){
  vector<int> v{1,2,1,3,4,5,6,1,2,3,4,5,6,7};
  cout<<lengthLIS(v)<<endl;
  return 0;
}
// O/P:
// 7

// Time Complexity: O(n^2)
// Space Complexity : O(n) {lis array}
