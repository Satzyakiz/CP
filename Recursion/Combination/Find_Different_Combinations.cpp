// Find all possible combinations of a certain length(B) within a certain range(A)
// Ex:
// A: 4 and B: 2
// O/P:  {i.e. 4C2}
// [
//   [1,2], [1,3],[1,4],[2,3],[2,4],[3,4]
// ]

// Find all possible combinations of a certain length(B) within a certain range(A)
// Ex:
// A: 4 and B: 2
// O/P:  {i.e. 4C2}
// [
//   [1,2], [1,3],[1,4],[2,3],[2,4],[3,4]
// ]

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
  for(int x: v){
    cout<<x<<" ";
  }
  cout<<endl;
}
void generateCombinations(vector<int> v,int curr,int a,int b, vector<vector<int>> &ans){
  if(v.size() == b){
    printVector(v);
    ans.emplace_back(v); //If we have to return a 2d vector, return this.
    return;
  }
  for(int i=curr; i<=a; i++){
    v.push_back(i);
    generateCombinations(v,i+1,a,b,ans);
    v.pop_back();
  }
  return;
}

int main(){
  int a,b;
  cin>>a>>b;
  vector<vector<int>> ans;
  if(a < b){
    cout<<"Impossible\n";
  }
  if(b == 0){
    cout<<"{}\n";
  }
  generateCombinations({},1,a,b,ans);
  return 0;
}
