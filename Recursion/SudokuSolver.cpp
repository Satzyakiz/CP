#include<bits/stdc++.h>
using namespace std;

void printBoard(vector<vector<int>> &board){
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[i].size(); j++){
      cout<<board[i][j]<<"   ";
    }
    cout<<endl;
  }
}
//check if any location is still unassigned
//If unassigned, assign row and col to that location
bool isUnassigned(vector<vector<int>> &board,int &row,int &col){
  for(row=0; row<board.size(); row++){
    for(col = 0; col<board[row].size(); col++){
      if(board[row][col] == 0) return true;
    }
  }
  return false;
}
//check if a particular no is present in particular row
bool checkInRow(vector<vector<int>> &board,int row,int num){
  for(int j=0; j<board[row].size(); j++){
    if(board[row][j] == num) return true;
  }
  return false;
}
//check if a particular no is present in a particular col
bool checkInCol(vector<vector<int>> &board,int col,int num){
  for(int i=0; i<board.size(); i++){
    if(board[i][col] == num) return true;
  }
  return false;
}
//check if a particular no is present in a particular sub grid
bool checkInSubGrid(vector<vector<int>> &board,int row,int col,int num){
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      if(board[row+i][col+j] == num) return true;
    }
  }
  return false;
}
//combination of all the checks present
bool isSafe(vector<vector<int>> &board,int row,int col,int num){
  return  board[row][col] == 0 &&
          !checkInRow(board,row,num) &&
          !checkInCol(board,col,num) &&
          !checkInSubGrid(board,row-row%3,col-col%3,num);
}
bool SudokuSolver(vector<vector<int>> &board){
  int row,col;
  if(!isUnassigned(board,row,col))  return true; //It means all the empty spaces are filled.

  for(int num=1; num <=9; num++){
    if(isSafe(board,row,col,num)){
      board[row][col] = num;
      if(SudokuSolver(board)) return true; // IF the computed arrangement is valid, no need to do further computation
      board[row][col] = 0; //backtracking
    }
  }
  return false;
}
int main(){
  vector<vector<int>> board {
                              {3, 0, 6, 5, 0, 8, 4, 0, 0},
                              {5, 2, 0, 0, 0, 0, 0, 0, 0},
                              {0, 8, 7, 0, 0, 0, 0, 3, 1},
                              {0, 0, 3, 0, 1, 0, 0, 8, 0},
                              {9, 0, 0, 8, 6, 3, 0, 0, 5},
                              {0, 5, 0, 0, 9, 0, 6, 0, 0},
                              {1, 3, 0, 0, 0, 0, 2, 5, 0},
                              {0, 0, 0, 0, 0, 0, 0, 7, 4},
                              {0, 0, 5, 2, 0, 6, 3, 0, 0}
                            };
  if(SudokuSolver(board)){
    cout<<"Possible\n";
    printBoard(board);
  }
  else{
    cout<<"Not Possible\n";
  }
}
