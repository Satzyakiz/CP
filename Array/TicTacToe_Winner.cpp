bool check(vector<vector<char>> &mat){
    //Left Diagonal
    if(mat[0][0] != '.' && mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2])
        return true;

    //Right Diagonal
    if(mat[0][2] != '.' && mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0])
        return true;

    //Same Row and Column
    for(int j=0; j<3; j++){
        if(mat[j][0] != '.' && mat[j][0] == mat[j][1] && mat[j][1] == mat[j][2])
            return true;
        if(mat[0][j] != '.' && mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j])
            return true;
    }
    return false;
}
string tictactoe(vector<vector<int>>& moves) {
    vector<vector<char>> mat(3,vector<char>(3,'.'));
    for(int i=0; i<moves.size(); i++){
        char x = moves[i][0], y = moves[i][1];
        if(i % 2 == 0){
            mat[x][y] = 'X';
        }else{
            mat[x][y] = 'O';
        }
        if(check(mat)){
            if(i%2 == 0)
                return "A";
            else
                return "B";
        }
    }
    return moves.size() == 9 ? "Draw" : "Pending";
}
