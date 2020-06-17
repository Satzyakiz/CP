#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
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
#define MOD 1000000007
bool checkLeft(string &s,int i,int k){
  for(int j=1; j<=k && (i-j) >= 0; j++){
    if(s[i-j] == '1'){
      return true;
    }
  }
  return false;
}
bool checkRight(string &s,int i,int k){
  for(int j=1; j<=k && (i+j)<s.size(); j++){
    if(s[i+j] == '1'){
      return true;
    }
  }
  return false;
}
void solve(){
  int n,k;
  cin>>n>>k;
  string s;
  cin.ignore();
  cin>>s;
  int count = 0;
  for(int i=0; i<n; i++){
    if(s[i] == '1'){
      i = i+k;
    }else{
      bool left = checkLeft(s,i,k);
      bool right = checkRight(s,i,k);
      if(left == false && right == false){
        count++;
        s[i] = '1';
        i = i+k;
      }
    }
  }
  cout<<count<<endl;
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
  while(t--)
    solve();
  return 0;
}
