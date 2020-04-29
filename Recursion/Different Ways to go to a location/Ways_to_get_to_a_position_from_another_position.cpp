// The robot can only move either down or right at any point in time.
// The robot is trying to reach the bottom-right corner of the grid .
//
// How many possible unique paths are there?
//

int ways(int A,int B){
  if(A == B && A == 1) return 1;
  if(A == 1 || B == 1) return 1;
  return ways(A-1,B)+ways(A,B-1);
}

// Input : A = 2, B = 2
// Output : 2
//
// 2 possible routes : (0, 0) -> (0, 1) -> (1, 1)
//               OR  : (0, 0) -> (1, 0) -> (1, 1)
