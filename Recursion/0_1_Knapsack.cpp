// 0/1 KnapSack
// I/P:
// 3
// 4
// 1 2 3
// 4 5 1
// O/P:
// 3
//
// I/P:
// 3
// 3
// 1 2 3
// 4 5 6
// O/P:
// 0

#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> val,vector<int> wt,int W,int n){
  if(n==0 || W==0) return 0;
  if(wt[n-1] <= W){
    //2 possibilities, either consider the element in Knapsack or leave it
    return max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
  }
  else{
    //Current weight more than Knapsack, so it needs to be discarded
    return knapsack(val,wt,W,n-1);
  }
}

int main(){
  int n,W;
  cin>>n>>W;
  vector<int> val(n);
  vector<int> wt(n);
  for(int i=0; i<n; i++){
    cin>>val[i];
  }
  for(int i=0; i<n; i++){
    cin>>wt[i];
  }
  cout<<knapsack(val,wt,W,n)<<endl;
  return 0;
}
