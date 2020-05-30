
// Given a binary array, find the maximum length of a contiguous
// subarray with equal number of 0 and 1.
//
// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with
// equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray
// with equal number of 0 and 1.


int findMaxLength(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        int maxLen = 0, prefixSum = 0;
        unordered_map<int, int> hash; // prefixSum => index
        for( int i=0; i < nums.size(); i++ ) {
            if( nums[i] == 1 ) prefixSum++;
            else prefixSum--;

            if( hash.find( prefixSum ) != hash.end() )
                maxLen = max( maxLen, i - hash[prefixSum] );
            else
                hash[prefixSum] = i;

            if( prefixSum == 0 )
                maxLen = i + 1;
        }
        return maxLen;
    }
