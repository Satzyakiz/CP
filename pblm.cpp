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


void solve(ll n){
  vector<ll> arr(n);
  for(int i=0; i<n; i++)
    cin>>arr[i];
  ll ans = arr[0]+1;
  for(int i=1; i<n; i++){
    if(arr[i] > arr[i-1]){
      ans += (arr[i] - arr[i-1]) + 2;
    }else if(arr[i] < arr[i-1]){
      ans += (arr[i-1] - arr[i]) + 2;
    }else{
      ans += 2;
    }
  }

  cout<<ans<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  ll n;
  cin>>n;
  solve(n);
  return 0;
}
