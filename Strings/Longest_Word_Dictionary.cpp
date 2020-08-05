// Given a list of strings words representing an English Dictionary,
// find the longest word in words that can be built one character at
// a time by other words in words. If there is more than one possible
// answer, return the longest word with the smallest lexicographical order.
//
// If there is no answer, return the empty string.
// Example 1:
// Input:
// words = ["w","wo","wor","worl", "world"]
// Output: "world"
// Explanation:
// The word "world" can be built one character at a time by "w", "wo",
// "wor", and "worl".
// Example 2:
// Input:
// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation:
// Both "apply" and "apple" can be built from other words in the dictionary.
// However, "apple" is lexicographically

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end());
    unordered_set<string> s;
    string ans = "";
    for(string &w: words){
        if(w.size() == 1 || s.count(w.substr(0,w.size()-1))){
            ans = w.size() > ans.size() ? w : ans;
            s.insert(w);
        }
    }
    return ans;
}
