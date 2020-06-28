#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    stack<char> stk;
    n = n/2;
    for(char c: s){
        if(stk.size() == 0){
            stk.push(c);
        }
        else if(c == ')' && stk.top() == '('){
            stk.pop();
            n--;
        }
        else{
            stk.push(c);
        }
    }
    cout<<n<<endl;

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
