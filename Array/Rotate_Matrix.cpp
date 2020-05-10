
// 90 degree rotation
// IP:
// 1   2   3   4
// 5   6   7   8
// 9   10  11  12
// 13  14  15  16
// OP:
// 13  9   5  1
// 14  10  6  2
// 15  11  7  3
// 16  12  8  4
void rotateMatrix(vector<vector<int>> A){
  //1st loops
  for(int i=0; i<A.size(); i++){
    for(int j=i+1; j<A.size(); j++){
      swap(A[i][j],A[j][i]);
    }
  }
  //2nd loops
  for(int i=0; i<A.size(); i++){
    for(int j=0; j<A/size()/2; j++){
      swap(A[i][j],A[i][A.size()-1-j]);
    }
  }
}
// After 1st loops:
// 1  5  9   13
// 2  6  10  14
// 3  7  11  15
// 7  8  12  16
//
// After 2nd loop:
// 13  9   5  1
// 14  10  6  2
// 15  11  7  3
// 16  12  8  7
