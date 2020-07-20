// Given an array of integers A, find the sum of min(B),
// where B ranges over every (contiguous) subarray of A.
//
// Since the answer may be large, return the answer modulo 10^9 + 7.
// Example 1:
//
// Input: [3,1,2,4]
// Output: 17
// Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4],
// [3,1,2], [1,2,4], [3,1,2,4].
// Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.

// Optimal Solution
int sumSubarrayMins(vector<int>& A) {
    long long ans = 0;
    int n = A.size(),j,k,mod= 1e9+7;
    stack<int> s;
    for(int i=0; i<=n; i++){
        while(!s.empty() && A[s.top()] > (i == n ? 0 : A[i])){
            j = s.top();
            s.pop();
            k = s.empty() ? -1 : s.top();
            ans = (ans + A[j] * (i-j) * (j-k))%mod;
        }
        s.push(i);
    }
    return (int)ans;
}
//O(n) space
int sumSubarrayMins(vector<int> A) {
    int res = 0, n = A.size(), mod = 1e9 + 7;
    vector<int> left(n), right(n);
    stack<pair<int, int>> s1,s2;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (!s1.empty() && s1.top().first > A[i]) {
            count += s1.top().second;
            s1.pop();
        }
        s1.push({A[i], count});
        left[i] = count;
    }
    for (int i = n - 1; i >= 0; --i) {
        int count = 1;
        while (!s2.empty() && s2.top().first >= A[i]) {
            count += s2.top().second;
            s2.pop();
        }
        s2.push({A[i], count});
        right[i] = count;
    }
    for (int i = 0; i < n; ++i)
        res = (res + A[i] * left[i] * right[i]) % mod;
    return res;
}

// Approach
// I guess this is a general intuition for most solution.
// res = sum(A[i] * f(i))
// where f(i) is the number of subarrays,
// in which A[i] is the minimum.
//
// To get f(i), we need to find out:
// left[i], the length of strict bigger numbers on the left of A[i],
// right[i], the length of bigger numbers on the right of A[i].
//
// Then,
// left[i] + 1 equals to
// the number of subarray ending with A[i],
// and A[i] is single minimum.
//
// right[i] + 1 equals to
// the number of subarray starting with A[i],
// and A[i] is the first minimum.
//
// Finally f(i) = (left[i] + 1) * (right[i] + 1)
//
// For [3,1,2,4] as example:
// left + 1 = [1,2,1,1]
// right + 1 = [1,3,2,1]
// f = [1,6,2,1]
// res = 3 * 1 + 1 * 6 + 2 * 2 + 4 * 1 = 17
