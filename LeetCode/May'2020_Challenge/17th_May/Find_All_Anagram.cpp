//More detailed description in strings folder
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
