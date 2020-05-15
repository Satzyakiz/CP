// 1. Find maximum subarray sum using kadane's algorithm (max)
// 2. Find minimum subarray sum using kadane's algorithm (min)
// 3. Find total sum of the array (sum)
// 4. Now, if sum == min return max
// 5. Otherwise, return maximum ( max, sum - min )

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& A){
          if(A.size() == 0) return 0;
          int maxVal,minVal,tempMaxVal,tempMinVal,sum;
          maxVal = minVal = tempMaxVal = tempMinVal = sum = A[0];
          for(int i=1;i<A.size(); i++){
            tempMaxVal = max(A[i],tempMaxVal + A[i]);
            maxVal = max(maxVal,tempMaxVal);
            tempMinVal = min(A[i],tempMinVal + A[i]);
            minVal = min(minVal,tempMinVal);
            sum += A[i];
          }
          if(sum == minVal) return maxVal;
          return max(maxVal,sum-minVal);
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++) cin>>arr[i];
  cout<<maxSubarraySumCircular(arr)<<endl;
  return 0;
}
