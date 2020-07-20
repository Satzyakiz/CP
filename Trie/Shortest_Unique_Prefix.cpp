// Find shortest unique prefix to represent each word in the list.
//
// Example:
//
// Input: [zebra, dog, duck, dove]
// Output: {z, dog, du, dov}
// where we can see that
// zebra = z
// dog = dog
// duck = du
// dove = dov


class TrieNode{
  public:
    char c;
    int freq;
    unordered_map<char,TrieNode *> child;
    bool isEnd;
    TrieNode(){ c = '#'; freq = -1;}
    TrieNode(char ch){ c = ch; freq = 1; }
};
TrieNode *root;
void insert(TrieNode *root,string s){
    if(s.size() == 0){
        root->isEnd = true;
        return;
    }
    if(root->child.find(s[0]) != root->child.end()){
        root->child[s[0]]->freq++;
        insert(root->child[s[0]],s.substr(1));
    }else{
        root->child[s[0]] = new TrieNode(s[0]);
        insert(root->child[s[0]],s.substr(1));
    }

}
void get(TrieNode *root,string s, string &curr){
    if(s.size() == 0){
        return;
    }
    curr += s[0];
    if(root->child[s[0]]->freq == 1){
        return;
    }
    get(root->child[s[0]],s.substr(1),curr);
}
vector<string> Solution::prefix(vector<string> &A) {
    root = new TrieNode();
    for(string &s: A){
        insert(root,s);
    }
    vector<string> ans;
    for(string &s: A){
        string temp ="";
        get(root,s,temp);
        ans.push_back(temp);
    }
    return ans;
}
