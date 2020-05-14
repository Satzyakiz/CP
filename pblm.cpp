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

unordered_map<string,bool> um;
bool isScramble(string a, string b) {
          if(a.size() != b.size()) return false;
          if(a == b) return true;
          string newStr = a+"_"+b;
          if(um.find(newStr) != um.end()) return um[newStr]; //If value already present in map
          int n = a.size();
          bool res = false;
          for(int i=1; i<n; i++){
            bool swap = isScramble(a.substr(0,i),b.substr(n-i,i)) == true
                && isScramble(a.substr(i,n-i),b.substr(0,n-i)) == true;
            bool noswap = isScramble(a.substr(0,i),b.substr(0,i)) == true
                && isScramble(a.substr(i,n-i),b.substr(i,n-i)) == true;
            if(swap || noswap){
              res = true;
              break;
            }
          }
          um[newStr] = res;
          return res;
        }


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("D:/CP/input.txt","r",stdin);
  freopen("D:/CP/output.txt","w",stdout);
  #endif
  string s1,s2;
  cin>>s1;
  cin.ignore();
  cin>>s2;

  if(isScramble(s1,s2)){
    cout<<"True";
  }
  else{
    cout<<"False";
  }
  return 0;
}
