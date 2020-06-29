// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, determine if s can be segmented into a space-separated
// sequence of one or more dictionary words.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in the
// segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
// Example 2:
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as
//             "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
// Example 3:
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false

unordered_map<string,bool> um;
bool help(string s,vector<string> &v){
    if(s.size() == 0)
        return true;
    if(um.find(s) != um.end())
        return um[s];
    string temp = "";
    for(int i=0; i<s.size(); i++){
        temp += s[i];
        if(find(v.begin(),v.end(),temp) != v.end() && help(s.substr(i+1),v))
            return um[temp] = true;
    }
    return um[s]=false;
}
bool wordBreak(string s, vector<string>& wordDict) {
     return help(s,wordDict);
}
