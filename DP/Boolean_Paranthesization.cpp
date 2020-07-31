// Given a boolean expression with following symbols.
//
// Symbols
//     'T' ---> true
//     'F' ---> false
//
// And following operators filled between symbols
//
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
//
// Count the number of ways we can parenthesize the expression so
// that the value of expression evaluates to true.
//
// Input:
// 2
// 7
// T|T&F^T
// 5
// T^F|F
//
// Output:
// 4
// 2

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1003
int helper(string tf, string operators){
    int n = tf.size();
    vector<vector<int>> F(n,vector<int>(n)), T(n,vector<int>(n));

    for(int i=0; i<n; i++){
        if(tf[i] == 'T'){
            T[i][i] = 1;
        }else if(tf[i] == 'F'){
            F[i][i] = 1;
        }
    }
    int a,b,c,d,e,f;
    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n-len+1; i++){
            int j = i+len-1;
            e = f = 0;
            for(int k = i; k<j; k++){

                a = T[i][k], b = F[i][k];
                c = T[k+1][j], d = F[k+1][j];

                if (operators[k] == '&') {
                    e += a*c;
                    f += a*d + b*c + b*d;
                }
                if (operators[k] == '|') {
                    e += a*c + a*d + c*b;
                    f += b*d;
                }
                if (operators[k] == '^') {
                    e += a*d + b*c;
                    f += a*c + b*d;
                }
            }

            T[i][j] = (e % MOD);
            F[i][j] = (f % MOD);
        }
    }

    return T[0][n-1];
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    string operators = "", tf = "";
    for(char &c: s){
        if(c =='T' || c == 'F')
            tf += c;
        else
            operators += c;
    }

    cout<<helper(tf,operators)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
