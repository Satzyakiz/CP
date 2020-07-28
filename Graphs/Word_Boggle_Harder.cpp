// Given a dictionary, a method to do lookup in dictionary and a M x N
// board where every cell has one character. Find all possible words
// that can be formed by a sequence of adjacent characters.
// Note that we can move to any of 8 adjacent characters, but a
// word should not have multiple instances of same cell.
//
// Example:
//
// Input: dictionary[] = {"GEEKS", "FOR", "QUIZ", "GO"};
//        boggle[][]   = {{'G','I','Z'},
//                        {'U','E','K'},
//                        {'Q','S','E'}};
//
// Output:  Following words of dictionary are present
//          GEEKS, QUIZ

// use set instead of vector to avoid sorting
#include<bits/stdc++.h>
using namespace std;

bool present(vector<vector<char> >& board,string s, int i,int j){
    if(s.size() == 0)
        return true;
    if(i<0 || j < 0 ||i>=board.size() || j >= board[i].size() || board[i][j] != s[0])
        return false;
    char c = board[i][j];
    board[i][j] = '1';
    bool check = present(board,s.substr(1), i+1,j) ||
                 present(board,s.substr(1), i-1,j) ||
                 present(board,s.substr(1), i,j-1) ||
                 present(board,s.substr(1), i,j+1) ||
                 present(board,s.substr(1), i+1,j+1) ||
                 present(board,s.substr(1), i-1,j-1) ||
                 present(board,s.substr(1), i+1,j-1) ||
                 present(board,s.substr(1), i-1,j+1);
    board[i][j] = c;
    return check;
}
vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {

    vector<string> ans;
    unordered_map<char,vector<pair<int,int>>> um;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            um[board[i][j]].push_back({i,j});
        }
    }

    for(string &s: dictionary){

        for(auto itr = um[s[0]].begin(); itr != um[s[0]].end(); itr++){
            int i = itr->first, j = itr->second;
            if(present(board,s, i,j)){
                ans.push_back(s);
                break;
            }
        }
    }
    return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<string> words(n);
    for(int i=0; i<n; i++) cin>>words[i];
    int m;
    cin>>m>>n;
    vector<vector<char>> board(m,vector<char>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>board[i][j];
    vector<string> ans = boggle(board,words);
    if(ans.size() == 0){
        cout<<"-1\n";
        return;
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(string &s: ans)
        cout<<s<<" ";
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
