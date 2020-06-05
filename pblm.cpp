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

void solve(){
  string s;
  cin>>s;
  int best = 0, curr = 1;
  for(int i=1; i<s.size(); i++){
    if(s[i] != s[i-1]){
      best = max(best,curr);
      curr = 0;
    }
    curr++;
  }
  best = max(best,curr);
  cout<<best<<endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // #ifndef ONLINE_JUDGE
  // freopen("D:/CP/input.txt","r",stdin);
  // freopen("D:/CP/output.txt","w",stdout);
  // #endif
  solve();
  return 0;
}
