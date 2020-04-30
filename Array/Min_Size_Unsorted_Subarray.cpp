// You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
// Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array,
// then the whole array should get sorted.
// If A is already sorted, output -1.

// Approach:
// 1) Get the index whose next index is smaller than the current index.
// 2) Get the minimum and maximum values from its right part.
// 3) In the right part, find the end point, the point beyond which no smaller element is present.
// 4) In the left part, find the start point, which have value more than the minimum of right part.
// 5) Return both index.

vector<int> getIndex(vector<int> arr){
  int n = arr.size();
  if(n == 0 || n == 1) return {-1};
  int i=0;
  while(i<n-1 && A[i] <= A[i+1])
    i++;
  if( i == n-1 ) return {-1};
  int j = i+1, minVal,maxVal,start,end;
  maxVal = minVal = A[i];
  while( j < n){
    if(maxVal > A[j]){
      end = j;
    }
    maxVal = max(maxVal,A[j]);
    minVal = min(minVal,A[j]);
    j++;
  }
  j = i-1;
  while(A[j] > minVal){
    j--;
  }
  start = j+1;
  return {start,end};
}
