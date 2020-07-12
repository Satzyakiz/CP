//Extension of largest area histogram

// Given a 2D binary matrix filled with 0's and 1's, find the largest
// rectangle containing only 1's and return its area.
//
// Example:
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6


vector<int> NSL(vector<int> &dp){
    vector<int> nsl;
    stack<int> s;
    int n = dp.size();
    int pseudo = -1;
    for(int i=0; i<n; i++){
        if(s.empty()){
            nsl.emplace_back(pseudo);
        }
        else if(!s.empty() && dp[s.top()] < dp[i]){
            nsl.emplace_back(s.top());
        }
        else if(!s.empty() && dp[s.top()] >= dp[i]){
            while(!s.empty() && dp[s.top()] >= dp[i]){
                s.pop();
            }
            if(s.empty()){
                nsl.emplace_back(pseudo);
            }else{
                nsl.emplace_back(s.top());
            }
        }
        s.push(i);
    }
    return nsl;
}
vector<int> NSR(vector<int> &dp){
    vector<int> nsr;
    stack<int> s;
    int n = dp.size();
    int pseudo = n;
    for(int i=n-1; i>=0; i--){
        if(s.empty()){
            nsr.emplace_back(pseudo);
        }
        else if(!s.empty() && dp[s.top()] < dp[i]){
            nsr.emplace_back(s.top());
        }
        else if(!s.empty() && dp[s.top()] >= dp[i]){
            while(!s.empty() && dp[s.top()] >= dp[i]){
                s.pop();
            }
            if(s.empty()){
                nsr.emplace_back(pseudo);
            }else{
                nsr.emplace_back(s.top());
            }
        }
        s.push(i);
    }
    reverse(nsr.begin(),nsr.end());
    return nsr;
}
int mah(vector<int> &dp){
    vector<int> nsl, nsr;
    nsl = NSL(dp);
    nsr = NSR(dp);

    vector<int> area(dp.size());
    for(int i=0; i<dp.size(); i++){
        int temp = (nsr[i] - nsl[i] - 1) * dp[i];
        area[i] = temp;
    }

    return *max_element(area.begin(), area.end());
}
int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.size() == 0)
        return 0;
    int n = matrix[0].size();
    vector<int> dp(n);
    int ans = 0;
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            if(i == 0){
                dp[j] = matrix[i][j] - '0';
            }else{
                if(matrix[i][j] == '0'){
                    dp[j] = 0;
                }else{
                    dp[j] += 1;
                }
            }
        }
        ans = max(ans,mah(dp));
    }
    return ans;
}
