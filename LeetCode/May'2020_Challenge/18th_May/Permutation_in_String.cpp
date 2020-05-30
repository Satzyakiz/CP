// Given two strings s1 and s2, write a function
// to return true if s2 contains the permutation of s1.
// In other words, one of the first string's permutations is
// the substring of the second string.
//
//
//
// Example 1:
//
// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:
//
// Input:s1= "ab" s2 = "eidboaoo"
// Output: False

bool checkInclusion(string s2, string s1) {
        if(s1.size() < s2.size()) return false;
        vector<int> s2Hash(26,0);
        vector<int> hash(26,0);
        int window = s2.size();
        for(int i=0; i<window; i++){
            s2Hash[s2[i] - 'a']++;
            hash[s1[i] - 'a']++;
        }
        int start = 0,end = window-1;
        while(end < s1.size()){
            if(s2Hash == hash) return true;
            end++;
            if(end != s1.size())
                hash[s1[end]-'a']++;
            hash[s1[start] - 'a']--;
            start++;
        }
        return false;
    }
