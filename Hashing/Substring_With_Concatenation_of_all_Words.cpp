// You are given a string, s, and a list of words, words, that are all of
// the same length. Find all starting indices of substring(s) in s that is
// a concatenation of each word in words exactly once and without any
// intervening characters.
//
// Example 1:
//
// Input:
//   s = "barfoothefoobarman",
//   words = ["foo","bar"]
// Output: [0,9]
// Example 2:
//
// Input:
//   s = "wordgoodgoodgoodbestword",
//   words = ["word","good","best","word"]

vector<int> findSubstring(string s, vector<string>& words) {
    int n = s.size(), m = words.size();
    vector<int> ans;
    if(n < m  || m == 0)
        return ans;
    int l = words[0].size();
    if(n < m*l)
        return ans;
    unordered_map<string,int> um1;
    for(string str: words)
        um1[str]++;

    for(int i=0; i<n-m*l+1; i++){
        if(um1.find(s.substr(i,l)) != um1.end()){
            unordered_map<string,int> um2 = um1;
            int count = 0;
            int j = i;
            while(um2[s.substr(j,l)] > 0 && count < m){
                um2[s.substr(j,l)]--;
                j += l;
                count++;
            }
            if(count == m){
                ans.emplace_back(i);
            }
        }
    }
    return ans;
}
