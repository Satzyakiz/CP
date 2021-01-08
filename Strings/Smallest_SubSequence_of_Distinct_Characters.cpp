// Given a string s, remove duplicate letters so that every letter
// appears once and only once. You must make sure your result is
// the smallest in lexicographical order among all possible results.
//
// Note: This question is the same as 1081:
// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
//
//
//
// Example 1:
//
// Input: s = "bcabc"
// Output: "abc"
// Example 2:
//
// Input: s = "cbacdcbc"
// Output: "acdb"

// Solved using stack

string removeDuplicateLetters(string s) {
    vector<int> count(26);
    for(char c: s) count[c - 'a']++;
    vector<bool> present(26);
    string ans = "";
    for(char c: s){
        count[c - 'a']--;
        if(ans.empty()){
            ans.push_back(c);
            present[c - 'a'] = true;
        }
        if(present[c - 'a']) continue;
        while(!ans.empty() && c < ans.back() && count[ans.back() - 'a']){
            present[ans.back() - 'a'] = false;
            ans.pop_back();
        }
        ans.push_back(c);
        present[c - 'a'] = true;
    }
    return ans;
}
