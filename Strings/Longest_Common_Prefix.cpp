
// Example 1:
//
// Input: ["flower","flow","flight"]
// Output: "fl"
// Example 2:
//
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

string getPrefix(string s1, string s2){
    string ans = "";
    for(int i=0,j=0; i<s1.size() && j<s2.size(); i++,j++){
        if(s1[i] != s2[j])
            break;
        ans += s1[i];
    }
    return ans;
}
string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0)
        return "";
    if(strs.size() == 1)
        return strs[0];

    string prefix = strs[0];
    for(int i=1; i<strs.size(); i++)
        prefix = getPrefix(prefix,strs[i]);
    return prefix;
}
