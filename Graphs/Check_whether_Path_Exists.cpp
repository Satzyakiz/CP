// Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether
// there is a path possible from source to destination, while traversing through
// blank cells only. You can traverse up, down, right and left.
//
// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Blank Wall.
// Note: there is only single source and single destination.

// Input:
// 2
// 4
// 3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3
// 3
// 0 3 2 3 0 0 1 0 0
//
// Output:
// 1
// 0

#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> &mat,int i,int j,int eX,int eY){
    if(i < 0 || j < 0 || i>= mat.size() || j >= mat.size() || mat[i][j] == 0 )
        return false;
    if(i == eX && j == eY)
        return true;
    mat[i][j] = 0;
    bool top = check(mat,i-1,j,eX,eY);
    bool down = check(mat,i+1,j,eX,eY);
    bool left = check(mat,i,j-1,eX,eY);
    bool right = check(mat,i,j+1,eX,eY);

    return top || down || left || right;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    int sX,sY, eX, eY;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
            if(mat[i][j] == 1){
                sX = i, sY = j;
            }
            if(mat[i][j] == 2){
                eX = i, eY = j;
            }
        }
    }
    bool val = check(mat,sX,sY,eX,eY);
    if(val)
        cout<<"1\n";
    else
        cout<<"0\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
