#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> arr;
void solve(){
    arr.emplace_back(0);
    int n,count = 1,x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        for(int j=0; j<x; j++){
            arr.emplace_back(i+1);
        }
    }
    int m;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>x;
        cout<<arr[x]<<endl;
    }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  solve();
  return 0;
}
