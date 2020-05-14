class TrieNode{
public:
  char val;
  bool isEnd;
  unordered_map<char, TrieNode *> um;
  TrieNode(int x): val(x), isEnd(false){}
}
class Trie{
  TrieNode *root;
public:
  Trie(){
    root = new TrieNode('/'); //Root Index initialized with / sign
  }
  //====================================================================
  // Insertion
  void insertWord(TrieNode *root,string word){
    if(word.size() == 0){
      root->isEnd = true; //Marks the last character as end character
      return;
    }
    if(root->um.find(word[0]) != root->um.end()){ //If character present already

    }
    else{
      root->um[word[0]] = new TrieNode(word[0]);
    }
    //Recursive call to create new node or add to existing one
    //This would make sure that the trie is connected
    insertWord(root->um[word[0]] , word.substr(1));

  }
  void insert(string word){
    insertWord(root,word);
  }
  //====================================================================
  //Searching
  bool ifPresent(TrieNode *root,string word){
    if(word.size() == 0){
      if(root->isEnd == true){
        return true;
      }
      return false;
    }
    if(root->um.find(word[0]) == root->um.end()) return false;
    return ifPresent(root->um[word[0]],word.substr(1));
  }
  bool search(string word){
    return ifPresent(root,word);
  }
//====================================================================
  bool startsWith(string prefix){
    TrieNode *curr = root;
    for(char c: prefix){
      if(curr->um.find(c) == curr->um.end()) return false;
      curr = curr->um[c];
    }
    return true;
  }
}
//====================================================================
//====================================================================


/////Leetcode Discussion Solution using array of TrieNodes
class TrieNode {
    public:
        bool isEnd = false;
        TrieNode *children[26];
        TrieNode() {
            for (int i = 0; i < 26; i++)
                children[i] = NULL;

            isEnd = false;
        }
};

class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] == NULL) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
       TrieNode * node = root;
       for (char cur : word) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
       }
        if (node->isEnd == true) {
            return 1;
        }
        return 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for (char cur : prefix) {
            int index = cur - 97;
            if (node->children[index] != NULL) {
                node = node->children[index];
                continue;
            }
            return 0;
       }
        return 1;
    }
};
