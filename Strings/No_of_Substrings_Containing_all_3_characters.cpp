// Given a string s consisting only of characters a, b and c.
//
// Return the number of substrings containing at least one occurrence
// of all these characters a, b and c.
//
//
//
// Example 1:
//
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the
// characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca",
// "bcab", "bcabc", "cab", "cabc" and "abc" (again).
// Example 2:
//
// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence
// of the characters a, b and c are "aaacb", "aacb" and "acb".
// Example 3:
//
// Input: s = "abc"
// Output: 1

int numberOfSubstrings(string s) {
    int n = s.size(), i=0, ans = 0;
    unordered_map<char,int> um;
    for(int j=0; j<n; j++){
        um[s[j]]++;
        while(um['a'] && um['b'] && um['c']){
            um[s[i]]--;
            i++;
        }
        ans += i;
    }
    return ans;
}
