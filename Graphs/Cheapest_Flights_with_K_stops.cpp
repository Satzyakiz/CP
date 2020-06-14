// There are n cities connected by m flights. Each flight starts from
// city u and arrives at v with a price w.
//
// Now given all the cities and flights, together with starting
// city src and the destination dst, your task is to find the
// cheapest price from src to dst with up to k stops. If there is
// no such route, output -1.
//
// Example 1:
// Input:
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
//
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200.
//
// Example 2:
// Input:
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
//
// The cheapest price from city 0 to city 2 with at most 0 stop costs 500,
// as marked blue in the picture.
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dp(K+2,vector<int>(n,INT_MAX));
        for(int i=0; i<K+2; i++)
            dp[i][src] = 0;
        for(int i=1; i<K+2; i++){
            for(auto f: flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if(dp[i-1][u] != INT_MAX)
                    dp[i][v] = min(dp[i][v],dp[i-1][u]+w);
            }
        }

        return dp[K+1][dst] == INT_MAX ? -1 : dp[K+1][dst];
    }
