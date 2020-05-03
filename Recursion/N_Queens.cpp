#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &mat){
  for(int i=0; i<mat.size(); i++){
    for(int j=0; j<mat[i].size(); j++){
      cout<<mat[i][j]<<" ";
    }
    cout<<endl;
  }
}
//As we are filling from left to right, i.e. from 0...col, we only need to handle the left portion
bool isSafe(vector<vector<int>> &mat,int row,int col){
  //check left part of the row
  for(int j=0; j<col; j++){
    if(mat[row][j]) return false;
  }
  //check upper left diagonal
  for(int i=row,j=col; i>=0 && j>=0; i--,j--){
    if(mat[i][j]) return false;
  }
  //check lower left diagonal
  for(int i=row,j=col; i<mat.size() && j>=0; i++,j--){
    if(mat[i][j]) return false;
  }
  return true;
}

bool solveNQ(vector<vector<int>> &mat,int col){
  if(col >= mat.size()) return true;
  for(int i=0; i<mat.size(); i++){
    if(isSafe(mat,i,col)){
      mat[i][col] = 1;
      if(solveNQ(mat,col+1)) return true;
      mat[i][col] = 0; //Backtracking, as previous arrangement was not possible
    }
  }
  return false;
}

int main(){
  int n;
  cin>>n;
  vector<vector<int>> mat(n,vector<int>(n));
  if(solveNQ(mat,0)){
    cout<<"possible\n";
    printMatrix(mat);
  }
  else{
    cout<<"Not Possible\n";
  }
  return 0;
}
