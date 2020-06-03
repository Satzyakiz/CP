// Given an array of strings, return all groups of strings that
// are anagrams. Represent a group by a list of integers representing
// the index in the original list. Look at the sample case for clarification.
//
//  Anagram : a word, phrase, or name formed by rearranging the
//  letters of another, such as 'spar', formed from 'rasp'
//  Note: All inputs will be in lower-case.
// Example :
//
// Input : cat dog god tca
// Output : [[1, 4], [2, 3]]

vector<vector<int>> Solution::anagrams(const vector<string> &A) {
    vector<vector<int>> ans;
    unordered_map<string,vector<int>> um;
    for(int i=0; i<A.size(); i++){
        string s = A[i];
        sort(s.begin(),s.end());
        um[s].emplace_back(i+1);
    }
    for(auto i=um.begin(); i!=um.end(); i++){
        ans.emplace_back(i->second);
    }
    return ans;
}
