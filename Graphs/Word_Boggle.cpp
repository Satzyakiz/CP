// Given a dictionary of distinct words and an M x N board where every
// cell has one character. Find all possible words from the dictionary
// that can be formed by a sequence of adjacent characters on the board.
// We can move to any of 8 adjacent characters, but a word should not
// have multiple instances of the same cell.
//
// Input:
// 1
// 4
// GEEKS FOR QUIZ GO
// 3 3
// G I Z
// U E K
// Q S E
// Output:
// GEEKS QUIZ

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
