#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define dbl double
#define endl "\n"
#define fo(i,n) for(int i=0; i<n; i++)
#define FOR(i,n,k) for(int i=0; i<n; i+=k)
#define sFOR(i,s,n) for(int i=s; i<n; i++)
#define vi vector<int>
#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())
#define eb(x) emplace_back(x)
#define UM unordered_map<int,int>
#define INF INT_MAX
#define NEG_INF INT_MIN
#define MOD 1000000000+7

vector<int> BIT1;
vector<int> BIT2;


int sum(vector<int> &BIT,int index){
  int ans = 0;
  while(index > 0){
    ans += BIT[index];
    index -= (index & -index);
  }
  return ans;
}
int prefixSum(int index){
  return sum(BIT1,index)*index - sum(BIT2,index);
}
int rangeSum(int l,int r){
  return prefixSum(r) - prefixSum(l-1);
}
void update(vector<int> &BIT,int index,int value){
  while(index <= BIT.size()){
    BIT[index] += value;
    index += (index & -index);
  }
}
void rangeUpdate(int l,int r,int value){
  update(BIT1,l,value);
  update(BIT1,r+1,-value);
  update(BIT2,l,value * (l-1));
  update(BIT2,r+1,-value*r);
}

void createBIT(vector<int> arr){
  BIT1.clear();
  BIT1.resize(arr.size()+1);
  BIT2.clear();
  BIT2.resize(arr.size()+1);
  for(int i=1; i<=arr.size(); i++)
    update(BIT1,i,arr[i-1]);


}
void displayBIT(){
  for(int x: BIT1){
    cout<<x<<" ";
  }
  cout<<endl;
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
  displayBIT();
  //Range Query
  cout<<"Sum between index 2 to 4:\n";
  cout<<rangeSum(2,4)<<endl;
  cout<<"Sum between index 1 to 6:\n";
  cout<<rangeSum(1,6)<<endl;
  cout<<"Sum between index 4 to 6:\n";
  cout<<rangeSum(4,6)<<endl;
  //Point Update
  //Adding 5 in index 4, i.e a[4] = -2 + 5 = 3

  // update(4,5);
  // displayBIT();
  // cout<<"After Point Update:\n";
  // cout<<"Sum between index 1 to 6:\n";
  // cout<<rangeSum(1,6)<<endl;
  //Range Update, Point Query
  rangeUpdate(2,4,5);
  displayBIT();
  cout<<"After Range Update:\n";
  cout<<rangeSum(1,6)<<endl;
  return 0;
}
