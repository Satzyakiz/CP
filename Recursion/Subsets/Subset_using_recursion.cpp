#include<bits/stdc++.h>
using namespace std;

void subset(vector<vector<int>> &ans,vector<int> A, int size, vector<int> currArr){
  if(size == A.size()){
    ans.emplace_back(currArr);
    return;
  }
  subset(ans,A,size+1,currArr);
  vector<int> tempArr(currArr.begin(),currArr.end());
  tempArr.emplace_back(A[size]);
  subset(ans,A,size+1,tempArr);

}

int main(){
  vector<int> arr(5);
  for(int i=1;i<=5; i++){
    arr[i-1] = i;
  }

  vector<vector<int>> ans;
  subset(ans,arr,0,{});
  sort(ans.begin(),ans.end());

  for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[i].size(); j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
