// Return True or False if a particular subset is present whose sum is equals to S
// I/P:
// arr = [2 3 7 8 10] sum = 11
// O/P: True
// if sum = 16, O/P: False

//First to last approach
#include<bits/stdc++.h>
using namespace std;

bool subsetSumPresent(vector<int> arr,int S,int index){
  if(S == 0) return true;
  if(index == arr.size()) return false;
  if(arr[index] <= S){
    return subsetSumPresent(arr,S-arr[index],index+1) || subsetSumPresent(arr,S,index+1);
  }
  else{
    return subsetSumPresent(arr,S,index+1);
  }
}

int main(){

  int n,S;
  cin>>n>>S;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  if(subsetSumPresent(arr,S,0)) cout<<"True\n";
  else cout<<"False\n";
}
