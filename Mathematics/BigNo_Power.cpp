// Find (a^b)%m
// Given three numbers a, b and m where 1<=b,m<=10^6 and ‘a’
// may be very large and contains upto 10^6 digits. The task is to find (a^b)%m.

#include <bits/stdc++.h>
using namespace std;


void solve(){
    int b,m;
    string a;
    cin>>a>>b>>m;
    long long no = 0;
    for(int i=0; i<a.size(); i++){
        no = (no*10) + (a[i] - '0');
        no %= m; //get the modulo at every step
    }
    if(b == 0){
        cout<<"1\n"<<endl;
        return;
    }
    if(b == 1){
        cout<<no<<endl;
        return;
    }
    long long ans = no;
    long long mul = ans;
    for(int i=2; i<=b; i++){
        ans = (ans * mul) % m;
    }
    cout<<ans<<endl;

}
int main() {
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
