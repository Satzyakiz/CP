// A string S of lowercase English letters is given. 
// We want to partition this string into as many parts as
// possible so that each letter appears in at most one part,
// and return a list of integers representing the size of these parts.
//
//
//
// Example 1:
//
// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect,
// because it splits S into less parts.

vector<int> partitionLabels(string S) {
    unordered_map<char,int> um;
    for(int i=0; i<S.size(); i++) um[S[i]] = i;
    int start = 0, last = 0;
    vector<int> ans;
    for(int i=0; i<S.size(); i++){
        last = max(last, um[S[i]]);
        if(last == i){
            ans.push_back(last - start + 1);
            start = last + 1;
        }
    }
    return ans;
}
