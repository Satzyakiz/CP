// Given a non-empty string s and a dictionary wordDict containing a list
// of non-empty words, add spaces in s to construct a sentence where each
// word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
// The same word in the dictionary may be reused multiple times in
// the segmentation.
// You may assume the dictionary does not contain duplicate words.
// Example 1:
//
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
// Example 2:
//
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]


unordered_map<string,vector<string>> um;
vector<string> join(string w, vector<string> prev){
    for(int i=0; i<prev.size(); i++){
        prev[i] += " "+w;
    }
    return prev;
}
vector<string> helper(string s,unordered_set<string> &dict){
    if(um.count(s))
        return um[s];
    vector<string> ans;
    if(dict.count(s)){
        ans.push_back(s);
    }
    for(int i=1; i<s.size(); i++){
        string word = s.substr(i);
        if(dict.count(word)){
            string rem = s.substr(0,i);
            vector<string> prev = join(word, helper(rem, dict));
            ans.insert(ans.end(), prev.begin(),prev.end());
        }
    }
    return um[s] = ans;
}
vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(),wordDict.end());
    return helper(s,dict);
}
// ======================================================================
//Trie Solution
class TrieNode{
    public:
        bool isEnd;
        unordered_map<char,TrieNode *> children;
        TrieNode(){
            isEnd = false;
        }
};
class Solution {
public:
    TrieNode *root;


    void buildTrie(string s){
        TrieNode *curr = root;
        for(char &c: s){
            if(curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }


    vector<string> DFS(string s,int index,unordered_map<int, vector<string>> &um){
        vector<string> ans;
        if(index == s.size()){
            ans.push_back("");
            return ans;
        }
        if(um.find(index) != um.end())
            return um[index];

        TrieNode *curr = root;
        for(int i=index; i<s.size(); i++){
            if(curr->children.find(s[i]) == curr->children.end())
                break;
            curr = curr->children[s[i]];
            if(curr->isEnd){
                int length = i-index+1;
                string temp = s.substr(index,length);
                if(i < s.size()-1){
                    temp += " ";
                }
                vector<string> next = DFS(s,i+1,um);
                for(string &str: next){
                    string t = temp+str;
                    ans.push_back(t);
                }
            }
        }

        return um[index] = ans;
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for(string &str: wordDict){
            buildTrie(str);
        }
        unordered_map<int, vector<string>> um;
        return DFS(s,0,um);
    }
};
