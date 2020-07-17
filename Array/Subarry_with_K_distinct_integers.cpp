// Given an array A of positive integers, call a (contiguous,
// not necessarily distinct) subarray of A good if the number of
// different integers in that subarray is exactly K.
//
// (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
//
// Return the number of good subarrays of A.

// Example 1:
//
// Input: A = [1,2,1,2,3], K = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers:
// [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
// Example 2:
//
// Input: A = [1,2,1,3,4], K = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers:
// [1,2,1,3], [2,1,3], [1,3,4].

// exactly(K) = atMost(K) - atMost(K-1)

int subarraysWithKDistinct(vector<int>& A, int k) {
    return atMost(A,k) - atMost(A,k-1);
}
int atMost(vector<int> &nums,int k){
    int ans = 0, i=0;
    unordered_map<int,int> um;
    for(int j=0; j<nums.size(); j++){
        if(um[nums[j]] == 0)
            k--;
        um[nums[j]]++;
        while(k < 0){
            um[nums[i]]--;
            if(um[nums[i]] == 0)
                k++;
            i++;
        }
        ans += j-i+1;
    }
    return ans;
}
