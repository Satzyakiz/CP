
// Given a string S and a string T, find the minimum window in S which will 
// contain all the characters in T in complexity O(n).
//
// Example:
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:
//
// If there is no such window in S that covers all characters in T, return
// the empty string "".
// If there is such window, you are guaranteed that there will always
// be only one unique minimum window in S.


string minWindow(string s, string t) {
    if (s.size() == 0 || t.size() == 0) return "";
    vector<int> map(128,0);
    int req = t.size();
    for(int i=0; i<req; i++)
        map[t[i]]++;
    int start = 0, left = 0, minSize = INT_MAX, i = 0;
    while(i <= s.size() && start < s.size()){
        if(req){
            if(i == s.size()) break;
            map[s[i]]--;
            if(map[s[i]] >= 0)
                req--;
            i++;
        }else{
            if(i - start < minSize){
                minSize = i - start;
                left = start;
            }
            map[s[start]]++;
            if(map[s[start]] > 0)
                req++;
            start++;
        }
    }

    return minSize == INT_MAX ? "" : s.substr(left,minSize);
}
