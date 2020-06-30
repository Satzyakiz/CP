// The Hamming distance between two integers is the number of positions at
// which the corresponding bits are different.
//
// Now your job is to find the total Hamming distance between all pairs of the
// given numbers.
//
// Example:
// Input: 4, 14, 2
//
// Output: 6
//
// Explanation: In binary representation, the 4 is 0100, 14 is 1110, and 2 is 0010
// (just showing the four bits relevant in this case). So the answer will be:
// HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2)
// = 2 + 2 + 2 = 6.

int totalHammingDistance(vector<int>& nums) {
    int ans =0, n = nums.size();
    for(int i=0; i<32; i++){
        int temp = 0;
        for(int j=0; j<n; j++){
            if(1<<i & nums[j])
                temp++;
        }
        ans += temp*(n-temp);
    }
    return ans;
}

// 1<<i --> Used to indicate i-th position in 32 bits
//temp gives us same no of bits, so n - temp gives is different no,
// which is req in hamming distance
