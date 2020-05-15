
//DP Approach of egg dropping problem

#include<bits/stdc++.h>
using namespace std;
int eggDrop(int eggs,int floors){
  vector<vector<int>> dp(eggs+1,vector<int> (floors+1));
  //Initialization
  for(int i=0; i<eggs+1; i++){
    dp[i][0] = 0;
    dp[i][1] = 1;
  }
  for(int j=0; j<floors+1; j++){
    dp[1][j] = j; //If 1 egg is there, we would req j no of tries
    //to determine the egg would break or not
    //where j is the no of floors
  }
  int minVal = INT_MAX;
  for(int i=2; i<eggs+1; i++){ // No of eggs at an instant
    for(int j=2; j<floors+1; j++){ //Current max no of floors at an instant
      dp[i][j] = INT_MAX;
      for(int x=1; x<=j; x++){ //Current floor no upto j floors
        int temp = 1 + max(dp[i-1][x-1],dp[i][j-x]);
        dp[i][j] = min(temp,dp[i][j]);
      }
    }
  }
  return dp[eggs][floors];
}

int main(){
  int eggs,floors;
  cin>>eggs>>floors;
  cout<<eggDrop(eggs,floors)<<endl;
  return 0;
}
