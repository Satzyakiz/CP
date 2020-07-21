// Generate all prime numbers between two given numbers.
// Input:
// 2
// 1 10
// 3 5
// Output:
// 2 3 5 7
// 3 5

#include<bits/stdc++.h>
using namespace std;
int sieve[100001];
void solve(){
    int s,e;
    cin>>s>>e;
    for(int i=s; i<=e; i++){
        if(sieve[i] == 0)
            cout<<i<<" ";
    }
    cout<<endl;

}
void initialize(){
    sieve[0] = sieve[1] = 1;
    for(int i=2; i*i<100001; i++){
        if(sieve[i] == 0)
            for(int j=i*i; j<=1e5; j+=i){
                sieve[j] = 1;
            }
    }
}
int main(){
    initialize();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
