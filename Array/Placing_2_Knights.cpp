// How many ways are there to place a black and a white knight on an 
// N * M chessboard such that they do not attack each other?
// The knights have to be placed on different squares. A knight can
// move two squares horizontally and one square vertically (L shaped),
// or two squares vertically and one square horizontally (L shaped).
// The knights attack each other if one can reach the other in one move.
//
// Input:
// 3
// 2 2
// 2 3
// 4 5
//
// Output:
// 12
// 26
// 312

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
bool isValid(int m,int n, int x, int y){
    if(x < 0 || y < 0 || x >= m || y >= n)
        return false;
    return true;
}
void solve(){
    int m,n;
    cin>>m>>n;
    int total = m*n;
    int ans = 0;
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            int temp = total-1;
            if(isValid(m,n,x-2,y-1)){
                temp--;
            }
            if(isValid(m,n,x-2,y+1)){
                temp--;
            }
            if(isValid(m,n,x-1,y-2)){
                temp--;
            }
            if(isValid(m,n,x+1,y-2)){
                temp--;
            }
            if(isValid(m,n,x+2,y-1)){
                temp--;
            }
            if(isValid(m,n,x+2,y+1)){
                temp--;
            }
            if(isValid(m,n,x-1,y+2)){
                temp--;
            }
            if(isValid(m,n,x+1,y+2)){
                temp--;
            }
            ans += temp;
        }
    }
    cout<<ans<<endl;
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
