// mplement a trie with insert, search, and startsWith methods.
//
// Example:
//
// Trie trie = new Trie();
//
// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true

typedef struct TrieNode{
        char val;
        bool ends;
        unordered_map<char,struct TrieNode *> um;
        TrieNode(char c): val(c), ends(false){}
    }TrieNode;
class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('/');
    }

    /** Inserts a word into the trie. */
    void insertVal(TrieNode *root,string word){
        if(word.size() == 0){
            root->ends = true;
            return;
        }
        // TrieNode *child;
        if(root->um.find(word[0]) != root->um.end()){
            // child = root->um[word[0]];
        }
        else{
            root->um[word[0]] = new TrieNode(word[0]);
            // child = root->um[word[0]];
        }
        insertVal(root->um[word[0]],word.substr(1));
    }
    void insert(string word) {
        insertVal(root,word);
    }

    /** Returns if the word is in the trie. */
    bool doSearch(TrieNode *root,string word){
        if(word.size() == 0){
            if(root->ends == true)
                return true;
            else
                return false;
        }
        if(root->um.find(word[0]) != root->um.end()){
            return doSearch(root->um[word[0]],word.substr(1));
        }
        return false;

    }
    bool search(string word) {
        return doSearch(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        unordered_map<char, TrieNode *> temp;

        for(char c: prefix){
            temp = curr->um;
            if(temp.find(c) == temp.end())
                return false;
            else{
                curr = temp[c];
            }
        }
        return true;
    }
};
