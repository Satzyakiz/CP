// Example 1:
// Input: board = ["O  ", "   ", "   "]
// Output: false
// Explanation: The first player always plays "X".
//
// Example 2:
// Input: board = ["XOX", " X ", "   "]
// Output: false
// Explanation: Players take turns making moves.
//
// Example 3:
// Input: board = ["XXX", "   ", "OOO"]
// Output: false
//
// Example 4:
// Input: board = ["XOX", "O O", "XOX"]
// Output: true

bool validTicTacToe(vector<string>& board) {
    bool X = false, O = false;
    int D = 0, RD = 0,turns = 0;
    vector<int> row(3),col(3);
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if(board[i][j] == 'X'){
                turns++;
                row[i]++, col[j]++;
                if(i == j){
                    D++;
                }
                if(i + j == 2){
                    RD++;
                }
            }else if(board[i][j] == 'O'){
                turns--;
                row[i]--, col[j]--;
                if(i == j){
                    D--;
                }
                if(i + j == 2){
                    RD--;
                }
            }
        }
    }

    X = row[0] == 3 || row[1] == 3 || row[2] == 3 ||
        col[0] == 3 || col[1] == 3 || col[2] == 3 ||
        D == 3 || RD == 3;
    O = row[0] == -3 || row[1] == -3 || row[2] == -3 ||
        col[0] == -3 || col[1] == -3 || col[2] == -3 ||
        D == -3 || RD == -3;

    if(X && turns == 0) return false;
    if(O && turns == 1) return false;

    return (turns == 0 || turns == 1) && (!X || !O);

}
