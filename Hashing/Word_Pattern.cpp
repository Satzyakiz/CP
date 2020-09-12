// Given a pattern and a string s, find if s follows the same pattern.
//
// Here follow means a full match, such that there is a bijection between
// a letter in pattern and a non-empty word in s.
//
// Example 1:
//
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
// Example 2:
//
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// Example 3:
//
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false
// Example 4:
//
// Input: pattern = "abba", s = "dog dog dog dog"
// Output: false

bool wordPattern(string pattern, string str) {
    unordered_map<char, string> um;
    unordered_map<string, char> um2;
    stringstream ss(str);
    string word;
    int i = 0;
    while(ss >> word){
        if(i == pattern.size())
            return false;
        if(um.count(pattern[i])){
            if(um[pattern[i]] != word)
                return false;
        }else{
            if(um2.count(word) && um2[word] != pattern[i])
                return false;
            um2[word] = pattern[i];
            um[pattern[i]] = word;
        }
        i++;
    }
    if(i != pattern.size())
        return false;
    return true;
}
