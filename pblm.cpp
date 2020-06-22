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
#define MOD 1000000007
void solve(){
    unordered_map<int,bool> um;
    int n,b,m,x;
    cin>>n>>m;
    int count = 0,count2 = 0;
    for(int i=0; i<n; i++){
        cin>>x;
        if(um.find(x) == um.end() && x > 0 && x < m)
            count++;
        um[x] = true;
        count2++;
    }
    if(count == 0){
        cout<<"-1\n";
        return;
    }
    else if(count == m-1){
        cout<<count2<<endl;
    }else{
        count = 0;
        for(int i=1; i<m; i++){
            if(um.find(i) != um.end())
                count++;
            else
                break;
        }
        cout<<count<<endl;
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
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
