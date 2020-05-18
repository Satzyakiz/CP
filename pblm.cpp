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

void chandf(ll a, ll b, ll l, ll r){
  vector<int> z(45,0);
  vi AB(45,0);
  vi lB(45,0);
  vi rB(45,0);
  ll x = a, y = b;
  int i=0;
  while(a){
    AB[i++] = a%2;
    a = a/2;
  }
  i = 0;
  while(b){
    if(!AB[i]){
      AB[i] = b%2;
    }
    i++;
    b /= 2;
  }
  // for(int a: AB) cout<<a<<" ";
  i = 0;
  while(l){
    lB[i++] = l%2;
    l /= 2;
  }
  i = 0;
  while(r){
    rB[i++] = r%2;
    r /= 2;
  }
  int j = 44;
  while(rB[j] == lB[j]){
    z[j] = rB[j];
    j--;
  }
  z[j--] = 0;
  while(j > -1){
    z[j] = AB[j];
    j--;
  }
  // for(int a: z) cout<<a<<" ";
  ll ans = 0;
  for(int i=0; i<45; i++){
    if(z[i] == 1)
      ans += pow(2,i);
  }
  cout<<ans;
  cout<<endl;
}
void solve(){
  ll a,b,l,r;
  cin>>a>>b>>l>>r;
  chandf(a,b,l,r);
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
