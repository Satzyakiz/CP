//Implementation of Binary Indexed Tree or Fenwick Tree
#include<bits/stdc++.h>
using namespace std;

vector<int> BIT;
//index & -index ==> provides the location of first 1 bit
int sum(int index){
  int ans = 0;
  while(index > 0){
    ans += BIT[index];
    index -= (index & -index);
  }
  return ans;
}
int rangeSum(int l,int r){
  return sum(r) - sum(l-1);
}
void update(int index,int value){
  while(index <= BIT.size()){
    BIT[index] += value;
    index += (index & -index);
  }
}

void createBIT(vector<int> arr){
  BIT.clear();
  BIT.resize(arr.size()+1);
  for(int i=1; i<=arr.size(); i++)
    update(i,arr[i-1]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  vector<int> arr{1,3,2,-2,4,5};
  createBIT(arr);
  //Range Query
  cout<<"Sum between index 2 to 4:\n";
  cout<<rangeSum(2,4)<<endl;
  cout<<"Sum between index 1 to 6:\n";
  cout<<rangeSum(1,6)<<endl;
  cout<<"Sum between index 4 to 6:\n";
  cout<<rangeSum(4,6)<<endl;
  //Point Update
  //Adding 5 in index 4, i.e a[4] = -2 + 5 = 3
  update(4,5);
  cout<<"After Point Update:\n";
  cout<<"Sum between index 1 to 6:\n";
  cout<<rangeSum(1,6)<<endl;
  return 0;

}

// O/P:
// Sum between index 2 to 4:
// 3
// Sum between index 1 to 6:
// 13
// Sum between index 4 to 6:
// 7
// After Point Update:
// Sum between index 1 to 6:
// 18
