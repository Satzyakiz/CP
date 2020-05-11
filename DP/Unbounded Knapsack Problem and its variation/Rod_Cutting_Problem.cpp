// GIVEN:
// price of peices of rod according to their size, and total length of the Rod.
// Target: to find out the max profit by cutting the rod into some segments of size
// among the given size.

//Initialize the first row and first column with 0.
//Same as unbounded knapsack.

//size represents the size of segments that can be made
// and price represents the price of the segments
int knapsack(vector<int> price,vector<int> size,int W,int n){
  vector<vector<int>> dp(n+1,vector<int>(W+1));
  for(int i=0; i<n+1; i++){
    for(int j=0; j<W+1; j++){
      if(i == 0 || j == 0){
        dp[i][j] = 0;
      }
      else{
        if(size[i-1] <= j){
          //here j is current weight of KnapSack(the max curr size)
          dp[i][j] = max(price[i-1]+dp[i][j-size[i-1]] , dp[i-1][j]);
          //The current element can also be chosen another time (infinite times)
          // price[i-1]+dp[i][j-size[i-1]] --> this part has the only change compared to 0-1 Knapsack
          // dp[i][j-size[i-1]] : the "i" part. "i" instead of "i-1".
        }
        else{
          dp[i][j] = dp[i-1][j];
        }
      }
    }
  }
  return dp[n][W];
}
