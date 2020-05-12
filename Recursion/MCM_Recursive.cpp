
// IP:
// 5
// 40 20 30 10 30
// OP:
// 26000

#include<bits/stdc++.h>
using namespace std;

int solveMCM(vector<int> arr,int i,int j){
  if(i >= j) return 0;
  int k,minVal=INF;
  for(k=i; k<j; k++){
    int temp = solveMCM(arr,i,k) + solveMCM(arr,k+1,j)
                + arr[i-1]*arr[k]*arr[j];
    minVal = min(minVal,temp);
  }
  return minVal;
}


int main(){
  int n,i;
  cin>>n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  cout<<solveMCM(arr,1,n-1)<<endl;
  return 0;
}
