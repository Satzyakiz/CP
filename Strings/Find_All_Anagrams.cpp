// Given a string s and a non-empty string p, find all
// the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and
// the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// =============================================================
// Solution using sliding window approach
// =============================================================
vector<int> findAnagrams(string s,string p){
  vector<int> ans;
  int window = p.size();
  if(window > s.size()) return ans;
  vector<int> pHash(26,0); // hash table for string p
  vector<int> hash(26,0); //hash for s string present anagrams
  for(int i=0; i<window; i++){
    pHash[p[i] - 'a']++;
    hash[s[i] - 'a']++;
  }
  int start=0,end=window-1;
  while(end < s.size()){
    if(pHash == hash) {
      //Same hash table means that the
      // current substring is an anagram
      ans.emplace_back(start);
    }
    //Sliding window part starts here
    end++; //end is increased by 1
    if(end != s.size()){
      hash[s[end] - 'a']++;
    }
    hash[s[start] - 'a']--; //The count of previous value of start
    // is decreased as the window slides.
    start++;//start is also increased by 1
  }
  return ans;
}
