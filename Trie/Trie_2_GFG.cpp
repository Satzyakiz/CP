// Your task is to use the TRIE data structure and search the given string A. 
// If found print 1 else 0.
// Input:
// 1
// 8
// the a there answer any by bye their
// the
// Output:
// 1

#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    char val;
    unordered_map<char,Node *> nextNode;
    bool isEnd;
    Node(char c){
        val = c;
        isEnd = false;
    }
};
class Trie{
public:
    Node *root;
    Trie(){
        root = new Node('#');
    }
    void insert(string s){
        Node *temp = root;
        for(char c: s){
            if(temp->nextNode.find(c) != temp->nextNode.end()){
                temp = temp->nextNode[c];
            }else{
                Node *newNode = new Node(c);
                temp->nextNode[c] = newNode;
                temp = temp->nextNode[c];
            }
        }
        temp->isEnd = true;
    }
    bool find(string s){
        Node *temp = root;
        for(char c: s){
            if(temp->nextNode.find(c) == temp->nextNode.end())
                return false;
            temp = temp->nextNode[c];
        }
        return temp->isEnd;
    }
};

void solve(){
    int n;
    cin>>n;
    Trie t;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        cin.ignore();
        t.insert(s);
    }
    cin>>s;
    cout<<t.find(s)<<endl;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
