//LIS variation

// You are given n pairs of numbers. In every pair, the first number is 
// always smaller than the second number.
//
// Now, we define a pair (c, d) can follow another pair (a, b) if and only
// if b < c. Chain of pairs can be formed in this fashion.
//
// Given a set of pairs, find the length longest chain which can be formed.
// You needn't use up all the given pairs. You can select pairs in any order.
//
// Example 1:
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]

int findLongestChain(vector<vector<int>>& pairs) {
	int n = pairs.size();
	sort(pairs.begin(),pairs.end());
	vector<int> lis(n,1);
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(pairs[j][1] < pairs[i][0] && lis[i] < 1 + lis[j])
				lis[i] =  1 + lis[j];
		}
	}
	int maxi = 1;
	for(int i=1; i<n; i++)
		maxi = max(maxi, lis[i]);
	return maxi;
}
