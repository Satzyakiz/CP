// Find all possible permutations
// Ex:
// arr = [1,2,3]
// O/P: (3!)
// [
//   [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
// ]

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
  for(int x: v){
    cout<<x<<" ";
  }
  cout<<endl;
}

void generatePermutations(vector<vector<int>> ans, vector<int> arr, int size){
  if(size == arr.size()-1){
    printVector(arr);
    ans.emplace_back(arr); //If we have to return a 2d vector, return this.
    return;
  }
  for(int i=size; i<arr.size(); i++){
    swap(arr[i],arr[size]);
    generatePermutations(ans,arr,size+1);
    swap(arr[i],arr[size]);
  }
  return;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  vector<vector<int>> ans;
  generatePermutations(ans,arr,0);
  return 0;
}
