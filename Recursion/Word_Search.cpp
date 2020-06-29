// Given a 2D board and a word, find if the word exists in the grid.
//
// The word can be constructed from letters of sequentially adjacent cell,
// where "adjacent" cells are those horizontally or vertically neighboring.
// The same letter cell may not be used more than once.
//
// Example:
//
// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]
//
// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.

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
bool exist(vector<vector<char>>& board, string word) {

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(present(board,i,j,word,0))
                return true;
        }
    }
    return false;
}
