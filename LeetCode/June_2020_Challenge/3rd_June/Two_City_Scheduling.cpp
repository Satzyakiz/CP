// There are 2N people a company is planning to interview.
// The cost of flying the i-th person to city A is costs[i][0],
// and the cost of flying the i-th person to city B is costs[i][1].
//
// Return the minimum cost to fly every person to a city such
// that exactly N people arrive in each city.
//
// Example 1:
//
// Input: [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation:
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.
//
// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have
// half the people interviewing in each city.

int twoCitySchedCost(vector<vector<int>>& costs) {
        int minCost = 0, n = costs.size()/2;
        int allInCity1 = 0;
        vector<int> diff(2*n);
        for(int i=0; i<2*n; i++){
            allInCity1 += costs[i][0];
            diff[i] = costs[i][1] - costs[i][0];
            cout<<allInCity1<<"  ";
        }
        cout<<endl;
        sort(diff.begin(),diff.end());
        minCost = allInCity1;
        for(int i=0; i<n; i++){
            minCost += diff[i];
            cout<<diff[i]<<"  ";
        }
        return minCost;
    }
