// Let's play the minesweeper game (Wikipedia, online game)!
//
// You are given a 2D char matrix representing the game board. 'M'
// represents an unrevealed mine, 'E' represents an unrevealed empty square,
// 'B' represents a revealed blank square that has no adjacent
// (above, below, left, right, and all 4 diagonals) mines, digit
// ('1' to '8') represents how many mines are adjacent to this revealed
// square, and finally 'X' represents a revealed mine.
//
// Now given the next click position (row and column indices) among all
// the unrevealed squares ('M' or 'E'), return the board after revealing
// this position according to the following rules:
//
// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change
// it to revealed blank ('B') and all of its adjacent unrevealed squares
// should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed,
// then change it to a digit ('1' to '8') representing the number of
// adjacent mines.
// Return the board when no more squares will be revealed.
//
// Input:
//
// [['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'M', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E']]
//
// Click : [3,0]
//
// Output:
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
//  Input:
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Click : [1,2]
//
// Output:
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'X', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]


 bool isBomb(vector<vector<char>>& board,int i,int j){
    if(i >= 0 && j >= 0 && i < board.size() && j < board[i].size() && board[i][j] == 'M')
        return true;
    return false;
}
bool isSafe(vector<vector<char>>& board, int i,int j){
    if(i >= 0 && j >= 0 && i < board.size() && j < board[i].size() && board[i][j] == 'E')
        return true;
    return false;
}
void DFS(vector<vector<char>>& board, int i,int j){
    board[i][j] = 'B';
    int val = 0;
    if(isBomb(board,i+1,j)) val++;
    if(isBomb(board,i-1,j)) val++;
    if(isBomb(board,i,j+1)) val++;
    if(isBomb(board,i,j-1)) val++;
    if(isBomb(board,i+1,j+1)) val++;
    if(isBomb(board,i+1,j-1)) val++;
    if(isBomb(board,i-1,j+1)) val++;
    if(isBomb(board,i-1,j-1)) val++;

    if(val){
        board[i][j] = val + '0';
        return;
    }

    if(isSafe(board,i+1,j)) DFS(board,i+1,j);
    if(isSafe(board,i-1,j)) DFS(board,i-1,j);
    if(isSafe(board,i,j+1)) DFS(board,i,j+1);
    if(isSafe(board,i,j-1)) DFS(board,i,j-1);
    if(isSafe(board,i+1,j+1)) DFS(board,i+1,j+1);
    if(isSafe(board,i+1,j-1)) DFS(board,i+1,j-1);
    if(isSafe(board,i-1,j+1)) DFS(board,i-1,j+1);
    if(isSafe(board,i-1,j-1)) DFS(board,i-1,j-1);
}
vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int x = click[0], y = click[1];
    if(board[x][y] == 'M'){
        board[x][y] = 'X';
        return board;
    }
    DFS(board, x, y);
    return board;
}
