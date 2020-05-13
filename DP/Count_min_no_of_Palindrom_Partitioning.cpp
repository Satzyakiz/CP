// IP: "nitin" OP: 0
// IP: "abcbd" OP: 2 ['a','bcb','d']
// {3 elements can be made by 2 partitions}
//
// IP:
// 4
// abcba
// abc
// ababcb
// aabbcc
// OP:
// 0
// 2
// 1
// 2


bool isPal(string s,int i,int j){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int dp[1002][1002]; //Max size of string in 1001
int getMinCut(string s,int i,int j){
    if(i>=j) return 0;
    if(isPal(s,i,j)) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int minVal = INT_MAX;
    for(int k=i; k<j; k++){
        int left,right;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = getMinCut(s,i,k);
            dp[i][k] = left;
        }
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{

            right = getMinCut(s,k+1,j);
            dp[k+1][j] = right;
        }
        int temp = left + right + 1;

        minVal = min(minVal,temp);
    }
    dp[i][j] = minVal;
    return minVal;
}
int Solution::minCut(string A) {
    for(int i=0; i<1002; i++){
        for(int j=0; j<1002; j++){
            dp[i][j] = -1;
        }
    }
    int n = A.size();
    return getMinCut(A,0,n-1);
}
