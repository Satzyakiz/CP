
// Input 1:
//     A =  [1, 2]
//     B =  [2, 1]
// Output 1:
//     1
int getStartIndex(vector<int> A,vector<int> B){
  int start, currPetrol=0,totalGas,totalDistance,n = A.size();
  start = 0;
  for(int i=0; i<n; i++){
    currPetrol += A[i] - B[i];
    if(currPetrol < 0){
      currPetrol = 0;
      start = i+1;
    }
    totalGas += A[i];
    totalDistance += B[i];
  }
  // if less gass is present than distance to be covered, it is impossible to
  // cover all the distance
  if(totalGas < totalDistance) return -1;
  return start;
}
