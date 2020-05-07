//Get the count of subsets whose sum is equal to S
//IP: [2 3 7 8 10] S = 10
//OP: 3 --> [2 8],[3 7],[10]

#include<bits/stdc++.h>
using namespace std;
//Back to front recursion
int countEqualSumSubset(vector<int> arr,int S,int n,int count){
  if(n == 0){
    if(S == 0){
        count++;
        //This ensures a subset, whose sum is equal to S
        //If this if statement was outside, then partial sum of
        //subset = S would also be considered which is wrong.
    }
    return count;
  }
  if(arr[n-1] <= S){
    count = countEqualSumSubset(arr,S,n-1,count)+countEqualSumSubset(arr,S-arr[n-1],n-1,count);
  }
  else{
    count = countEqualSumSubset(arr,S,n-1,count);
  }
  return count;
}

int main(){
  int n,S;
  cin>>n>>S;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<countEqualSumSubset(arr,S,arr.size(),0)<<endl;
  return 0;
}
