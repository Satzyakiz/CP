// 
// As it is Tushar’s Birthday on March 1st, he decided to throw a party to
// all his friends at TGI Fridays in Pune. Given are the eating capacity of each
// friend, filling capacity of each dish and cost of each dish. A friend is
// satisfied if the sum of the filling capacity of dishes he ate is equal to
// his capacity. Find the minimum cost such that all of Tushar’s friends are
// satisfied (reached their eating capacity).
//
// NOTE:
//
// Each dish is supposed to be eaten by only one person. Sharing is not allowed.
// Each friend can take any dish unlimited number of times.
// There always exists a dish with filling capacity 1 so that a solution always exists.
// Input Format
//
// Friends : List of integers denoting eating capacity of friends separated by space.
// Capacity: List of integers denoting filling capacity of each type of dish.
// Cost :    List of integers denoting cost of each type of dish.

// Input:
//     2 4 6
//     2 1 3
//     2 5 3
//
// Output:
//     14
//
// Explanation:
//     First friend will take 1st and 2nd dish, second friend will take 2nd
//     dish twice.  Thus, total cost = (5+3)+(3*2)= 14



int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    vector<int> dp(1001,INT_MAX);
    dp[0] = 0;
    int mxe = *max_element(a.begin(),a.end());
    for(int i=1; i<=mxe; i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            if(i-b[j] >= 0)
            {
                dp[i] = min(dp[i],dp[i-b[j]] + c[j]);
            }
        }
    }
    int ans=0;
    for(int i : a) ans += dp[i];
    return ans;
}
