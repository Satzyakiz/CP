//Same as the other one, just blank spaces are represented as '.' and queen is represented as 'Q'.
bool isSafe(vector<string> &b,int row,int col){
  for(int j=0; j<col; j++){
    if(b[row][j] == 'Q') return false;
  }
  for(int i=row,j=col; i>=0 && j>=0; i--,j--){
    if(b[i][j] == 'Q') return false;
  }
  for(int i=row,j=col; i<b.size() && j>=0; i++,j--){
    if(b[i][j] == 'Q') return false;
  }
  return true;
}

void solveNQ(vector<vector<string>> &ans,vector<string> &b,int col){
  if(col >= b.size()){
      ans.emplace_back(b);
      return;
  }
  for(int i=0; i<b.size(); i++){
    if(isSafe(b,i,col)){
      b[i][col] = 'Q';
      solveNQ(ans,b,col+1); //In order to get all possible combinations we are simply calling this function.
      b[i][col] = '.'; //Backtracking, as previous arrangement was not possible
    }
  }
}
vector<vector<string>> solveNQueens(int A) {
    vector<vector<string>> ans;
    vector<string> b;
    string r = "";
    for(int i=0; i<A; i++) r+=".";
    for(int i=0; i<A; i++) b.emplace_back(r);
    solveNQ(ans,b,0);
    return ans;
}
