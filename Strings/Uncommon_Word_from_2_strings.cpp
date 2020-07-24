
// We are given two sentences A and B.  (A sentence is a string of space 
// separated words. Each word consists only of lowercase letters.)
//
// A word is uncommon if it appears exactly once in one of the sentences,
// and does not appear in the other sentence.
//
// Return a list of all uncommon words.
//
// You may return the list in any order.
//
// Example 1:
//
// Input: A = "this apple is sweet", B = "this apple is sour"
// Output: ["sweet","sour"]
// Example 2:
//
// Input: A = "apple apple", B = "banana"
// Output: ["banana"]

vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string,int> um;
    istringstream ss(A+" "+B);
    string word;
    while(ss>>word){
        cout<<word<<endl;
        um[word]++;
    }
    vector<string> ans;
    for(auto itr = um.begin(); itr != um.end(); itr++){
        if(itr->second == 1)
            ans.emplace_back(itr->first);
    }
    return ans;
}
