
// Given a 2D board and a list of words from the dictionary,
// find all words in the board.
//
// Each word must be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once in a word.
//
//
//
// Example:
//
// Input:
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]
//
// Output: ["eat","oath"]

//Brute Force approach


bool present(vector<vector<char>> &board,int x,int y, string &word,int index){
    if(index >= word.size()) return true;
    if(x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] != word[index])
        return false;
    char c = board[x][y];
    board[x][y] = '-1';
    bool ans =  present(board,x+1,y,word,index+1) ||
                present(board,x-1,y,word,index+1) ||
                present(board,x,y-1,word,index+1) ||
                present(board,x,y+1,word,index+1);
    board[x][y] = c;
    return ans;
}
vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ans;
    unordered_map<char,vector<pair<int,int>>> um;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            um[board[i][j]].push_back({i,j});
        }
    }
    for(string &s: words){
        // if(um.find(s[0]) == um.end())
        //     continue;
        for(auto itr = um[s[0]].begin(); itr != um[s[0]].end(); itr++){
            int x = itr->first, y = itr->second;
            if(present(board,x,y,s,0)){
                ans.emplace_back(s);
                break;
            }
        }
    }

    return ans;
}
