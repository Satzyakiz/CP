// IP: 2 6 7
// OP: 6
int rollsReq(int d,int f,int target){
    //creating a matrix whose rows are equal to no of dices and columns are equal to target.
    vector<vector<int>> dp(d+1,vector<int>(target+1));
    dp[0][0] = 1;
    for(int i=1; i<d+1; i++){   //No of dices
      for(int j=1; j<target+1; j++){ //Target at a particular instant
        for(int k=1; k<=f; k++){
          if(k > j) break;  //If current face value greater than target value then not possible
          dp[i][j] += dp[i-1][j-k];
        }
      }
    }
    return dp[d][target];
}

int main(){
    int d,f,target;
    cin>>d>>f>>target;
    cout<<rollsReq(d,f,target)<<endl;
    return 0;
}
