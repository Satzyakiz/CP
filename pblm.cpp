
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool check(vector<vector<int>> mat,int x,int i,int j){
    if(i < 0 || j < 0 || i >= mat.size() || j >= mat[i].size() || mat[i][j] != x)
        return false;
    return true;
}
bool checkAll(vector<vector<int>> mat, int i, int j){
    int x = mat[i][j];
    return  check(mat,x,i-1,j-1) || check(mat,x,i-1,j) || check(mat,x,i-1,j+1) ||
            check(mat,x,i,j-1) || check(mat,x,i,j+1) ||
            check(mat,x,i+1,j-1) || check(mat,x,i+1,j) ||check(mat,x,i+1,j+1);
}
void solve(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> mat(m,vector<int>(n));
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];
    set<int> s;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
                // cout<<mat[i][j]<<" ";
                if(mat[i][j] != -1 && !s.count(mat[i][j])){
                    if(checkAll(mat,i,j)){
                        s.insert(mat[i][j]);
                    }
                }
        }
        // cout<<endl;
    }
    // cout<<endl;
    cout<<s.size()<<endl;
    // cout<<"==============\n";
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
