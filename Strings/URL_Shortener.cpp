
// Design a system that takes big URLs like 
// “http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/”
// and converts them into a short 6 character URL. It is given that URLs
// are stored in database and every URL has an associated integer id.
// So your program should take an integer id and generate a 6 character long URL.
//
// A URL character can be one of the following
//
// A lower case alphabet [‘a’ to ‘z’], total 26 characters
// An upper case alphabet [‘A’ to ‘Z’], total 26 characters
// A digit [‘0′ to ‘9’], total 10 characters
// There are total 26 + 26 + 10 = 62 possible characters.
//
// So the task is to convert an integer (database id) to a base 62
// number where digits of 62 base are
// "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
void URL(int n){
    string URLstr = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string ans = "";
    while(n){
        ans = URLstr[n % 62] + ans;
        n /= 62;
    }
    cout<<ans<<endl;
}
void solve(){
    int n;
    cin>>n;
    URL(n);
    cout<<n<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
