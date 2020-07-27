// Given an integer, the task is to find factorial of the number.
// Input
// 3
// 5
// 10
// 2
// Output
// 120
// 3628800
// 2

#include<bits/stdc++.h>
using namespace std;
#define MAX 500000
void multiply(int ANS[],int no, int &size){
    int carry = 0;
    for(int i=0; i<size; i++){
        ANS[i] *= no;
        ANS[i] += carry;
        carry = ANS[i] / 10;
        ANS[i] %= 10;
    }
    while(carry){
        ANS[size++] = carry%10;
        carry /= 10;
    }
}
string fact(int n){
    int ANS[MAX],size = 1;
    memset(ANS,0, sizeof(ANS));
    ANS[0] = 1;
    string ans = "";
    for(int i=n; i>1; i--){
        multiply(ANS, i, size);
    }
    for(int i=size-1; i >=0; i--)
        ans += to_string(ANS[i]);

    return ans;
}

void solve(){
    int s;
    cin>>s;
    cout<<fact(s)<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
