// Given an unsorted array of integers, find the length of the longest
// consecutive elements sequence.
//
// Your algorithm should run in O(n) complexity.
//
// Example:
//
// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
// Therefore its length is 4.

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> searched(nums.begin(),nums.end()), visit;
    int ans = 0;
    for(int &x: nums){
        if(visit.count(x))
            continue;
        visit.insert(x);
        int prev = x-1, next = x+1;
        while(searched.count(prev)){
            visit.insert(prev);
            prev--;
        }
        while(searched.count(next)){
            visit.insert(next);
            next++;
        }
        ans = max(ans, next - prev - 1);
    }
    return ans;
}
