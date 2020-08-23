
// In English, we have a concept called root, which can be followed by 
// some other words to form another longer word - let's call this word
// successor. For example, when the root "an" is followed by the successor
// word "other", we can form a new word "another".
//
// Given a dictionary consisting of many roots and a sentence consisting of
// words spearted by spaces. You need to replace all the successors in the
// sentence with the root forming it. If a successor can be replaced by more
// than one root, replace it with the root with the shortest length.
//
// Return the sentence after the replacement.
//
//
//
// Example 1:
//
// Input: dictionary = ["cat","bat","rat"],
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 2:
//
// Input: dictionary = ["a","b","c"],
// sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"
// Example 3:
//
// Input: dictionary = ["a", "aa", "aaa", "aaaa"],
// sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
// Output: "a a a a a a a a bbb baba a"
// Example 4:
//
// Input: dictionary = ["catt","cat","bat","rat"],
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Example 5:
//
// Input: dictionary = ["ac","ab"],
// sentence = "it is abnormal that this solution is accepted"
// Output: "it is ab that this solution is ac"

class TrieNode{
    public:
        TrieNode(){
            isEnd = false;
        }
        unordered_map<char, TrieNode *> children;
        bool isEnd;
};
void insertWord(TrieNode *root,string word){
    if(word.size() == 0){
        root->isEnd = true;
        return;
    }
    char c = word[0];
    word = word.substr(1);
    if(root->children.find(c) != root->children.end()){
        insertWord(root->children[c],word);
    }else{
        root->children[c] = new TrieNode();
        insertWord(root->children[c],word);
    }
}
string check(TrieNode *root,string word, string temp = ""){

    if(root->isEnd){
        return temp;
    }
    char c = word[0];
    word = word.substr(1);
    temp += c;
    if(word.size() == 0){
        return "";
    }
    if(root->children.find(c) == root->children.end()){
        return "";
    }

    return check(root->children[c], word, temp);
}
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode *root = new TrieNode();
        for(string &word: dictionary){
            insertWord(root,word);
        }

        string ans = "";
        stringstream ss(sentence);
        string word;
        while(ss >> word){
            string temp = check(root,word);
            if(temp == ""){
                ans += word + " ";
            }else{
                ans += temp + " ";
            }
        }
        ans.pop_back();
        return ans;
    }
};
