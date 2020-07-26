
#include <bits/stdc++.h>
using namespace std;
int get(string x){
    reverse(x.begin(),x.end());
    int ans = 0;
    for(int i=0; i<x.size(); i++){
        if(x[i] == '1'){
            ans += pow(2,i);
        }
    }
    return ans;
}
void helper(int m,int ma,int &ans){
    bitset<32> b1(m), b2(ma);
    string a = "",b = "";
    int i;
    for(i=31; i>=0; i--){
        if(b1[i] != 0)
            break;
    }
    for( ; i>=0; i--){
        a += to_string(b1[i]);
    }

    for(i=31; i>=0; i--){
        if(b2[i] != 0)
            break;
    }
    for( ; i>=0; i--){
        b += to_string(b2[i]);
    }
    // cout<<a<<endl<<b<<endl;
    string x = a + b;
    string y = b + a;
    // cout<<x<<endl<<y<<endl;
    int iX = get(x), iY = get(y);
    ans = max(ans, iX - iY);
}
void solve(){
    int n,xx,m = INT_MAX,ma = INT_MIN;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int ans = INT_MIN;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            helper(arr[i],arr[j],ans);
        }
    }
    // cout<<"==================================\n";
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
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
